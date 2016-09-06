#include <stdlib.h>
#include <string.h>

#include "roman_calculator.h"
#include "roman_convert_to_int.h"
#include "roman_convert_from_int.h"

static const int ERROR = -1;

static char *strdup(const char *source);

char *roman_calculator_add(const char *left, const char *right)
{
	int left_value = roman_convert_to_int(left);
	int right_value = roman_convert_to_int(right);

	if (left_value == ERROR || right_value == ERROR)
		return strdup("invalid input");

	int sum = left_value + right_value;

	char *result = roman_convert_from_int(sum);
	return result;
}

char *roman_calculator_subtract(const char *minuend, const char *subtrahend)
{
	int minuend_value = roman_convert_to_int(minuend);
	int subtrahend_value = roman_convert_to_int(subtrahend);

	int difference = minuend_value - subtrahend_value;

	char *result = roman_convert_from_int(difference);
	return result;
}

static char *strdup(const char *source)
{
	char *result = malloc(strlen(source) + 1);
	strcpy(result, source);
	return result;
}
