#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"

char *roman_convert_from_int(const int number)
{
	char *result = calloc(2, sizeof(char));
	if (number == 10) strcat(result, "X");
	if (number == 5) strcat(result, "V");
	if (number == 1) strcat(result, "I");
	return result;
}
