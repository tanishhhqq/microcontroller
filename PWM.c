#include <p18f4520.h>

#pragma config OSC = HS
#pragma config PWRT = OFF
#pragma config WDT = OFF
#pragma config DEBUG = OFF, LVP = OFF

void main(void)
{
    TRISC = 0x00;    // Set all pins of Port C as outputs
    
    PR2 = 249;       // Set Timer 2 period
    CCPR1 = 186;     // Set duty cycle to approximately 75%
    T2CON = 0x01;    // Configure Timer 2 with prescaler of 1
    CCP1CON = 0x1C;  // Configure CCP1 module for PWM mode
    
    TMR2 = 0x00;     // Clear Timer 2 register
    T2CONbits.TMR2ON = 1;  // Start Timer 2
    
    while (1)
    {
        PIR1bits.TMR2IF = 0;  // Clear Timer 2 overflow flag
        while (PIR1bits.TMR2IF == 0);  // Wait for Timer 2 overflow
    }
}
