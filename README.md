# Software Project Ex01 - Math Utilities

A 2016 CS BSc C assignment implementing a small command-line calculator for modular exponentiation, primality testing, and numeric palindrome checks.

## Functionality

- Compute `x^n mod d` in logarithmic time, including negative bases.
- Check whether an integer is prime.
- Check whether an integer is a numeric palindrome.
- Provide the original interactive command-line flow and exact sample-output formatting.

## Build

```bash
make
```

This builds `build/ex1` with `-std=c99 -Wall -Wextra -Werror -pedantic-errors`.

## Usage

```bash
./build/ex1
```

The program prompts for one of three operations:

- `1`: modular power, then three integers: base, exponent, divisor
- `2`: primality check, then one integer
- `3`: palindrome check, then one integer

## Testing

```bash
make test
python3 tests/run_samples.py build/ex1
```

The tests include a C unit executable for edge cases and a Python sample runner that compares the program against the six supplied input/output fixtures.

## Repository Structure

- `assignment/SP_Assignment1.pdf`: supplied assignment handout preserved as recovered
- `assignment/makefile`: supplied original makefile preserved as recovered
- `assignment/partners-template.txt`: supplied blank partner metadata template
- `include/MathIsFun.h`: supplied public header
- `src/MathIsFun.c`: my implementation, maintained for current toolchains
- `src/main.c`: my command-line entry point, maintained for current toolchains
- `tests/fixtures/`: supplied sample input and expected-output files
- `tests/test_mathisfun.c`: maintained unit tests
- `tests/run_samples.py`: maintained sample-output regression runner
- `recovered/`: original recovered README and CMake file kept for provenance

## Implementation notes

The maintained version keeps the public CLI behavior, updates the implementation for current strict C compilers, fixes the sample-output spacing for palindrome prompts, adds a portable Makefile test path, and documents provenance.

The recovered source had two current-toolchain issues: `main()` had no explicit `void` parameter list under strict prototypes, and one loop used `for (i; ...)`, which current compilers reject with warnings-as-errors. It also returned true for negative prime inputs and could hang while checking whether `1` is prime; the maintained implementation fixes those edge cases while preserving the assignment's documented behavior.

## License

No repository-wide license is declared because the repository combines original work with supplied material whose reuse terms were not recorded.
