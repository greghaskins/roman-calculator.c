#include <check.h>

START_TEST(test_hello_world)
{
	ck_assert_str_eq("Hello", "World");
}
END_TEST

int main (void)
{
	TCase *tcase = tcase_create("hi"); 
	tcase_add_test(tcase, test_hello_world);

	Suite *suite = suite_create("Hello");
	suite_add_tcase(suite, tcase);

	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_NORMAL);

	int failure_count = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failure_count;
}

