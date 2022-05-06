#include "arrayqueue.h"
#include "linkeddequeue.h"
// #include <gtest/gtest.h>
#include "../../../gtest/include/gtest/gtest.h"

#include <stdio.h>

TEST(createArrayQueue, when_create_expect_true) {
    ArrayQueue *tmp = createArrayQueue(1);
    EXPECT_NE(tmp, nullptr);
    free(tmp);

    tmp = createArrayQueue(10);
    EXPECT_EQ(tmp->maxElementCount, 10);
    free(tmp);
};

TEST(enqueueAQ, when_emptyQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(10);
    ArrayQueueNode node;
    node.data = 1;
    EXPECT_EQ(enqueueAQ(tmp, node), 1);
    EXPECT_EQ(tmp->currentElementCount, 1);
    EXPECT_EQ(tmp->front, 0);
    EXPECT_EQ(tmp->rear, 0);

    EXPECT_EQ(enqueueAQ(tmp, node), 1);
    EXPECT_EQ(tmp->currentElementCount, 2);
    EXPECT_EQ(tmp->front, 0);
    EXPECT_EQ(tmp->rear, 1);
    free(tmp);
}

TEST(enqueueAQ, when_fullQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(1);
    ArrayQueueNode node;
    node.data = 1;
    EXPECT_EQ(enqueueAQ(tmp, node), 1);
    EXPECT_EQ(tmp->currentElementCount, 1);
    EXPECT_EQ(tmp->front, 0);
    EXPECT_EQ(tmp->rear, 0);

    EXPECT_EQ(enqueueAQ(tmp, node), 0);
    free(tmp);
}

TEST(dequeueAQ, when_emptyQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(1);
    EXPECT_EQ(dequeueAQ(tmp), nullptr);
    free(tmp);
}

TEST(dequeueAQ, when_onlyOneQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(1);
    ArrayQueueNode node;

    node.data = 1;
    EXPECT_EQ(tmp->front, 0);
    enqueueAQ(tmp, node);
    EXPECT_EQ(tmp->rear, 0);
    ArrayQueueNode tempNode = *dequeueAQ(tmp);
    EXPECT_EQ(tempNode.data, 1);
    EXPECT_EQ(tmp->currentElementCount, 0);
    EXPECT_EQ(tmp->maxElementCount, 1);
    EXPECT_EQ(tmp->front, 1);
    EXPECT_EQ(tmp->rear, 0);
    free(tmp);
}

TEST(peekAQ, when_onlyOneQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(1);
    ArrayQueueNode node;

    node.data = 1;
    EXPECT_EQ(tmp->front, 0);
    enqueueAQ(tmp, node);
    EXPECT_EQ(tmp->rear, 0);
    ArrayQueueNode tempNode = *peekAQ(tmp);
    EXPECT_EQ(tempNode.data, 1);
    EXPECT_EQ(tmp->currentElementCount, 1);
    EXPECT_EQ(tmp->maxElementCount, 1);
    EXPECT_EQ(tmp->front, 0);
    EXPECT_EQ(tmp->rear, 0);
    free(tmp);
}

TEST(insertFrontLD, when_emptyLD_expect_suceess) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    node.data = 1;

    EXPECT_EQ(deque->currentElementCount, 0);
    insertFrontLD(deque, node);
    EXPECT_EQ(deque->currentElementCount, 1);
    EXPECT_EQ(deque->pFrontNode->data, 1);
    EXPECT_EQ(deque->pRearNode->data, 1);
    DequeNode node2;

    node2.data = 2;
    insertFrontLD(deque, node2);
    EXPECT_EQ(deque->currentElementCount, 2);
    EXPECT_EQ(deque->pRearNode->data, 2);
    EXPECT_EQ(deque->pFrontNode->data, 1);
    free(deque);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}