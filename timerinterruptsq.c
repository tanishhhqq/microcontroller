#include <p18f458.h>

// Configuration Bits
#pragma config OSC=HS
#pragma config PWRT=OFF
#pragma config WDT=OFF
#pragma config DEBUG=ON, LVP=OFF

// Function Prototypes
void interrupt ISR(void);

// Global Variables
bit mybit = 0; // Define and initialize mybit

void main (void) {
    TRISBbits.TRISB4 = 0; // Set RB4 as output
    
    // Configure Timer0
    T0CON = 0x08; // Prescaler 1:128
    TMR0H = 0xFF; // Initialize Timer0 high byte
    TMR0L = 0xF0; // Initialize Timer0 low byte
    
    // Clear Timer0 Overflow Flag
    INTCONbits.TMR0IF = 0;
    
    // Enable Timer0 Overflow Interrupt
    INTCONbits.TMR0IE = 1;
    
    // Enable Peripheral and Global Interrupts
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    
    while (1) {
        // Main program loop
    }
}

// Timer0 Overflow Interrupt Service Routine
#pragma interrupt ISR
void ISR(void) {
    mybit = !mybit; // Toggle mybit
    INTCONbits.TMR0IF = 0; // Clear Timer0 Overflow Flag
    T0CONbits.TMR0ON = 1; // Restart Timer0
}
