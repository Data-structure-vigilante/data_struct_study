# GTEST_DIR=/Users/hekang/Documents/자료구조/data_struct_study/gtest
LIB_DIR=../../../gtest/
all:
	g++ -o main main.cc testExample.cc
test:
	g++ -o testExample sum_test.cc testExample.cc -L${LIB_DIR} -I${LIB_DIR} -pthread -lgtest -std=c++11
	./testExample