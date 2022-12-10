#include <stdio.h>
#include <stdlib.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"

extern char signs[7];

int def_of_radix(const char *str) {
    int radix = 0;
    char num[strlen(str)];
    strcpy(num, str);
    while (num[0] == ' ' || strchr(signs, num[0]) != NULL) {
        memmove(&num[0], &num[1], strlen(num));
    }
    if (num[0] == '0' && num[1] == 'x') {
        radix = 16;
    } else if (num[0] == '0') {
        radix = 8;
    } else {
        for (int i = 0; i < strlen(num); i++) {
            if (num[i] != '0' && num[i] != '1' && num[i] != '\n') {
                radix = 0;
                return radix;
            }
        }
        radix = 2;
    }
    return radix;
}

void get_result(const int radix, const long int result) {
    if (radix == 16) {
        hex(result);
    } else if (radix == 8) {
        oct(result);
    } else if (radix == 2) {
        bin(result);
    }
}