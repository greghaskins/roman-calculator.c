#include <stdlib.h>

#include "subtraction_tests.h"
#include "../src/roman_calculator.h"

static void verify_subtraction(const char *minuend, const char *subtrahend, const char *expected_result) {
	char *actual_result = roman_calculator_subtract(minuend, subtrahend);
	ck_assert_msg(
			strcmp(expected_result, actual_result) == 0,
			"%s - %s: expected %s, but was %s",
			minuend, subtrahend, expected_result, actual_result);	       
	free(actual_result);
}

START_TEST(can_subtract_by_removing_letters)
{
	verify_subtraction("II", "I", "I");
}
END_TEST

TCase *subtraction_tests(void)
{
	TCase *test_case = tcase_create("subtraction tests");	
	tcase_add_test(test_case, can_subtract_by_removing_letters);
	return test_case;
}
