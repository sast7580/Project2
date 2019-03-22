/*----------------------------------------------------------------------------
LAB EXERCISE 8.1 - DIGITAL INPUTS AND OUTPUTS
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
    1) Define BusIn, BusOut interfaces for inputs and outputs
    2) The LED is controlled by the button:
            + USER_BUTTON - LED1
            
    GOOD LUCK!
 *----------------------------------------------------------------------------*/
 
 #include "mbed.h"
 
DigitalOut boardled(LED1);
DigitalOut redled(PA_9);    // D8
DigitalIn button1(PA_10);   // D2
DigitalIn button2(PB_3);    // D3
DigitalIn button3(PB_5);    // D4
DigitalIn button4(PB_4);    // D5
//Serial pc(SERIAL_TX, SERIAL_RX);

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

int main()
{
    boardled = 0;
    redled = 0;
    
    while (1) 
    {
        if(button1 == 0)  // button1 pressed
        {
            boardled = 1;
//            pc.printf("\rbutton 1 pressed... board light on\n");
//            wait(2000);
        }
        else if(button2 == 0)  // button2 pressed
        {
            boardled = 0;
//           pc.printf("\rbutton 2 pressed... board light off\n");
//            wait(2000);
        }
        else if(button3 == 0)  // button3 pressed
        {
            redled = 1;
//            pc.printf("\rbutton 3 pressed... red light on\n");
//            wait(2000);
        }
        else if(button4 == 0)  // button4 pressed
        {
            redled = 0;  
//            pc.printf("\rbutton 4 pressed... red light off\n");
//            wait(2000);            
        } 
    }
}                 
