#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_calculator.h"
#include "roman_convert_to_int.h"
#include "roman_convert_from_int.h"

char *roman_calculator_add(const char *left, const char *right)
{
	int left_value = roman_convert_to_int(left);
	int right_value = roman_convert_to_int(right);

	int sum = left_value + right_value;
	
	char *result = roman_convert_from_int(sum);
	return result;
}
