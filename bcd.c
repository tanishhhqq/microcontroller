#include <reg51.h>

void main() {
    unsigned int i; // Use unsigned int for loop variable

    while(1) {
        for(i = 0; i < 100; i++) {
            if(i < 10)
                P1 = i;
            else if(i < 20)
                P1 = i + 6;
            else if(i < 30)
                P1 = i + 12;
            else if(i < 40)
                P1 = i + 18;
            else if(i < 50)
                P1 = i + 24;
            else if(i < 60)
                P1 = i + 30;
            else if(i < 70)
                P1 = i + 36;
            else if(i < 80)
                P1 = i + 42;
            else if(i < 90)
                P1 = i + 48;
            else // i < 100, this else block is redundant
                P1 = i + 54;

            // Add delay here
            // You may adjust the delay based on your requirement
            delay();
        }
    }
}

void delay() {
    unsigned int j, k;
    for(j = 0; j < 5000; j++) {
        for(k = 0; k < 20; k++);
    }
}

