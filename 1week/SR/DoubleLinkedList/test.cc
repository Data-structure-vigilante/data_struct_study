#include <gtest/gtest.h>
#include "doublylist.h"
#include <stdio.h>

DoublyList *pList = createDoublyList();

TEST(create, pos) { EXPECT_NE(createDoublyList(), nullptr); };
DoDoublyListNode tmp2;
TEST(add, over)
{
	EXPECT_EQ(addDLElement(pList, 1, tmp), -1);
};
TEST(add, 0) { EXPECT_EQ(addDLElement(pList, 0, tmp), 0); };
TEST(add, 1) { EXPECT_EQ(addDLElement(pList, 1, tmp), 1); };
TEST(add, 2) { EXPECT_EQ(addDLElement(pList, 2, tmp), 2); };
TEST(add, re1) { EXPECT_EQ(addDLElement(pList, 1, tmp), 1); };
TEST(add, null) { EXPECT_EQ(addDLElement(nullptr, 5, tmp), -1); };

TEST(remove, pos)
{
	EXPECT_EQ(removeDLElement(pList, 0), 0);
};
TEST(remove, neg) { EXPECT_EQ(removeDLElement(pList, -5), -1); };
TEST(remove, null) { EXPECT_EQ(removeDLElement(nullptr, 4), -1); };
TEST(length, 3) { EXPECT_EQ(getDoublyListLength(pList), 3); };
TEST(get, pos) { EXPECT_NE(getDLElement(pList, 3), nullptr); };
TEST(get, neg) { EXPECT_EQ(getDLElement(pList, -10), nullptr); };
TEST(get, null) { EXPECT_EQ(getDLElement(nullptr, 5), nullptr); };

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}