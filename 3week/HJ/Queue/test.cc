#include <gtest/gtest.h>
#include "arrayqueue.h"
#include <stdio.h>

TEST(createArrayQueue, when_create_expect_true)
{
	ArrayQueue *tmp = createArrayQueue(1);
	EXPECT_NE(tmp, nullptr);
	free(tmp);

	tmp = createArrayQueue(10);
	EXPECT_EQ(tmp->maxElementCount, 10);
	free(tmp);
};

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}