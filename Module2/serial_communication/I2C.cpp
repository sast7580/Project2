/*----------------------------------------------------------------------------
LAB EXERCISE 11.3 - I2C interface
SERIAL COMMUNICATION
 ----------------------------------------
    Access the virtual temperature sensor via I2C interface, print the current temperature
    to the PC via UART
    
    Input: temperature sensor
    Output: PC
    
    GOOD LUCK!
 *----------------------------------------------------------------------------*/
#include "mbed.h"
#include "pindef.h"
#include "NHD_0216HZ.h"

NHD_0216HZ lcd( SPI_CS,  SPI_MOSI, SPI_SCLK);


//I2C interface
I2C temp_sensor(I2C_SDA, I2C_SCL);
Serial pc(UART_TX, UART_RX);

//I2C address of temperature sensor DS1631
const int temp_addr = 0x90;

char cmd[] = {0x51, 0xAA};
char read_temp[2];

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    pc.printf("\rHello mbed\n");
    lcd.init_lcd(); //Initialise the LCD
    lcd.set_cursor(0,0);//Set the cursor position
    lcd.printf("\rTemperature:");
    
    while(1){

        //Write the Start Convert T command to the sensor
        temp_sensor.write(temp_addr, cmd, 1);
        
        wait(0.5);
        
        //Write the Read Temperature command to the sensor        
        temp_sensor.write(temp_addr, &cmd[1], 1);
        temp_sensor.read(temp_addr, read_temp, 2);
        
        wait(0.5);
        
        //Convert temperature to Celsius
        float temp = (float((read_temp[0] << 8) | read_temp[1]) / 256);
        
        //Print temperature to the serial monitor
        pc.printf("\rtemperature: %f degree C\n", temp);

        lcd.set_cursor(0,1);//Set cursor position
        //Write your code here
        lcd.printf(" %f ",temp);
        
        
    }
}

// *******************************ARM University Program Copyright (c) ARM Ltd 2014*************************************
