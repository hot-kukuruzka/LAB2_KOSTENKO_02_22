#include <stdio.h>

void oct(const int number) {
    if (number < 0) {
        printf("-0%o (%i)", -number, number);
    } else {
        printf("0%o (%i)", number, number);
    }
}