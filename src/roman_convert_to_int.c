#include <string.h>

#include "roman_convert_to_int.h"

static const int ERROR = -1;

static int letter_to_int(const char letter);

int roman_convert_to_int(const char *numeral)
{
	if (!numeral) return ERROR;

	const int length = strlen(numeral);
	int total = 0;
	for (int i = 0; i < length; i++)
	{
		char letter = numeral[i];
		int value = letter_to_int(letter);
		if (value == ERROR) return ERROR;
		total += letter_to_int(letter);
	}
	return total;
}

static int letter_to_int(const char letter)
{
	switch (letter)
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			return ERROR;
	}
}
