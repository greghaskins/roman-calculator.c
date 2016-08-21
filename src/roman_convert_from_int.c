#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"

typedef struct RomanLetters {
	int value;
	char letters[3];
} RomanLetters;

static const RomanLetters ROMAN_LETTERS[] = {
	{ 1000, "M" },
	{ 500, "D" },
	{ 100, "C" },
	{ 50, "L" },
	{ 10, "X" },
	{ 5, "V" },
	{ 1, "I" }
};
static const int ROMAN_LETTERS_LENGTH = sizeof(ROMAN_LETTERS) / sizeof(RomanLetters);


char *roman_convert_from_int(const int number)
{
	char *result = calloc(2, sizeof(char));
	if (number < 1) return strcat(result, "underflow error");
	if (3999 < number) return strcat(result, "overflow error");

	int remainder = number;
	for (int i = 0; i < ROMAN_LETTERS_LENGTH; i++)
	{
		const RomanLetters entry = ROMAN_LETTERS[i];
		while (remainder >= entry.value)
		{
			strcat(result, entry.letters);
			remainder -= entry.value;
		}
	}
	return result;
}
