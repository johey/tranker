# Makefile

CFLAGS=-g -Wall --std=gnu99
LDFLAGS=-lncurses

.PHONY: clean

tranker: 
	gcc $(CFLAGS) *.c -o tranker $(LDFLAGS)

build_tests:
	g++ -o tests_run -g -Wall tests/test_suite.cpp -lgtest -lpthread

test: build_tests
	./tests_run

valgrind: build_tests
	valgrind ./tests_run

spectrum:
	zcc +zx -c tranker.c

all: test spectrum tranker

run: tranker
	./tranker

clean:
	rm -f tranker tests_run *.o

