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

START_TEST(can_subtract_by_prefixing)
{
	verify_subtraction("V", "I", "IV");
	verify_subtraction("X", "I", "IX");
	verify_subtraction("L", "X", "XL");
	verify_subtraction("C", "X", "XC");
	verify_subtraction("D", "C", "CD");
	verify_subtraction("M", "C", "CM");
}
END_TEST

START_TEST(can_subtract_when_result_isnt_directly_composed_of_inputs)
{
	verify_subtraction("C", "XXX", "LXX");
	verify_subtraction("X", "V", "V");
	verify_subtraction("MCX", "DLV", "DLV");
	verify_subtraction("M", "IV", "CMXCVI");
	verify_subtraction("MDXXIV", "CXLIV", "MCCCLXXX");
}
END_TEST

START_TEST(reports_underflow_errors_below_roman_range)
{
	verify_subtraction("I", "I", "underflow error");
	verify_subtraction("XIV", "MMCL", "underflow error");
}
END_TEST

START_TEST(reports_errors_from_invalid_input)
{
	verify_subtraction("huh", "I", "invalid input");
	verify_subtraction("MCI", "&0AB", "invalid input");
	verify_subtraction("DDD", "IV", "invalid input");
	verify_subtraction("M", "IVMCXL", "invalid input");
}
END_TEST


TCase *subtraction_tests(void)
{
	TCase *test_case = tcase_create("subtraction tests");	
	tcase_add_test(test_case, can_subtract_by_removing_letters);
	tcase_add_test(test_case, can_subtract_by_prefixing);
	tcase_add_test(test_case, can_subtract_when_result_isnt_directly_composed_of_inputs);
	tcase_add_test(test_case, reports_underflow_errors_below_roman_range);
	tcase_add_test(test_case, reports_errors_from_invalid_input);
	return test_case;
}
