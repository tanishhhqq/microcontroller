#include <8051.h>

// Function to convert binary to BCD
unsigned char binaryToBCD(unsigned char binary) {
    unsigned char tens, units;

    tens = binary / 10;     // Get tens place digit
    units = binary % 10;    // Get units place digit

    return (tens << 4) | units;  // Combine tens and units into BCD format
}

void main() {
    unsigned char binaryNum = 25;  // Example binary number

    unsigned char bcdNum = binaryToBCD(binaryNum);  // Convert to BCD

    // Now you can use bcdNum for further processing or output

    // For example, outputting to P1 port (assuming 8051 has 8-bit ports)
    P1 = bcdNum;

    while(1) {
        // Your main program loop
    }
}
