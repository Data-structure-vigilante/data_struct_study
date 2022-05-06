#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"

TEST(create, when_createWithZero_expect_NULL) {
	EXPECT_EQ(createArrayQueue(0), nullptr);
};

TEST(create, when_createWithNegative_expect_NULL) {
	EXPECT_EQ(createArrayQueue(-1), nullptr);
};

TEST(create, when_createWithValidInput_expect_NotNULL) {
	ArrayQueue *queue;

	queue = createArrayQueue(10);
	EXPECT_NE(queue, nullptr);
	EXPECT_EQ(queue->maxElementCount, 10);
	EXPECT_EQ(queue->front, -1);
	EXPECT_EQ(queue->rear, -1);
	deleteArrayQueue(queue);
}

TEST(enqueue, when_enqueueToEmptyQueue_expect_TRUE) {
	ArrayQueue *queue;
	ArrayQueueNode	temp;

	temp.data = 1;
	queue = createArrayQueue(10);
	enqueueAQ(queue, temp);
	EXPECT_EQ(queue->front, 0);
	EXPECT_EQ(queue->rear, 0);
	EXPECT_EQ(queue->currentElementCount, 1);
	deleteArrayQueue(queue);
}

TEST(enqueue, when_enqueueToEmptyQueue_expect_FALSE) {
	ArrayQueue *queue;
	ArrayQueueNode	temp;

	temp.data = 1;
	queue = createArrayQueue(1);
	enqueueAQ(queue, temp);
	EXPECT_EQ(queue->front, 0);
	EXPECT_EQ(queue->rear, 0);
	EXPECT_EQ(queue->currentElementCount, 1);
	deleteArrayQueue(queue);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}