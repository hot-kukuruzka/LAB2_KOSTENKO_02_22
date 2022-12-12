#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"
#include "common_funcs.h"

char signs[7] = "+-*%^|&";
char b_signs[3] = "^|&";

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
        } else if (number < 0) {
            printf("Ошибка: введите положительное число");
            return 0;
        }
        get_result(radix, ~number);
    } else {
        for (int i = 0; i < strlen(str) - 1; i++) {
            if (strchr(signs, str[i]) != NULL && i != 0) {
                char num1[i - 1];
                char num2[strlen(str) - i - 1];
                char sign = str[i];      
                int radix1, radix2;
                memmove(&num1[0], &str[0], i - 1);
                memmove(&num2[0], &str[i + 1], strlen(str) - i - 1);
                radix1 = def_of_radix(num1);
                radix2 = def_of_radix(num2);
                long int n1 = _strtol(num1, radix1);
                long int n2 = _strtol(num2, radix2);

                if (radix1 != radix2) {
                    printf("Ошибка: системы счисления не совпадают\n");
                    printf("%i %i", radix1, radix2);
                    return 0;
                } else if (radix1 == 0) {
                    printf("Ошибка: попробуйте ввести другое число");
                    return 0;
                } else if (strchr(b_signs, sign) != NULL && (n1 < 0 || n2 < 0)) {
                    printf("Ошибка: введите положительное число");
                    return 0;
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
            }
        }
    }
    free(str);
    return 0;
}