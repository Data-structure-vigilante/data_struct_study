GTEST_DIR=googletest/googletest
all:
	g++ -o main main.cc testExample.cc
test:
	g++ -o testExample sum_test.cc testExample.cc -isystem ${GTEST_DIR}/include -L${GTEST_DIR}/build -pthread -lgtest -std=c++11
	./testExample