#include <check.h>

START_TEST(one_and_one_is_two)
{
	ck_assert_int_eq(1, 2);	
}
END_TEST

TCase *addition_tests()
{
	TCase *test_case = tcase_create("addition tests");
	tcase_add_test(test_case, one_and_one_is_two);
	return test_case;
}
