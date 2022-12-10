#include <stdio.h>

void hex(const int number) {
    if (number < 0) {
        printf("-0x%x (%i)", -number, number);
    } else {
        printf("0x%x (%i)", number, number);
    }
}