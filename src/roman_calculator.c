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
	char *result = strdup(minuend);
	const char *remaining_subtrahend = subtrahend;
	for (const char *letter = subtrahend; *letter; letter++)
	{
		char *match;
		if((match = strchr(result, *letter)))
		{
			memmove(match, match + 1, 1 + strlen(match  + 1));
			remaining_subtrahend += 1;
		}
	}
	if (strlen(remaining_subtrahend) == 0)
		return result;

	free(result);
	result = calloc(sizeof(char), 16);
	strcat(result, subtrahend);
	strcat(result, minuend);

	return result;
}

static char *strdup(const char *source)
{
	char *result = malloc(strlen(source) + 1);
	strcpy(result, source);
	return result;
}
