NAME := main
SRC := linkedstack.c exprlinkedstack.c
TEST_SRC := test.cc
GTEST_DIR=../../../gtest/
all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -pthread -lgtest -std=c++11
	./test
	rm test

.PHONY: all test