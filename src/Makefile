# Makefile

CC=gcc
CFLAGS=-g -Wall --std=gnu99 -ljansson -fno-stack-protector
LDFLAGS=-lncurses

SRCS=$(wildcard *.c)
OBJS=$(SRCS:.c=.o )

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

all: $(OBJS)
	$(CC) $(CFLAGS) *.o -o tranker $(LDFLAGS)

build_tests:
	g++ -o tests_run -g -Wall tests/test_suite.cpp -lgtest -lpthread -ljansson -lncurses

test: build_tests
	./tests_run

gdbtest: build_tests
	gdb ./tests_run

valgrind: build_tests
	valgrind ./tests_run

spectrum:
	zcc +zx -c tranker.c

run: all
	./tranker

clean:
	rm -f $(OBJS) tranker tests_run

