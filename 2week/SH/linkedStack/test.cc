#include "linkedStack.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

LinkedStack *stack;

TEST(create, when_create_expect_notNull) {
    stack = createLinkedStack();
    EXPECT_NE(stack, nullptr);
    deleteLinkedStack(stack);
};

TEST(create, when_createMaxelement1_expect_1) {
    stack = createLinkedStack();
    EXPECT_EQ(stack->currentElementCount, 0);
    deleteLinkedStack(stack);
};

TEST(pushLS, when_NullStack_expect_minus1) {
    StackNode node;
    stack = nullptr;
    // stack = createLinkedStack();
    node.data = 0;

    EXPECT_EQ(pushLS(stack, node), -1);
}

TEST(pushLS, when_Stack_expect_0) {
    StackNode node;
    stack = nullptr;
    stack = createLinkedStack();
    node.data = 0;

    EXPECT_EQ(pushLS(stack, node), 0);
    deleteLinkedStack(stack);
}

TEST(pushLS, when_Stack_expect_position) {
    StackNode node;
    stack = nullptr;
    stack = createLinkedStack();
    node.data = 0;

    for (int i = 0; i < 10; i++) {
        node.data = i;
        EXPECT_EQ(pushLS(stack, node), i);
    }
    deleteLinkedStack(stack);
}

TEST(popLS, when_StackIsEmpty_expect_FALSE) {
    stack = createLinkedStack();
    EXPECT_EQ(popLS(stack), nullptr);
    deleteLinkedStack(stack);
}

TEST(popLS, when_StackIsNotEmpty_expect_TRUE) {
    StackNode *temp;
    StackNode node;
    node.data = 1;
    stack = createLinkedStack();
    pushLS(stack, node);
    temp = popLS(stack);
    EXPECT_EQ(temp->data, 1);
    EXPECT_EQ(stack->currentElementCount, 0);
    EXPECT_NE(temp, nullptr);
    deleteLinkedStack(stack);
    free(temp);
}

TEST(popLS, when_StackMultiNode_expect_TRUE) {
    StackNode *temp;
    StackNode *temp2;
    StackNode node;
    node.data = 1;
    stack = createLinkedStack();
    pushLS(stack, node);
    pushLS(stack, node);
    pushLS(stack, node);
    temp2 = popLS(stack);
    temp = popLS(stack);
    EXPECT_EQ(temp->data, 1);
    EXPECT_EQ(stack->currentElementCount, 1);
    EXPECT_NE(temp, nullptr);
    deleteLinkedStack(stack);
    free(temp);
    free(temp2);
}

TEST(peekLS, when_StackIsEmpty_expect_FALSE) {
    stack = nullptr;
    EXPECT_EQ(peekLS(stack), nullptr);
    stack = createLinkedStack();
    EXPECT_EQ(peekLS(stack), nullptr);
    deleteLinkedStack(stack);
}

TEST(peekLS, when_StackIsEmpty_expect_TRUE) {
    StackNode *temp;
    StackNode node;
    node.data = 1;
    stack = createLinkedStack();
    pushLS(stack, node);
    temp = peekLS(stack);
    EXPECT_EQ(temp->data, 1);
    EXPECT_EQ(stack->currentElementCount, 1);
    EXPECT_NE(temp, nullptr);
    deleteLinkedStack(stack);
}

TEST(LinkedStackEmpty, when_StackIsNotEmpty_expect_0) {
    StackNode *temp;
    StackNode node;
    node.data = 1;
    stack = createLinkedStack();
    pushLS(stack, node);
    EXPECT_EQ(isLinkedStackEmpty(stack), 0);
    deleteLinkedStack(stack);
}

TEST(LinkedStackEmpty, when_StackIsEmpty_expect_1) {
    stack = createLinkedStack();
    EXPECT_EQ(isLinkedStackEmpty(stack), 1);
    deleteLinkedStack(stack);
}

TEST(leaksTest, logs) { system("leaks test > logs"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}