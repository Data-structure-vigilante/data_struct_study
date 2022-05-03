#include "linkedstack.h"
#include <gtest/gtest.h>
#include <stdio.h>

TEST(createLinkedStack, when_success_expect_notNull) {
    LinkedStack *stack = createLinkedStack();
    EXPECT_NE(stack, nullptr);
}

TEST(pushLS, when_emptyStack_expect_return0) {
    LinkedStack *stack = createLinkedStack();
		StackNode element = {1, 0};
		EXPECT_EQ(pushLS(stack, element), 0);
		EXPECT_EQ(stack->pTopElement->data, 1);
}

TEST(pushLS, when_push_expect_i)
{
	LinkedStack *tmp = createLinkedStack();
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		EXPECT_EQ(pushLS(tmp, elem), i);
	}
}

TEST(popLS, when_pop_expect_i) {
	LinkedStack *tmp = createLinkedStack();
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		EXPECT_EQ(pushLS(tmp, elem), i);
	}
	for (int i = 10; i > 0; --i)
	{
		EXPECT_EQ(popLS(tmp)->data, i);
		EXPECT_EQ(tmp->currentElementCount, i - 1);
	}
}

TEST(peekLS, when_peekSuccess_expect_i)
{
	LinkedStack *tmp = createLinkedStack();
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		pushLS(tmp, elem);
	}
	for (int i = 10; i > 0; --i)
	{
		EXPECT_EQ(peekLS(tmp)->data, 10);
		EXPECT_EQ(tmp->currentElementCount, 10);
	}
}

TEST(deleteLinkedStack, when_deleteSuccess_expect_segfault) {
		LinkedStack *tmp = createLinkedStack();
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		pushLS(tmp, elem);
	}
	deleteLinkedStack(tmp);
	EXPECT_EQ(tmp->pTopElement->data, 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}