#include "mbed.h"
#include "NHD_0216HZ.h"
#include "pindef.h"

DigitalOut boardled(LED1);
 
Mutex mutex; 
Thread thread1;
Thread thread2;
Thread thread3;
Thread thread4;
NHD_0216HZ lcd( SPI_CS, SPI_MOSI, SPI_SCLK);

void tempThread() {
    I2C temp_sensor(I2C_SDA, I2C_SCL);
    const int temp_addr = 0x90;
    char cmd[] = {0x51, 0xAA};
    char read_temp[2];
    
    while (true) 
    {
        //Write the Start Convert T command to the sensor
        mutex.lock();
        lcd.clr_lcd();
        
        lcd.set_cursor(0,0);  //Set the cursor position
        lcd.printf("Temperature:");
    
        temp_sensor.write(temp_addr, cmd, 1);
        
        //Write the Read Temperature command to the sensor        
        temp_sensor.write(temp_addr, &cmd[1], 1);
        temp_sensor.read(temp_addr, read_temp, 2);
        
        //Convert temperature to Celsius
        float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);

        lcd.set_cursor(0,1);//Set cursor position
        lcd.printf(" %f ",temp);
        
        wait(2);
        
        mutex.unlock();
    }
}
 
void brightnessThread() {
    AnalogIn potent(PA_0);    // Define analog input potentiometer
    PwmOut redled(PB_3);

    while (true) 
    {
        // Use potentiometer to adjust LED brightness
        redled = potent.read();
    }
}

void incrementThread() {   
    
    while (true) 
    {
        for(float i=0; i<100; i++)
        {
        mutex.lock();
        lcd.clr_lcd();
        lcd.set_cursor(0,0);//Set the cursor position
        lcd.printf("Increment:");
            
        lcd.set_cursor(0,1);//Set cursor position
        
        // print to lcd
        lcd.printf(" %f ", i);
        wait(2);
        mutex.unlock();
        
        }
    }
}

void blinkThread() {
    while (true) 
    {
        boardled = !boardled;
        wait(1);
    }
} 
int main() {
    lcd.init_lcd(); //Initialise the LCD
    lcd.clr_lcd();
    
    thread1.start(tempThread);
    thread2.start(brightnessThread);
    thread3.start(incrementThread);
    thread4.start(blinkThread);
    
    //sleep();  // sleep waiting for interrupts
}