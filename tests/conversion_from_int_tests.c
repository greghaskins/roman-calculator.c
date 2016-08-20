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
}
END_TEST


TCase *conversion_from_int_tests()
{
	TCase *test_case = tcase_create("conversion from int");
	tcase_add_test(test_case, can_convert_numbers_with_single_numeral);
	return test_case;
}
