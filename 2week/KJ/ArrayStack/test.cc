#include <gtest/gtest.h>
#include "arraystack.h"
#include <stdio.h>

TEST(createArrayStack, when_negativeInt_expect_NULL)
{
	EXPECT_EQ(createArrayStack(-1), nullptr);
}
TEST(createArrayStack, when_success_expect_maxElementCount)
{
	EXPECT_EQ(createArrayStack(10)->maxElementCount, 10);
}

TEST(pushLS, when_pushToEmptyStack_expect_0)
{
	ArrayStack *tmp = createArrayStack(10);
	StackNode elem = {25};

	EXPECT_EQ(pushLS(tmp, elem), 0);
	EXPECT_EQ(tmp->pElement->data, 25);
	EXPECT_EQ(tmp->currentElementCount, 1);
}
TEST(pushLS, when_push_expect_i)
{
	ArrayStack *tmp = createArrayStack(10);
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		EXPECT_EQ(pushLS(tmp, elem), i);
		EXPECT_EQ(tmp->pElement[i].data, i + 1);
	}
}

TEST(popLS, when_popEmptyStack_expect_NULL)
{
	ArrayStack *tmp = createArrayStack(10);

	EXPECT_EQ(popLS(tmp), nullptr);
}

TEST(popLS, when_popSuccess_expect_i)
{
	ArrayStack *tmp = createArrayStack(10);
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		pushLS(tmp, elem);
	}
	for (int i = 10; i > 0; --i)
	{
		EXPECT_EQ(popLS(tmp)->data, i);
	}
}

TEST(peekLS, when_peekSuccess_expect_i)
{
	ArrayStack *tmp = createArrayStack(10);
	for (int i = 0; i < 10; ++i)
	{
		StackNode elem = {i + 1};
		pushLS(tmp, elem);
	}
	for (int i = 10; i > 0; --i)
	{
		EXPECT_EQ(peekLS(tmp)->data, 10);
	}
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}