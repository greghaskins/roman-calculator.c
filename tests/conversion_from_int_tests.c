#include <check.h>

#include "../src/roman_convert_from_int.h"

static void verify_from_int(const int input, const char *expected_result)
{
	char *actual_result = roman_convert_from_int(input);

	ck_assert_msg(
			strcmp(expected_result, actual_result) == 0,
			"roman from %d:\n expected %s, but got %s",
			input, expected_result, actual_result);
	free(actual_result);
}

START_TEST(can_convert_numbers_with_single_numeral)
{
	verify_from_int(1, "I");
	verify_from_int(5, "V");
	verify_from_int(10, "X");
	verify_from_int(50, "L");
	verify_from_int(100, "C");
	verify_from_int(500, "D");
	verify_from_int(1000, "M");
}
END_TEST

START_TEST(can_represent_larger_numbers_by_combining_and_repeating)
{
	verify_from_int(2, "II");
	verify_from_int(3, "III");
	verify_from_int(6, "VI");
	verify_from_int(8, "VIII");
	verify_from_int(37, "XXXVII");
	verify_from_int(580, "DLXXX");
	verify_from_int(2001, "MMI");
	verify_from_int(1666, "MDCLXVI");
	verify_from_int(3888, "MMMDCCCLXXXVIII");
}
END_TEST

START_TEST(uses_shorthand_subtractive_form_instead_of_repeating_four_times)
{
	verify_from_int(4, "IV");
	verify_from_int(9, "IX");
	verify_from_int(40, "XL");
	verify_from_int(90, "XC");
	verify_from_int(400, "CD");
	verify_from_int(900, "CM");
	verify_from_int(444, "CDXLIV");
	verify_from_int(2999, "MMCMXCIX");
}
END_TEST

START_TEST(numbers_less_than_one_are_an_error)
{
	verify_from_int(0, "underflow error");
	verify_from_int(-1, "underflow error");
	verify_from_int(-435745, "underflow error");
}
END_TEST

START_TEST(numbers_greater_than_maximum_possible_3999_are_an_error)
{
	verify_from_int(4000, "overflow error");
	verify_from_int(4001, "overflow error");
	verify_from_int(9345637, "overflow error");
}
END_TEST

TCase *conversion_from_int_tests()
{
	TCase *test_case = tcase_create("conversion from int");
	tcase_add_test(test_case, can_convert_numbers_with_single_numeral);
	tcase_add_test(test_case, can_represent_larger_numbers_by_combining_and_repeating);
	tcase_add_test(test_case, uses_shorthand_subtractive_form_instead_of_repeating_four_times);
	tcase_add_test(test_case, numbers_less_than_one_are_an_error);
	tcase_add_test(test_case, numbers_greater_than_maximum_possible_3999_are_an_error);
	return test_case;
}
