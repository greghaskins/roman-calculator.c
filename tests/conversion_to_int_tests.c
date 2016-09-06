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

START_TEST(can_convert_simple_additive_numerals)
{
	ck_assert_int_eq(roman_convert_to_int("II"), 2);
	ck_assert_int_eq(roman_convert_to_int("XXVII"), 27);
	ck_assert_int_eq(roman_convert_to_int("MCV"), 1105);
}
END_TEST

START_TEST(can_understand_shorthand_subtractive_form)
{
	ck_assert_int_eq(roman_convert_to_int("IV"), 4);
	ck_assert_int_eq(roman_convert_to_int("IX"), 9);
	ck_assert_int_eq(roman_convert_to_int("XL"), 40);
	ck_assert_int_eq(roman_convert_to_int("XC"), 90);
	ck_assert_int_eq(roman_convert_to_int("CD"), 400);
	ck_assert_int_eq(roman_convert_to_int("CM"), 900);
	ck_assert_int_eq(roman_convert_to_int("MCMXLIV"), 1944);
}
END_TEST

START_TEST(null_string_is_an_error_so_return_minus_one)
{
	ck_assert_int_eq(roman_convert_to_int(NULL), -1);
}
END_TEST

START_TEST(unknown_characters_anywhere_are_an_error_so_return_minus_one)
{
	ck_assert_int_eq(roman_convert_to_int("A"), -1);
	ck_assert_int_eq(roman_convert_to_int("$"), -1);
	ck_assert_int_eq(roman_convert_to_int("XIfI"), -1);
	ck_assert_int_eq(roman_convert_to_int("MW"), -1);
	ck_assert_int_eq(roman_convert_to_int("DC8"), -1);
}
END_TEST

START_TEST(semantically_invalid_numerals_are_an_error_so_return_minus_one)
{
	ck_assert_int_eq(roman_convert_to_int("VV"), -1);
	ck_assert_int_eq(roman_convert_to_int("VIV"), -1);
	ck_assert_int_eq(roman_convert_to_int("DDD"), -1);
	ck_assert_int_eq(roman_convert_to_int("CMCM"), -1);
	ck_assert_int_eq(roman_convert_to_int("LLIIII"), -1);
	ck_assert_int_eq(roman_convert_to_int("IXIV"), -1);
	ck_assert_int_eq(roman_convert_to_int("XIXIVIII"), -1);
}
END_TEST

TCase *conversion_to_int_tests()
{
	TCase *test_case = tcase_create("conversion to int");
	tcase_add_test(test_case, can_convert_single_numerals);
	tcase_add_test(test_case, can_convert_simple_additive_numerals);
	tcase_add_test(test_case, can_understand_shorthand_subtractive_form);
	tcase_add_test(test_case, null_string_is_an_error_so_return_minus_one);
	tcase_add_test(test_case, unknown_characters_anywhere_are_an_error_so_return_minus_one);
	tcase_add_test(test_case, semantically_invalid_numerals_are_an_error_so_return_minus_one);
	return test_case;
}
