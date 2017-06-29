# Makefile

CFLAGS=-g -Wall --std=gnu99
LDFLAGS=-lncurses

.PHONY: clean

tranker: 
	gcc $(CFLAGS) *.c -o tranker $(LDFLAGS)

test:
	g++ -o test_run -Wall tests/test_suite.cpp -lgtest -lpthread
	./test_run

valgrind: test
	valgrind ./test_run

spectrum:
	zcc +zx -c tranker.c

all: test spectrum tranker

run: tranker
	./tranker

clean:
	rm -f tranker test_run *.o

