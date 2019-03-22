/*----------------------------------------------------------------------------
LAB EXERCISE 8.2 - INTERRUPT IN/OUT
PROGRAMMING USING MBED API
 ----------------------------------------
 In this exercise you need to use the mbed API functions to:
 
    1) Define InterruptIn and ISR for the button press
    2) In the interrupt service routine, the LED is used to indicate when a
    button was pressed:
            + USER_BUTTON - LED1

    3) Put the processor into sleep mode upon exiting from the ISR
            
    GOOD LUCK!
 *----------------------------------------------------------------------------*/
 
 #include "mbed.h"
 
DigitalOut boardled(LED1);
DigitalOut redled(PA_9);    // D8
InterruptIn button1(PA_10);   // D2
InterruptIn button2(PB_3);    // D3
InterruptIn button3(PB_5);    // D4
InterruptIn button4(PB_4);    // D5
Serial pc(SERIAL_TX, SERIAL_RX);

/*----------------------------------------------------------------------------
 MAIN function
 *----------------------------------------------------------------------------*/

void pressed()
{
    if(button1 == 0)    // button1 pressed
        boardled = 1;
    if(button3 == 0)    // button3 pressed
        redled = 1;
}

void released()
{
    if(button2 == 0)    // button2 pressed
        boardled = 0;
    if(button4 == 0)    // button4 pressed
        redled = 0;}

int main()
{
    // Assign functions to buttons
    button1.fall(&pressed);
    button2.fall(&released);
    button3.fall(&pressed);
    button4.fall(&released);   
             
    while (1) 
    {
        sleep();  // sleep waiting for interrupts
    }
}                 
