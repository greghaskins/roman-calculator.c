#include <check.h>

#include "addition_tests.c"

int main(void)
{
	Suite *suite = suite_create("roman_calculator");
	
	suite_add_tcase(suite, addition_tests());
	
	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_NORMAL);
	int failure_count = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failure_count;
}
