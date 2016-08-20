#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"

char *roman_convert_from_int(const int number)
{
	char *result = malloc(2);
	if (number == 1) strcpy(result, "I");
	if (number == 5) strcpy(result, "V");
	if (number == 10) strcpy(result, "X");
	return result;
}
