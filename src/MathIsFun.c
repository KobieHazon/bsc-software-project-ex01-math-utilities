#include "MathIsFun.h"

/*
 * Calculates the largest integer less or equal than the square root of x.
 * funSqrt(10) = 3
 * funSqrt(16) = 4
 * @param x - An integer for which the function applies
 * @return the value of |_sqrt(x)_|, if x is negative then the function
 * returns -1.
 */
int funSqrt(int x); // ==> Declaration is always in the beginning of the file.

/*
 * Calculates a % d (for negative numbers as well).
 * @param a - An integer for which the function applies
 * @param d - An integer for modulu
 * @return the value of x%d if x is positive and (x+d) % d if x is negative.
 */
int funModulu(int a, int d);


int funModulu(int a, int d) {
    int temp = a;
    while (temp < 0) {
        temp += d;
    }
    return temp % d;
}

int funPow(int x, int n, int d) {
    int result;
    if (n == 0) return 1;
    if (n == 1) return funModulu(x, d);
    if ((n % 2) == 0) {
        result = funPow(x, n / 2, d);
        return funModulu(result * result, d);
    }
    else {
        result = funPow(x, (n - 1) / 2, d);
        return funModulu(result * x * result, d);
    }
}

int funSqrt(int x) {
    int low = 1;
    int high = x / 2;
    int middle = (high + low) / 2;

    if (x < 0) return -1;
    while ((x < middle*middle) || (((middle+1)*(middle+1) <= x))){
        if (x < middle*middle)
            high = middle - 1;
        else
            low = middle + 1;
        middle = (high + low) / 2;
    }
    return middle;
}

bool funPrimeCheck(int x) {
    int sqrtX = funSqrt(x);
    int i = 2;

    if (x == 1) return false;
    for (i; i <= sqrtX; i++){
        if (funModulu(x, i) == 0)
            return false;
    }
    return true;
}

bool funPalindromeCheck(int x) {
    int temp, reverse = 0;

    if (x < 0) return false; //negative numbers are not palindromes
    temp = x;

    while (temp != 0) {
        reverse *= 10;
        reverse += temp % 10;
        temp /= 10;
    }
    if (reverse == x) return true;
    return false;
}