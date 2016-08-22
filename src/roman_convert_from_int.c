#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"

static const int MAX_POSSIBLE_LENGTH_OF_NUMERAL = 16;

typedef struct RomanLetters {
	int value;
	char letters[3];
} RomanLetters;

static const RomanLetters ROMAN_LETTERS[] = {
	{ 1000, "M" },
	{ 900, "CM" },
	{ 500, "D" },
	{ 400, "CD" },
	{ 100, "C" },
	{ 90, "XC" },
	{ 50, "L" },
	{ 40, "XL" },
	{ 10, "X" },
	{ 9, "IX" },
	{ 5, "V" },
	{ 4, "IV" },
	{ 1, "I" }
};
static const int ROMAN_LETTERS_LENGTH = sizeof(ROMAN_LETTERS) / sizeof(RomanLetters);
static void build_result_from_component_letters(const int number, char *result);

static int append_letters_to_reduce_remainder(RomanLetters entry, int remainder, char *result);

char *roman_convert_from_int(const int number)
{
	char *result = calloc(MAX_POSSIBLE_LENGTH_OF_NUMERAL, sizeof(char));
	if (number < 1) return strcat(result, "underflow error");
	if (3999 < number) return strcat(result, "overflow error");

	build_result_from_component_letters(number, result);
	return result;
}

static void build_result_from_component_letters(const int number, char *result)
{
	int remainder = number;
	for (int i = 0; i < ROMAN_LETTERS_LENGTH; i++)
	{
		const RomanLetters entry = ROMAN_LETTERS[i];
		remainder = append_letters_to_reduce_remainder(entry, remainder, result);
	}
}

static int append_letters_to_reduce_remainder(RomanLetters entry, int remainder, char *result)
{
	while (remainder >= entry.value)
	{
		strcat(result, entry.letters);
		remainder -= entry.value;
	}
	return remainder;
}
