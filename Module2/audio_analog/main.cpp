/*----------------------------------------------------------------------------
LAB EXERCISE 9 - Analog input and PWM
 ----------------------------------------
    Use two potentiometers to adjust the volume and pitch of the output sound wave.
    
    Inputs: Virtual potentiometers 1 and 2
    Output: Virtual speaker,  Real PC

    GOOD LUCK!
 *----------------------------------------------------------------------------*/

#include "mbed.h"

PwmOut speaker(PB_10);   // Define the PWM speaker output to D6
AnalogIn poten1(PA_0);    // Define analog input potentiometer
AnalogIn poten2(PA_1);    // Define analog input potentiometer

// Define serial output
Serial pc(SERIAL_TX, SERIAL_RX);

//Write your code here


//Define variables
float i;
float output;
float p1;
float p2;

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main(){
    while(1){
        p1 = poten1.read();  
        p2 = poten2.read();  
      
      // generate sawtooth sound wave
        for (i=0; i<50; i++) {
            // Make the period and volume adjustable using the potentiometers
            speaker.period(p2/150.0); // 500hz period
            speaker = p1; //25% duty cycle - mid range volume
            wait(0.05);  
            }    

        // Print values of the potentiometers to the PC serial terminal
        pc.printf("\rpotentiometer 1: %f\n", p1);
        pc.printf("\rpotentiometer 2: %f\n", p2);        
    }
}