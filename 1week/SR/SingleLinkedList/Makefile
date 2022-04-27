NAME := main
SRC := linkedlist.c
TEST_SRC := test.cc

all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -pthread -lgtest -std=c++11
	./test

${NAME}: main.c linkedlist.c
	gcc -fdiagnostics-color=always -g *.c -o main

clean:
	rm test

.PHONY: all test