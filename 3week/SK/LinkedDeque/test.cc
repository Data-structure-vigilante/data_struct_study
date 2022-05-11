#include "linkeddeque.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(create, when_createWithValidInput_expect_NotNULL) {
    LinkedDeque *deque;

    deque = createLinkedDeque();
    EXPECT_NE(deque, nullptr);
    EXPECT_EQ(deque->currentElementCount, 0);
    deleteLinkedDeque(deque);
}

TEST(FrontPushPopTest, when_push5ElementAndPop_expect_data) {
    LinkedDeque *deque;

    deque = createLinkedDeque();
    for (int i = 0; i < 5; ++i) {
        DequeNode node = {(char)i, 0, 0};
        insertFrontLD(deque, node);
        EXPECT_EQ(deque->currentElementCount, i + 1);
        EXPECT_EQ(peekFrontLD(deque)->data, i);
    }
    for (int i = 4; i >= 0; --i) {
        DequeNode *popNode;
        popNode = popFrontLD(deque);
        EXPECT_EQ(popNode->data, i);
        free(popNode);
    }
    deleteLinkedDeque(deque);
}

TEST(RearPushPopTest, when_push5ElementAndPop_expect_data) {
    LinkedDeque *deque;

    deque = createLinkedDeque();
    for (int i = 0; i < 5; ++i) {
        DequeNode node = {(char)i, 0, 0};
        insertRearLD(deque, node);
        EXPECT_EQ(deque->currentElementCount, i + 1);
        EXPECT_EQ(peekRearLD(deque)->data, i);
    }
    for (int i = 4; i >= 0; --i) {
        DequeNode *popNode;
        popNode = popRearLD(deque);
        EXPECT_EQ(popNode->data, i);
        free(popNode);
    }
    deleteLinkedDeque(deque);
}

TEST(CombinationPushPopTest,
     when_pushFront3elementAndPushRear3element_expect_validData) {
    LinkedDeque *deque;

    deque = createLinkedDeque();
    for (int i = 0; i < 6; ++i) {
        DequeNode node = {(char)i, 0, 0};
        if (i % 2) {
            insertFrontLD(deque, node);
        } else {
            insertRearLD(deque, node);
        }
        EXPECT_EQ(deque->currentElementCount, i + 1);
        if (i % 2) {
            EXPECT_EQ(peekRearLD(deque)->data, i - 1);
        } else {
            EXPECT_EQ(peekRearLD(deque)->data, i);
        }
    }
    deleteLinkedDeque(deque);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}