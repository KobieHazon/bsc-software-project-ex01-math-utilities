#include <stdbool.h>
#include <stdio.h>

#include "MathIsFun.h"

static int failures = 0;

static void expect_int(const char *name, int actual, int expected) {
    if (actual != expected) {
        printf("%s: expected %d, got %d\n", name, expected, actual);
        failures++;
    }
}

static void expect_bool(const char *name, bool actual, bool expected) {
    if (actual != expected) {
        printf("%s: expected %s, got %s\n",
               name,
               expected ? "true" : "false",
               actual ? "true" : "false");
        failures++;
    }
}

int main(void) {
    expect_int("positive modular power", funPow(5, 2, 20), 5);
    expect_int("negative modular power", funPow(-3, 3, 5), 3);
    expect_int("zero exponent", funPow(0, 0, 5), 1);
    expect_int("fast exponentiation", funPow(2, 10, 17), 4);

    expect_bool("two is prime", funPrimeCheck(2), true);
    expect_bool("three is prime", funPrimeCheck(3), true);
    expect_bool("nine is composite", funPrimeCheck(9), false);
    expect_bool("one is not prime", funPrimeCheck(1), false);
    expect_bool("zero is not prime", funPrimeCheck(0), false);
    expect_bool("negative is not prime", funPrimeCheck(-7), false);

    expect_bool("palindrome", funPalindromeCheck(12121), true);
    expect_bool("non-palindrome", funPalindromeCheck(112233), false);
    expect_bool("zero palindrome", funPalindromeCheck(0), true);
    expect_bool("negative palindrome", funPalindromeCheck(-121), false);

    return failures == 0 ? 0 : 1;
}
