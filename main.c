#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"
#include "common_funcs.h"

char signs[7] = "~+-*%^|&";
char b_signs[3] = "~^|&";

int main() {
    char *str = NULL;
    size_t n = 0;
    getline(&str, &n, stdin);

    if (str[0] == '~') {
        char num[strlen(str) - 2];
        memmove(&num[0], &str[1], strlen(str) - 2);
        int radix = def_of_radix(num);
        long int number = _strtol(num, radix);

        if (radix == 0) {
            printf("Ошибка: попробуйте ввести другое число");
            return 0;
        } else if (strchr(num, '-') != NULL) {
            printf("error");
            return 0;
        }
        get_result(radix, ~number);
    } else {
        for (int i = 0; i < strlen(str) - 1; i++) {
            if (strchr(signs, str[i]) != NULL && i != 0) {
                char num1[i - 1];
                char num2[strlen(str) - i - 1];
                char sign = str[i];      
                if (i == strlen(str) - 2) {
                    printf("error");
                    return 0;
                }
                int radix1, radix2;
                memmove(&num1[0], &str[0], i - 1);
                memmove(&num2[0], &str[i + 1], strlen(str) - i - 1);
                if (strchr(b_signs, sign) != NULL && (strchr(num1, '-') != NULL || strchr(num2, '-') != NULL)) {
                    printf("error");
                    return 0;
                }
                radix1 = def_of_radix(num1);
                radix2 = def_of_radix(num2);
                
                long int n1 = _strtol(num1, radix1);
                long int n2 = _strtol(num2, radix2);

                if (radix1 != radix2) {
                    printf("Ошибка: системы счисления не совпадают\n");
                    return 0;
                } else if (radix1 == 0) {
                    printf("Ошибка: попробуйте ввести другое число");
                    return 0;
                }
                if (radix1 == 2) {
                    for (; i < strlen(num1); i++) {
                        if (num1[i] >= '0' && num1[i] <= '1') {
                            continue;
                        } else {
                            printf("error");
                            return 0;
                        }
                    }
                    for (; i < strlen(num2); i++) {
                        if (num2[i] >= '0' && num2[i] <= '1') {
                            continue;
                        } else {
                            printf("error");
                            return 0;
                        }
                    }
                } else if (radix1 == 8) {
                    for (; i < strlen(num1); i++) {
                        if (num1[i] >= '0' && num1[i] <= '7') {
                            continue;
                        } else {
                            printf("error");
                            return 0;
                        }
                    }
                    for (; i < strlen(num2); i++) {
                        if (num2[i] >= '0' && num2[i] <= '7') {
                            continue;
                        } else {
                            printf("error");
                            return 0;
                        }
                    }
                } else if (radix == 16) {
                    for (; i < strlen(number); i++) {
                        if ((number[i] >= '0' && number[i] <= '9') ||
                            (number[i] >= 'A' && number[i] <= 'F') ||
                            (number[i] >= 'a' && number[i] <= 'f')
                                ) {
                            continue;
                        } else {
                            printf("error");
                            return 0;
                        }
                    }
                }

                long int res;
                switch (sign) {
                    case '+':
                        res = n1 + n2;
                        break;
                    case '-':
                        res = n1 - n2;
                        break;
                    case '*':
                        res = n1 * n2;
                        break;
                    case '%':
                        res = n1 % n2;
                        break;
                    case '^':
                        res = n1 ^ n2;
                        break;
                    case '|':
                        res = n1 | n2;
                        break;
                    case '&':
                        res = n1 & n2;
                        break;
                }          
                get_result(radix1, res);
                return 0;
            }
        }
        printf("error");
    }
    free(str);
    return 0;
}

