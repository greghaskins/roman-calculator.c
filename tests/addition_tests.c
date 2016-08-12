#include <check.h>

#include "../src/roman_calculator.h"

START_TEST(can_add_by_simple_repetition)
{
	ck_assert_str_eq("II", roman_calculator_add("I", "I"));
	ck_assert_str_eq("III", roman_calculator_add("I", "II"));
	ck_assert_str_eq("XXX", roman_calculator_add("XX", "X"));
	ck_assert_str_eq("CC", roman_calculator_add("C", "C"));
	ck_assert_str_eq("MMM", roman_calculator_add("M", "MM"));
}
END_TEST

TCase *addition_tests()
{
	TCase *test_case = tcase_create("addition tests");
	tcase_add_test(test_case, can_add_by_simple_repetition);
	return test_case;
}
