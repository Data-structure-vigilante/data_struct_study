NAME := main
SRC := ./LinkedStack/linkedstack.c mapdef.c
TEST_SRC := test.cc
INCLUDE := ./LinkedStack

all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -I${INCLUDE} -pthread -lgtest -std=c++11
	./test
	rm test

${NAME}: ${NAME}.c ${SRC}
	gcc -fdiagnostics-color=always -g -I${INCLUDE} ${SRC} ${NAME}.c -o main

clean:
	rm test

run: all
	./${NAME}
	rm ${NAME}
.PHONY: all test run