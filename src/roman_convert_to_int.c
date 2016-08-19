#include <string.h>

#include "roman_convert_to_int.h"

int roman_convert_to_int(const char *numeral)
{
	if (!numeral)
	{
		return -1;
	}
	const char first_letter = *numeral;
	switch (first_letter)
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
			return -1;
	}
}

