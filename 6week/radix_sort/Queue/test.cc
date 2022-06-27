#include "arrayqueue.h"
#include "linkeddequeue.h"
#include <gtest/gtest.h>
//#include "../../../gtest/include/gtest/gtest.h"

#include <stdio.h>

TEST(createArrayQueue, when_create_expect_true) {
    ArrayQueue *tmp = createArrayQueue(1);
    EXPECT_NE(tmp, nullptr);
    free(tmp->pElement);
    free(tmp);

    tmp = createArrayQueue(10);
    EXPECT_EQ(tmp->maxElementCount, 10);
    free(tmp->pElement);
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
    free(tmp->pElement);
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
    free(tmp->pElement);
    free(tmp);
}

TEST(dequeueAQ, when_emptyQueue_expect_1) {
    ArrayQueue *tmp = createArrayQueue(1);
    EXPECT_EQ(dequeueAQ(tmp), nullptr);
    free(tmp->pElement);
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
    EXPECT_EQ(tmp->front, 0);
    EXPECT_EQ(tmp->rear, 0);
    free(tmp->pElement);
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
    free(tmp->pElement);
    free(tmp);
}

TEST(insertRearLD, when_emptyLD_expect_suceess) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    node.data = 1;

    EXPECT_EQ(deque->currentElementCount, 0);
    insertRearLD(deque, node);
    EXPECT_EQ(deque->currentElementCount, 1);
    EXPECT_EQ(deque->pFrontNode->data, 1);
    EXPECT_EQ(deque->pRearNode->data, 1);
    DequeNode node2;

    node2.data = 2;
    insertRearLD(deque, node2);
    EXPECT_EQ(deque->currentElementCount, 2);
    EXPECT_EQ(deque->pRearNode->data, 2);
    EXPECT_EQ(deque->pFrontNode->data, 1);
    deleteLinkedDeque(deque);
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
    EXPECT_EQ(deque->pFrontNode->data, 2);
    EXPECT_EQ(deque->pRearNode->data, 1);
    deleteLinkedDeque(deque);
}

TEST(deleteFrontLD, when_LD_expect_success) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    node.data = 1;

    EXPECT_EQ(deque->currentElementCount, 0);
    insertFrontLD(deque, node);

    DequeNode *tmp;
    tmp = deleteFrontLD(deque);
    EXPECT_EQ(tmp->data, 1);
    free(tmp);
    tmp = deleteFrontLD(deque);
    EXPECT_EQ(tmp, nullptr);
    free(tmp);
    free(deque);
}

TEST(deleteFrontLD, when_multipleElementsLD_expect_success) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    DequeNode *tmp;

    for (int i = 0; i < 3; ++i) {
        node.data = i;
        insertRearLD(deque, node);
    }

    for (int i = 0; i < 3; ++i) {
        tmp = deleteFrontLD(deque);
        EXPECT_EQ(tmp->data, i);
        free(tmp);
    }
    tmp = deleteFrontLD(deque);
    EXPECT_EQ(tmp, nullptr);
    deleteLinkedDeque(deque);
}

TEST(deleteRearLD, when_multipleElementsLD_expect_success) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    DequeNode *tmp;

    for (int i = 0; i < 3; ++i) {
        node.data = i;
        insertFrontLD(deque, node);
    }

    for (int i = 0; i < 3; ++i) {
        tmp = deleteRearLD(deque);
        EXPECT_EQ(tmp->data, i);
        free(tmp);
    }
    tmp = deleteRearLD(deque);
    EXPECT_EQ(tmp, nullptr);
    deleteLinkedDeque(deque);
}

TEST(peekLD, when_LD_expect_success) {
    LinkedDeque *deque = createLinkedDeque();
    DequeNode node;
    DequeNode *tmp;

    for (int i = 0; i < 5; ++i) {
        node.data = i + 1;
        insertFrontLD(deque, node);
    }
    EXPECT_EQ(peekFrontLD(deque)->data, 5);
    EXPECT_EQ(peekRearLD(deque)->data, 1);
    deleteLinkedDeque(deque);
    system("leaks test");
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}