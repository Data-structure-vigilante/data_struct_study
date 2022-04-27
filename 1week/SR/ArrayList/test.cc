#include <gtest/gtest.h>
#include "arraylist.h"
#include <stdio.h>

TEST(createArrayList, ArrayList)
{
	EXPECT_EQ(createArrayList(10)->maxElementCount, 10);
	EXPECT_EQ(createArrayList(10)->currentElementCount, 0);
	EXPECT_EQ(createArrayList(2147483647)->maxElementCount, 2147483647);
	EXPECT_EQ(createArrayList(2147483648), nullptr);
	EXPECT_EQ(createArrayList(-1), nullptr);
}

TEST(addALElement, ArrayList)
{
	ArrayList *arr;

	arr = createArrayList(20);
	for (int i = 0; i < 20; ++i)
	{
		ArrayListNode elem = {i + 1};
		EXPECT_EQ(addALElement(arr, i, elem), i);
	}
	ArrayListNode elem = {1};
	EXPECT_EQ(addALElement(arr, 20, elem), -1);
	EXPECT_EQ(addALElement(nullptr, 2, elem), -1);
}

TEST(isArrayListFull, ArrayList)
{
	ArrayList *arr = createArrayList(100);
	EXPECT_EQ(isArrayListFull(nullptr), 0);
	EXPECT_EQ(isArrayListFull(arr), 0);
	for (int i = 0; i < 100; ++i)
	{
		ArrayListNode elem = {i + 1};
		addALElement(arr, i, elem);
		if (i == 50)
			EXPECT_EQ(isArrayListFull(arr), 0);
	}
	EXPECT_EQ(isArrayListFull(arr), arr->currentElementCount == arr->maxElementCount);
}
TEST(removeALElement, ArrayList)
{
	ArrayList *arr = createArrayList(100);
	for (int i = 0; i < 50; ++i)
	{
		ArrayListNode elem = {i + 1};
		addALElement(arr, i, elem);
	}
	EXPECT_EQ(removeALElement(arr, 25), 25);
	EXPECT_EQ(arr->currentElementCount, 49);
	EXPECT_EQ(removeALElement(arr, 500), -1);
	EXPECT_EQ(arr->currentElementCount, 49);
	EXPECT_EQ(removeALElement(nullptr, 10), -1);
}

TEST(getALElement, ArrayList)
{
	ArrayList *arr = createArrayList(10);
	for (int i = 0; i < 10; ++i)
	{
		ArrayListNode elem = {i};
		addALElement(arr, i, elem);
	}
	EXPECT_EQ(getALElement(arr, 5)->data, 5);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}