#include <check.h>

#include "../src/roman_convert_to_int.h"

START_TEST(can_convert_single_numerals)
{
	ck_assert_int_eq(roman_convert_to_int("I"), 1);
	ck_assert_int_eq(roman_convert_to_int("V"), 5);
	ck_assert_int_eq(roman_convert_to_int("X"), 10);
	ck_assert_int_eq(roman_convert_to_int("L"), 50);
	ck_assert_int_eq(roman_convert_to_int("C"), 100);
	ck_assert_int_eq(roman_convert_to_int("D"), 500);
	ck_assert_int_eq(roman_convert_to_int("M"), 1000);
}
END_TEST

START_TEST(null_string_is_an_error_so_return_minus_one)
{
	ck_assert_int_eq(roman_convert_to_int(NULL), -1);
}
END_TEST

START_TEST(unknown_characters_are_an_error_so_return_minus_one)
{
	ck_assert_int_eq(roman_convert_to_int("A"), -1);
	ck_assert_int_eq(roman_convert_to_int("$"), -1);
	ck_assert_int_eq(roman_convert_to_int("f"), -1);
	ck_assert_int_eq(roman_convert_to_int("W"), -1);
	ck_assert_int_eq(roman_convert_to_int("8"), -1);
}
END_TEST


TCase *conversion_to_int_tests()
{
	TCase *test_case = tcase_create("conversion to int");
	tcase_add_test(test_case, can_convert_single_numerals);
	tcase_add_test(test_case, null_string_is_an_error_so_return_minus_one);
	tcase_add_test(test_case, unknown_characters_are_an_error_so_return_minus_one);
	return test_case;
}
