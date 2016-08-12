OBJECTS = roman_calculator.o
CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: run_tests
	${CURDIR}/run_tests

run_tests: ${CURDIR}/tests/run_tests.c $(OBJECTS)
	gcc -Wall -MMD -o $@ $< $(CHECK_LIBS) $(OBJECTS)

%.o: ${CURDIR}/src/%.c
	gcc -Wall -MMD -o $@ -c $<

-include *.d

clean:
	rm -f run_tests *.o *.d
