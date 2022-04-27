#include <gtest/gtest.h>
#include "doublylist.h"
#include <stdio.h>

TEST(addDLElement, DoublyList)
{
	DoublyList *arr;

	arr = createDoublyList(20);
	for (int i = 0; i < 20; ++i)
	{
		DoublyListNode elem = {i + 1};
		EXPECT_EQ(addDLElement(arr, i, elem), i);
	}
	DoublyListNode elem = {1};
	EXPECT_EQ(addDLElement(arr, 20, elem), -1);
	EXPECT_EQ(addDLElement(nullptr, 2, elem), -1);
}

TEST(removeDLElement, DoublyList)
{
	DoublyList *arr = createDoublyList(100);
	for (int i = 0; i < 50; ++i)
	{
		DoublyListNode elem = {i + 1};
		addDLE'lement(arr, i, elem);
	}
	EXPECT_EQ(removeDLElement(arr, 25), 25);
	EXPECT_EQ(arr->currentElementCount, 49);
	EXPECT_EQ(removeDLElement(arr, 500), -1);
	EXPECT_EQ(arr->currentElementCount, 49);
	EXPECT_EQ(removeDLElement(nullptr, 10), -1);
}

TEST(getDLElement, DoublyList)
{
	DoublyList *arr = createDoublyList(10);
	for (int i = 0; i < 10; ++i)
	{
		DoublyListNode elem = {i};
		addDLElement(arr, i, elem);
	}
	EXPECT_EQ(getDLElement(arr, 5)->data, 5);
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
createDoublyList