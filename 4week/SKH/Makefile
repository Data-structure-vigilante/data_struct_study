NAME := main
SRC := bintree.c
TEST_SRC := test.cc
GTEST_DIR=../../gtest/

all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -pthread -lgtest -std=c++11
	./test
	rm test

${NAME}: main.c arraylist.c
	gcc -fdiagnostics-color=always -g *.c -o main

.PHONY: all test