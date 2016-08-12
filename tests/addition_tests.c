#include <check.h>

#include "../src/roman_calculator.h"

START_TEST(one_and_one_is_two)
{
	ck_assert_str_eq("II", roman_calculator_add("I", "I"));
}
END_TEST

TCase *addition_tests()
{
	TCase *test_case = tcase_create("addition tests");
	tcase_add_test(test_case, one_and_one_is_two);
	return test_case;
}
