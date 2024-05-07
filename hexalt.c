#include <stdio.h>

int main() {
    int i, j, k; 

    while (1) {
        for (i = 0; i < 16; i++) {
            // Nested loops for delaying execution
            for (j = 0; j < 1000; j++) {
                for (k = 0; k < 1000; k++) {
                    // This loop doesn't do anything but delay execution
                }
            }
        }
    }

    return 0;
}
