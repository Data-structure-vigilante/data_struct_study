#include <gtest/gtest.h>
#include <stdio.h>
#include "linkedlist.h"

LinkedList* test;
ListNode	temp = {0, NULL};

TEST(create, create_list) {
	test = createLinkedList();
	EXPECT_NE(test, nullptr);
}

TEST(add_invalid, pList_is_NULL) {
	EXPECT_EQ(addLLElement(NULL, 10, temp), -1);
}

TEST(add_invalid, position_negative) {
	EXPECT_EQ(addLLElement(test, -1, temp), -1);
}

TEST(add_invalid, position_overflow) {
	EXPECT_EQ(addLLElement(test, 10, temp), -1);
}


TEST(add_valid, empty_list) {
	EXPECT_EQ(test->currentElementCount, 0);
	EXPECT_EQ(addLLElement(test, 0, temp), 0);
	EXPECT_EQ(test->currentElementCount, 1);
	EXPECT_EQ(getLLElement(test, 0)->data, 0);
}

TEST(add_valid, non_empty_list) {
	ListNode Node;
	EXPECT_EQ(test->currentElementCount, 1);
	for (int i=1;i<10;i++) {
		Node.data = i;
		EXPECT_EQ(addLLElement(test, i, Node), 0);
	}
	EXPECT_EQ(test->currentElementCount, 10);
	for (int i=0;i<10;i++) {
		EXPECT_EQ(getLLElement(test, i)->data, i);
	}
}

TEST(remove_invalid, pList_is_NULL) {
	EXPECT_EQ(removeLLElement(NULL, 10), -1);
}

TEST(remove_invalid, position_negative) {
	EXPECT_EQ(removeLLElement(test, -1), -1);
}

TEST(remove_invalid, position_overflow) {
	EXPECT_EQ(removeLLElement(test, 12), -1);
}

TEST(remove_valid, non_empty_list) {
	EXPECT_EQ(test->currentElementCount, 10);
	EXPECT_EQ(removeLLElement(test, 1), 0);
	EXPECT_EQ(test->currentElementCount, 9);
	EXPECT_EQ(getLLElement(test, 1)->data, 2);
}

TEST(remove_valid, empty_list) {
	EXPECT_EQ(test->currentElementCount, 9);
	clearLinkedList(test);
	EXPECT_EQ(test->currentElementCount, 0);
	EXPECT_EQ(test->headerNode.pLink, nullptr);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}