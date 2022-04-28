NAME := main
SRC := arraystack.c
TEST_SRC := test.cc
GTEST_DIR=../../../gtest/
all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -L${GTEST_DIR}/lib -I${GTEST_DIR}/include -pthread -lgtest -std=c++11
	./test
	rm test

${NAME}: main.c arraystack.c
	gcc -fdiagnostics-color=always -g *.c -o main

.PHONY: all test