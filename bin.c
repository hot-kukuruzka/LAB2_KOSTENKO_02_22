#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bin(const int number) {
    int num = (number < 0) ? -number : number; 
    char num_b[8];
    for (int i = 0; i < 8; i++) {
        num_b[i] = (num & 0x80) ? '1' : '0';
        num <<= 1;
    }
    while (num_b[0] == '0' && strlen(num_b) > 1) {
        memmove(&num_b[0], &num_b[1], strlen(num_b));
    }
    if (number < 0) {
        printf("-%s (%i)", num_b, number);
    } else {
        printf("%s (%i)", num_b, number);
    }
}