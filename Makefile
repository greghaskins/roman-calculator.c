all: check

check: check_roman
	./check_roman

check_roman: check_roman.c
	gcc -o $@ $< `pkg-config --cflags --libs check`
