#include <stdio.h>

void oct(const int number) {
    if (number < 0) {
        printf("-%o (%i)", -number, number);
    } else {
        printf("%o (%i)", number, number);
    }
}