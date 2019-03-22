#include "mbed.h"

DigitalOut myled(LED1);
Serial pc(SERIAL_TX, SERIAL_RX);

int main() {
    int i = 1;
    pc.printf("Hello World !\n");
    pc.printf("\rRTC example\n"); 
    set_time(1552160629); // Set RTC time to Saturday, 09-Mar-19 time... UTC

    while(1) {

        time_t seconds = time(NULL);

        //printf("Time as seconds since January 1, 1970 = %d\n", seconds);
        
        printf("\rTime as a basic string = %s", ctime(&seconds));

        //char buffer[32];
        //strftime(buffer, 32, "%I:%M:%S %p\n", localtime(&seconds));
        //printf("Time as a custom formatted string = %s", buffer);

        pc.printf("\r program running for %d seconds.\n", i++);

        myled = !myled;      
        wait(1);
    }
}