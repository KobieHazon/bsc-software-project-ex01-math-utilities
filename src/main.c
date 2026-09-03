#include <stdio.h>

#include "MathIsFun.h"

static void print_intro(void) {
    printf("Welcome to Math Is Fun - beta version\n"
           "Supported operations are:\n"
           "1 - Power Calculation\n"
           "2 - Prime Check\n"
           "3 - Palindrome Check\n"
           "Please enter operation number (1/2/3): \n");
}

static void print_bool_result(bool value) {
    if (value) {
        printf("res = true\n");
    } else {
        printf("res = false\n");
    }
}

int main(void) {
    int choice = 0;
    int x = 0;
    int n = 0;
    int d = 0;
    int value = 0;

    print_intro();
    if (scanf("%d", &choice) != 1) {
        return 1;
    }

    switch (choice) {
        case 1:
            printf("Please enter three space separated numbers: \n");
            if (scanf("%d%d%d", &x, &n, &d) != 3) {
                return 1;
            }
            printf("res = %d\n", funPow(x, n, d));
            break;
        case 2:
            printf("Please enter an integer: \n");
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            print_bool_result(funPrimeCheck(value));
            break;
        case 3:
            printf("Please enter an integer: \n");
            if (scanf("%d", &value) != 1) {
                return 1;
            }
            print_bool_result(funPalindromeCheck(value));
            break;
        default:
            break;
    }
    return 0;
}
