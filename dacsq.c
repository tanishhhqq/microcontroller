#include <reg51.h>

sbit wave = P1^0;

void delay();

void main() {
    wave = 0; // Initialize wave to 0

    while (1) {
        wave = 1; // Set wave high
        delay();
        wave = 0; // Set wave low
        delay();
    }
}

void delay() {
    unsigned char i;

    TMOD = 0x10; // Set Timer 1 in mode 1 (16-bit auto-reload)
    
    for (i = 0; i < 14; i++) { // Assuming you want a delay of 14 machine cycles
        TH1 = 0x00; // Load timer high byte with 0
        TL1 = 0x00; // Load timer low byte with 0
        TR1 = 1;    // Start Timer 1
        while (TF1 == 0); // Wait for Timer 1 overflow
        TF1 = 0;    // Clear Timer 1 overflow flag
    }
}
