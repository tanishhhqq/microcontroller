#include <reg51.h>

// Lookup table for sine wave values (8-bit resolution)
const unsigned char sine_table[32] = {128, 159, 187, 212, 233, 248, 255, 255, 248, 233, 212, 187, 159, 128, 97, 69, 44, 23, 8, 1, 1, 8, 23, 44, 69, 97, 128, 159, 187, 212, 233, 248};

void main() {
    unsigned char i = 0;

    // Initialize PWM
    TMOD |= 0x01;   // Timer 0, Mode 1 (16-bit timer)
    TH0 = 0x00;     // Initialize Timer 0 high byte
    TL0 = 0x00;     // Initialize Timer 0 low byte
    TR0 = 1;        // Start Timer 0
    ET0 = 0;        // Disable Timer 0 interrupts

    while (1) {
        // Output sine wave value to DAC
        P1 = sine_table[i];
        
        // Increment index for next sine wave value
        i = (i + 1) % 32;

        // Delay for PWM period
        // Adjust this delay according to your desired frequency
        for (unsigned int j = 0; j < 1000; j++);
    }
}
