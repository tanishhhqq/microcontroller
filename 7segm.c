#include <8051.h>

#define SEG_PORT P1

// Function prototypes
void delay(unsigned int);

void main() {
    unsigned char segCode[] = {
        0xC0, // 0
        0xF9, // 1
        0xA4, // 2
        0xB0, // 3
        0x99, // 4
        0x92, // 5
        0x82, // 6
        0xF8, // 7
        0x80, // 8
        0x90  // 9
    };

    while (1) {
        unsigned int i;

        for (i = 0; i < 10; i++) {
            SEG_PORT = segCode[i];
            delay(500); // Delay for 500 milliseconds
        }
    }
}

// Delay function
void delay(unsigned int count) {
    unsigned int i, j;
    for (i = 0; i < count; i++)
        for (j = 0; j < 1000; j++); // Adjust this loop for proper delay timing
}
