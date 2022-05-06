#include "linkeddeque.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


TEST(create, when_createWithValidInput_expect_NotNULL) {
    LinkedDeque *queue;

    queue = createLinkedDeque();
    EXPECT_NE(queue, nullptr);
    EXPECT_EQ(queue->currentElementCount, 0);
    deleteLinkedDeque(queue);
}

TEST(insertFrontLD, when_) {

}

// TEST(enqueue, when_enqueueToEmptyQueue_expect_TRUE) {
//     ArrayQueue *queue;
//     ArrayQueueNode temp;

//     temp.data = 1;
//     queue = createArrayQueue(10);
//     enqueueAQ(queue, temp);
//     EXPECT_EQ(queue->front, 0);
//     EXPECT_EQ(queue->rear, 0);
//     EXPECT_EQ(queue->currentElementCount, 1);
//     deleteArrayQueue(queue);
// }

// TEST(enqueue, when_enqueueToEmptyQueue_expect_FALSE) {
//     ArrayQueue *queue;
//     ArrayQueueNode temp;

//     temp.data = 1;
//     queue = createArrayQueue(1);
//     enqueueAQ(queue, temp);
//     EXPECT_EQ(queue->front, 0);
//     EXPECT_EQ(queue->rear, 0);
//     EXPECT_EQ(queue->currentElementCount, 1);
//     deleteArrayQueue(queue);
// }

// TEST(dequeueAQ, when_deQueToEmptyQueue_expect_NULL) {
//     ArrayQueue *queue;
//     queue = createArrayQueue(1);

//     EXPECT_EQ(dequeueAQ(queue), nullptr);
//     deleteArrayQueue(queue);
// }

// TEST(dequeueAQ, when_1ElementQueue_expect_element) {
//     ArrayQueue *queue;
//     ArrayQueueNode temp;
// 	ArrayQueueNode *result;

//     temp.data = 1;
//     queue = createArrayQueue(1);
//     enqueueAQ(queue, temp);
// 		result = dequeueAQ(queue);
// 		EXPECT_NE(result, nullptr);
// 		EXPECT_EQ(result->data, 1);
// 		EXPECT_EQ(queue->currentElementCount, 0);
// 		EXPECT_EQ(queue->front, 0);
// 		EXPECT_EQ(queue->rear, 0);
//     deleteArrayQueue(queue);
// }

// TEST(peekAQ, when_queueIsEmpty_expect_NULL) {
//     ArrayQueue *queue;

//     queue = createArrayQueue(1);
// 	EXPECT_EQ(peekAQ(queue), nullptr);
//     deleteArrayQueue(queue);
// }

// TEST(peekAQ, when_queueIsNotEmpty_expect_NULL) {
//     ArrayQueue *queue;
//     ArrayQueueNode temp;

//     temp.data = 1;
//     queue = createArrayQueue(1);
//     enqueueAQ(queue, temp);
// 	EXPECT_NE(peekAQ(queue), nullptr);
//     EXPECT_EQ(peekAQ(queue)->data, 1);
//     deleteArrayQueue(queue);
// }

// TEST(CircularCase, when_expect_TRUE) {
// 	ArrayQueue *queue;
//     ArrayQueueNode temp;

//     queue = createArrayQueue(3);
// 	for (int i=0;i<queue->maxElementCount;i++) {
// 		temp.data = i+1;
// 		enqueueAQ(queue, temp);
// 		EXPECT_EQ(queue->currentElementCount, temp.data);
// 	}
// 	for (int i=0;i<queue->maxElementCount-1;i++) {
// 		EXPECT_EQ(dequeueAQ(queue)->data, i+1);
// 		EXPECT_EQ(queue->front, i+1);
// 		EXPECT_EQ(queue->currentElementCount, queue->maxElementCount -1 -i);
// 	}
//     temp.data = 10;
//     enqueueAQ(queue, temp);
//     EXPECT_EQ(queue->rear, 0);
//     enqueueAQ(queue, temp);
//     EXPECT_EQ(queue->rear, 1);
//     enqueueAQ(queue, temp);
//     EXPECT_NE(queue->rear, 2);
//     deleteArrayQueue(queue);
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}