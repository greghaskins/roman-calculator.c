# roman-calculator.c
Code exercise in C: doing math with Roman numerals

[![Build Status](https://travis-ci.org/greghaskins/roman-calculator.c.svg?branch=master)](https://travis-ci.org/greghaskins/roman-calculator.c) [![codecov](https://codecov.io/gh/greghaskins/roman-calculator.c/branch/master/graph/badge.svg)](https://codecov.io/gh/greghaskins/roman-calculator.c)

## Build Environment

- Ubuntu 14.04
- GCC 4.8.4
- GNU Make 3.81
- Check 0.9.10
- Valgrind 3.10.1

Or, use this one-liner on your Ubuntu 14.04 box:

```sh
sudo apt-get install build-essential check valgrind
```

Then you can run the build and tests with:

```sh
make
```

## API and Examples

The `roman_calculator` library provides a way to add roman numerals together. Input and output are given as `char *` null-terminated strings. The rules for roman numerals are as described [here](http://codingdojo.org/cgi-bin/index.pl?KataRomanCalculator)

```c
#include "roman_calculator.h"

char *sum1 = roman_calculator_add("I", "I"); // -> "II"
char *sum2 = roman_calculator_add("XXXI", "MXXVI"); // -> "MLVII"
```

See [tests/addition_tests.c]() for more detailed examples.

## TODO

- [x] Addition happy cases
- [x] Handle null input
- [x] Handle underflow and overflow errors (beyond 3999)
- [x] Error on bogus characters
- [x] Subtractive/compressed format input/output (IV, XL, CD, etc.)
- [ ] Deal with malformed numerals (e.g. `DDD`, `CMCM`, `LLIIII`, `IXIV`)
- [ ] Subtraction feature (`roman_calculator_subtract`)
