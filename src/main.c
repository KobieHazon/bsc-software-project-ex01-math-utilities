#include <stdio.h>
#include "MathIsFun.h"

int main() {
    int choice = 0; // save the user choice
    int val, x, n, d;
    int checkPrime = 0; //match to the arguments of funPrimeCheck function
    int checkPalindrome; //match to the arguments of funPalindromeCheck function

    printf("Welcome to Math Is Fun - beta version\n"
                   "Supported operations are:\n"
                   "1 - Power Calculation\n"
                   "2 - Prime Check\n"
                   "3 - Palindrome Check\n"
                   "Please enter operation number (1/2/3): \n");

    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Please enter three space separated numbers: \n");
            scanf("%d%d%d", &x, &n, &d);
            val = funPow(x, n, d);
            printf("res = %d\n", val);
            break;
        case 2:
            printf("Please enter an integer: \n");
            scanf("%d", &checkPrime);
            val = funPrimeCheck(checkPrime);
            if (val) printf("res = true\n");
            else printf("res = false\n");
            break;
        case 3:
            printf("Please enter an integer:\n");
            scanf("%d", &checkPalindrome);
            val = funPalindromeCheck(checkPalindrome);
            if (val) printf("res = true\n");
            else printf("res = false\n");
            break;
        default:
            break;
    }
    return (0);

}