CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

check: check_main
	${CURDIR}/check_main

check_main: ${CURDIR}/tests/check_main.c
	gcc -Wall -MMD -o $@ $< $(CHECK_LIBS)

-include *.d

clean:
	rm -f check_main *.o *.d
