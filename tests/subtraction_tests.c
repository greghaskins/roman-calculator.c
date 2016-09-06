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
	verify_subtraction("III", "I", "II");
	verify_subtraction("XXX", "XX", "X");
	verify_subtraction("XLV", "V", "XL");
	verify_subtraction("MDIV", "D", "MIV");
	verify_subtraction("MMLXI", "MI", "MLX");
	verify_subtraction("MMDCCLXXVII", "DLV", "MMCCXXII");
}
END_TEST

TCase *subtraction_tests(void)
{
	TCase *test_case = tcase_create("subtraction tests");	
	tcase_add_test(test_case, can_subtract_by_removing_letters);
	return test_case;
}
