OBJECTS = roman_calculator.o
CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: check_main
	${CURDIR}/check_main

check_main: ${CURDIR}/tests/check_main.c $(OBJECTS)
	gcc -Wall -MMD -o $@ $< $(CHECK_LIBS) $(OBJECTS)

%.o: ${CURDIR}/src/%.c
	gcc -Wall -MMD -o $@ -c $<

-include *.d

clean:
	rm -f check_main *.o *.d
