OBJECTS = $(patsubst %.h,%.o,$(wildcard */*.h))
CFLAGS = -Wall -Wextra -std=c99 -pedantic -Werror -O0
CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: run_tests valgrind

run_tests: compile_tests
	${CURDIR}/run_tests

valgrind: compile_tests
	valgrind --leak-check=full --error-exitcode=1 -q ${CURDIR}/run_tests

compile_tests: ${CURDIR}/tests/run_tests.c $(OBJECTS)
	gcc $(CFLAGS) -MMD -coverage -o run_tests $< $(CHECK_LIBS) $(OBJECTS)

%.o: ${CURDIR}/%.c
	gcc $(CFLAGS) -MMD -coverage -o $@ -c $<

-include *.d

clean:
	git clean -dXf
