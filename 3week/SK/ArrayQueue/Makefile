NAME := main
SRC := arrayqueue.c
TEST_SRC := test.cc
GTEST_DIR=../../../gtest/
all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -fsanitize=address -pthread -lgtest -std=c++11
	./test
	rm test

.PHONY: all test