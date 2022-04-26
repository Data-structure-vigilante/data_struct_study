#include <gtest/gtest.h>
#include "arraylist.h"
#include <stdio.h>

ArrayList *pList = createArrayList(20);
TEST(create, neg)
{
	EXPECT_EQ(createArrayList(-1), nullptr);
};
TEST(create, pos) { EXPECT_NE(createArrayList(20), pList); };
TEST(create, int_max) { EXPECT_NE(createArrayList(2147483647), nullptr); };
TEST(is_full, empty) { EXPECT_EQ(isArrayListFull(pList), 0); };
TEST(is_full, full) { EXPECT_NE(isArrayListFull(pList), 1); };
TEST(is_full, null) { EXPECT_EQ(isArrayListFull(nullptr), 0); };
ArrayListNode tmp;
TEST(add, pos) { EXPECT_EQ(addALElement(pList, 4, tmp), 4); };
TEST(add, neg) { EXPECT_EQ(addALElement(pList, -3, tmp), -1); };
TEST(add, null) { EXPECT_EQ(addALElement(nullptr, 5, tmp), -1); };
TEST(remove, pos) { EXPECT_EQ(removeALElement(pList, 0), 0); };
TEST(remove, neg) { EXPECT_EQ(removeALElement(pList, -5), -1); };
TEST(remove, null) { EXPECT_EQ(removeALElement(nullptr, 4), -1); };

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}