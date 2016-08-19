OBJECTS = roman_calculator.o roman_convert_to_int.o
CFLAGS = -Wall -Wextra -std=c99 -pedantic -Werror -O0
CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: run_tests
	${CURDIR}/run_tests

run_tests: ${CURDIR}/tests/run_tests.c $(OBJECTS)
	gcc $(CFLAGS) -MMD -coverage -o $@ $< $(CHECK_LIBS) $(OBJECTS)

%.o: ${CURDIR}/src/%.c
	gcc $(CFLAGS) -MMD -coverage -o $@ -c $<

-include *.d

clean:
	git clean -dXf
