NAME := main
SRC := avltree.c bintree.c
TEST_SRC := test.cc
GTEST_DIR=../../gtest/

all: ${NAME}

test: ${SRC} ${TEST_SRC}
	g++ -o test ${SRC} ${TEST_SRC} -pthread -lgtest -std=c++11 -g3 -fsanitize=address
	./test
	rm test

${NAME}: main.c ${SRC}
	gcc -fdiagnostics-color=always -g main.c ${SRC} -o main

.PHONY: all test