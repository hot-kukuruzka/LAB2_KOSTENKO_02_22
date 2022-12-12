#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

long int _strtol(const char *num, int radix) {
    int res = 0, x = 0;
    int n = (num[strlen(num) - 1] == '\n') ? strlen(num) - 1 : strlen(num);
    for (int i = 0; i < n; i++) {
        switch (num[i]) {
        case '0':
            x = 0;
            break;
        case '1':
            x = 1;
            break;
        case '2':
            x = 2;
            break;
        case '3':
            x = 3;
            break;
        case '4':
            x = 4;
            break;
        case '5':
            x = 5;
            break;
        case '6':
            x = 6;
            break;
        case '7':
            x = 7;
            break;
        case '8':
            x = 8;
            break;
        case '9':
            x = 9;
            break;
        case 'a':
            x = 10;
            break;
        case 'b':
            x = 11;
            break;
        case 'c':
            x = 12;
            break;
        case 'd':
            x = 13;
            break;
        case 'e':
            x = 14;
            break;
        case 'f':
            x = 15;
            break;
        }
        res = res * radix + x;
    }
    return res;
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