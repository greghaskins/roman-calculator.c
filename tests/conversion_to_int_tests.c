#include <check.h>

#include "../src/roman_convert_to_int.h"

START_TEST(can_convert_single_numerals)
{
	ck_assert_int_eq(roman_convert_to_int("I"), 1);
}
END_TEST

TCase *conversion_to_int_tests()
{
	TCase *test_case = tcase_create("conversion to int");
	tcase_add_test(test_case, can_convert_single_numerals);
	return test_case;
}
