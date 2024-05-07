#include <xc.h> // Include the header file for PIC microcontroller

#pragma config OSC = HS // Set oscillator configuration
#pragma config PWRT = OFF // Disable Power-up Timer
#pragma config WDT = OFF // Disable Watchdog Timer
#pragma config DEBUG = OFF, LVP = OFF // Disable debugging and Low Voltage Programming

void main(void) {
    unsigned char text[] = "HELLO";
    unsigned int i = 0;

    TXSTA = 0x20; // Transmit Enable, Asynchronous Mode, High Speed
    SPBRG = 15; // Baud Rate Setting for 9600 at 20MHz
    TXSTAbits.TXEN = 1; // Enable Transmit
    RCSTAbits.SPEN = 1; // Enable Serial Port

    for (i = 0; i < 5; i++) {
        while (!PIR1bits.TXIF); // Wait until transmit buffer is empty
        TXREG = text[i]; // Transmit a character
    }

    while (1); // Infinite loop to prevent the program from exiting
}
