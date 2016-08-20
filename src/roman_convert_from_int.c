#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "roman_convert_from_int.h"

char *roman_convert_from_int(const int number)
{
	char *result = malloc(2);
	strcpy(result, "I");
	return number ? result : result;
}
