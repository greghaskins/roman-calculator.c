OBJECTS = roman_calculator.o
CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: run_tests
	${CURDIR}/run_tests

run_tests: ${CURDIR}/tests/run_tests.c $(OBJECTS)
	gcc -Wall -MMD -coverage -o $@ $< $(CHECK_LIBS) $(OBJECTS)

%.o: ${CURDIR}/src/%.c
	gcc -Wall -MMD -coverage -o $@ -c $<

-include *.d

clean:
	git clean -dXf
