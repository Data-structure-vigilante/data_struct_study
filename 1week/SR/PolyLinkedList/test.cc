#include <gtest/gtest.h>
#include "polylinkedlist.h"
#include <stdio.h>

TEST(create, pos)
{
	EXPECT_NE(createPolyList(), nullptr);
};
TEST(add, list)
{
	PolyList *listA;

	listA = createPolyList();

	for (int i = 5; i > 0; i--;)
}
TEST(sum, same_length)
{
	PolyList *listA;
	PolyList *listB;

	listA = createPolyList();
	listB = createPolyList();
	for (int i = 10; i > 0; --i)
	{
		addPolyNodeLast(listA, i, i);
	}
	for (int i = 20; i > 10; --i)
	{
		addPolyNodeLast(listB, i, i);
	}
	EXPECT_NE(sumPolyList(listA, listB), nullptr);
	EXPECT_NE(sumPolyList(listA, listA), nullptr);
};

TEST(sum, null)
{
	PolyList *temp;

	temp = createPolyList();
	for (int i = 10; i > 0; --i)
	{
		addPolyNodeLast(temp, i, i);
	}
	EXPECT_NE(sumPolyList(temp, nullptr), nullptr);
	EXPECT_NE(sumPolyList(nullptr, temp), nullptr);
	EXPECT_EQ(sumPolyList(nullptr, nullptr), nullptr);
};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}