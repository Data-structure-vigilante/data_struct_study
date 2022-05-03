NAME := main
SRC := ../LinkedStack/linkedstack.c mapdef.c
TEST_SRC := test.cc
INCLUDE := ../LinkedStack

all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -I${INCLUDE} -pthread -lgtest -std=c++11
	./test
	rm test

${NAME}: main.c ${SRC}
	gcc -fdiagnostics-color=always -g *.c -o main

clean:
	rm test

.PHONY: all test