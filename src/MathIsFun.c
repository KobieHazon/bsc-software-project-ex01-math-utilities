#include "MathIsFun.h"

static int funModulu(int a, int d) {
    int remainder;

    if (d <= 0) {
        return 0;
    }

    remainder = a % d;
    if (remainder < 0) {
        remainder += d;
    }
    return remainder;
}

static int funSqrt(int x) {
    int low = 0;
    int high = x;
    int answer = 0;

    if (x < 0) {
        return -1;
    }

    while (low <= high) {
        int middle = low + (high - low) / 2;
        long long square = (long long)middle * middle;

        if (square <= x) {
            answer = middle;
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }
    return answer;
}

int funPow(int x, int n, int d) {
    long long base;
    long long result;

    if (n < 0 || d <= 0) {
        return 0;
    }

    base = funModulu(x, d);
    result = 1 % d;

    while (n > 0) {
        if (n % 2 != 0) {
            result = (result * base) % d;
        }
        base = (base * base) % d;
        n /= 2;
    }
    return (int)result;
}

bool funPrimeCheck(int x) {
    int limit;
    int divisor;

    if (x < 2) {
        return false;
    }

    limit = funSqrt(x);
    for (divisor = 2; divisor <= limit; divisor++) {
        if (funModulu(x, divisor) == 0) {
            return false;
        }
    }
    return true;
}

bool funPalindromeCheck(int x) {
    int original = x;
    long long reversed = 0;

    if (x < 0) {
        return false;
    }

    while (x != 0) {
        reversed *= 10;
        reversed += x % 10;
        x /= 10;
    }
    return reversed == original;
}
