CHECK_LIBS = -pthread -lcheck_pic -lrt -lm

all: check

check: check_roman
	./check_roman

check_roman: check_roman.c
	gcc -o $@ $< $(CHECK_LIBS)

clean:
	rm -f check_roman *.o
