#include <check.h>

#include "addition_tests.h"
#include "subtraction_tests.h"
#include "conversion_to_int_tests.c"
#include "conversion_from_int_tests.c"

int main(void)
{
	Suite *suite = suite_create("roman_calculator");
	
	suite_add_tcase(suite, addition_tests());
	suite_add_tcase(suite, subtraction_tests());
	suite_add_tcase(suite, conversion_to_int_tests());
	suite_add_tcase(suite, conversion_from_int_tests());
	
	SRunner *runner = srunner_create(suite);
	srunner_run_all(runner, CK_NORMAL);
	int failure_count = srunner_ntests_failed(runner);
	srunner_free(runner);

	return failure_count;
}
