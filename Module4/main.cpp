#include "mbed.h"

// Define inputs/outputs
Serial pc(SERIAL_TX, SERIAL_RX);
DigitalOut led(LED1);
Timer t;

//Define variables
float i;
int k = 0;
float sample = 0;
float array[120];
float peaks[10];
float timeList[10];
float maximum = array[0];
float previous = array[0];
float periodTime = 0.0000249;  // 1004 Hz
float timepast = periodTime;
bool ascending = true;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    // generate sine wave
    for (i=0;i<6;i=i+0.05) {
        sample=0.5+0.5*sin(i*3.14159); // Compute the sine value,+ half the range
        array[k] = sample;
//      pc.printf("\rsample: %f\n", sample);
        k++;
        wait(periodTime);
    }
            
    while(1){ 
        t.start();
                   
        float frequency = 0;
        int j = 0;
        int l = 0;    
        int c = 1;

        // peak detection algorithm
        for(j=0; j<119; j++){
            if(array[j] < array[j+1]){
                ascending = true;
                maximum = array[j+1];
            }
            else if((array[j] > array[j+1]) && (ascending == true)){
                peaks[l] = maximum;
                timeList[l] = timepast;                
                ascending = false;
                pc.printf("\rpeak %d: %0.1f\n", c, peaks[l]);
                c++;                
                l++;
            } 
            timepast += periodTime;
        }           
    
    // determine/print frequncy and amplitude for each peak
    frequency = 1/(timeList[1] - timeList[0]);
    pc.printf("\n\rfrequency: %.1f\n", frequency);
    c = 1;
    for(j=0; j<l; j++){
        pc.printf("\ramplitude for peak %d: %.1f\n", c, (peaks[j]/2));
        c++;
    }

    // blink led at rate of frequency
    led = 1;
    wait(1/frequency);
    led = 0;
    wait(1/frequency);
    
    // calculate processor load
    t.stop();
    pc.printf("\n\rThe time taken was %f seconds\n\n", t.read());
    t.reset();
    
    wait(1);
    }
}