#include <stdlib.h>
#include <check.h>

#include "../src/roman_calculator.h"

void verify_addition(const char *left, const char *right, const char *expected_result) {
	char *actual_result = roman_calculator_add(left, right);
	ck_assert_msg(
			strcmp(expected_result, actual_result) == 0,
			"%s + %s: expected %s, but was %s",
			left, right, expected_result, actual_result);	       
	free(actual_result);
}

START_TEST(can_add_by_simple_repetition)
{
	verify_addition("I", "I", "II");
	verify_addition("I", "II", "III");
	verify_addition("XX", "X", "XXX");
	verify_addition("C", "C", "CC");
	verify_addition("M", "MM", "MMM");
}
END_TEST

START_TEST(can_add_by_concatenation)
{
	verify_addition("X", "I", "XI");
	verify_addition("MCX", "XV", "MCXXV");
	verify_addition("DCI", "II", "DCIII");
	verify_addition("LX", "XVI", "LXXVI");
}
END_TEST


START_TEST(addition_is_commutative)
{
	verify_addition("X", "I", "XI");
	verify_addition("I", "X", "XI");

	verify_addition("VII", "X", "XVII");
	verify_addition("X", "VII", "XVII");
}
END_TEST

START_TEST(adding_smaller_numerals_consolidates_into_larger_numeral)
{
	verify_addition("XXX", "XX", "L");
	verify_addition("D", "D", "M");
	verify_addition("XXXII", "XXV", "LVII");
}
END_TEST

START_TEST(uses_shorthand_subtractive_form)
{
	verify_addition("IV", "I", "V");
	verify_addition("XXXI", "IX", "XL");
	verify_addition("MCMVIII", "CXLI", "MMXLIX");
}
END_TEST

START_TEST(reports_errors_from_invalid_input)
{
	verify_addition("wat", "I", "invalid input");
	verify_addition("XVI", "$%7", "invalid input");
	verify_addition("CDCDDIVIX", "L", "invalid input");
}
END_TEST


TCase *addition_tests()
{
	TCase *test_case = tcase_create("addition tests");
	tcase_add_test(test_case, can_add_by_simple_repetition);
	tcase_add_test(test_case, can_add_by_concatenation);
	tcase_add_test(test_case, addition_is_commutative);
	tcase_add_test(test_case, adding_smaller_numerals_consolidates_into_larger_numeral);
	tcase_add_test(test_case, reports_errors_from_invalid_input);
	tcase_add_test(test_case, uses_shorthand_subtractive_form);
	return test_case;
}
