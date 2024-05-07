#include <p18f4520.h>

#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

void lcdcmd(unsigned char value); // Function Prototype declaration
void lcddata(unsigned char value);
void msdelay(unsigned int itime);

#define Idata PORTD // Declare idata variable for PORTD
#define rs PORTCbits.RC0 // Declare rs variable for pin RC0
#define rw PORTBbits.RB1 // Declare zw variable for pin RB1
#define en PORTCbits.RC2 // Declare en variable for pin RC2

void main() {
    TRISC = 0x00; // Set direction of PORTC as output
    TRISD = 0x00; // Set direction of PORTD as output

    msdelay(50);

    lcdcmd(0x38); // 16x2 LCD
    msdelay(50);

    lcdcmd(0x0E);
    msdelay(15);

    lcdcmd(0x01); // Clear Display screen
    msdelay(15);

    lcdcmd(0x06); // Increment cursor and shift right
    msdelay(15);

    lcdcmd(0x80); // Force cursor on first row first position
    lcddata('S');
    msdelay(50);
    lcddata('P'); // Display character "P"
    msdelay(50);
    lcddata('P');
    msdelay(50);
    lcddata('U');
    msdelay(50)
}

void msdelay(unsigned int itime) {
    unsigned int i, j;
    for (i = 0; i < itime; i++)
        for (j = 0; j < 165; j++); // 1ms delay
}

void lcdcmd(unsigned char value) {
    rs = 0; // Set RS low for command mode
    rw = 0; // Set RW low for write mode
    Idata = value; // Send command
    en = 1; // Enable pulse
    msdelay(10); // Delay
    en = 0; // Disable pulse
}

void lcddata(unsigned char value) {
    rs = 1; // Set RS high for data mode
    rw = 0; // Set RW low for write mode
    Idata = value; // Send data
    en = 1; // Enable pulse
    msdelay(10); // Delay
    en = 0; // Disable pulse
}
