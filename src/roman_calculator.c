#include "roman_calculator.h"

char *roman_calculator_add(const char *left, const char *right)
{
	char result[strlen(left) + strlen(right)];
	sprintf(result, "%s%s", left, right);
	return result;
}
