#include "../../../gtest/include/gtest/gtest.h"
#include "arraystack.h"
#include <stdio.h>
#include <stdlib.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

ArrayStack *stack;

TEST(create, when_create_expect_notNull) {
    stack = createArrayStack(1);
    EXPECT_NE(stack, nullptr);
    deleteArrayStack(stack);
};

TEST(create, when_createMinus1_expect_Null) {
    EXPECT_EQ(createArrayStack(0), nullptr);
    EXPECT_EQ(createArrayStack(-1), nullptr);
};

TEST(create, when_createMaxelement1_expect_1) {
    stack = createArrayStack(1);
    EXPECT_EQ(stack->maxElementCount, 1);
    deleteArrayStack(stack);
};

TEST(pushLS, when_NullStack_expect_minus1) {
    StackNode node;
    stack = nullptr;
    // stack = createArrayStack(1);
    node.data = 0;

    EXPECT_EQ(pushLS(stack, node), -1);
}

TEST(pushLS, when_StackNotMaxElement_expect_1) {
    StackNode node;
    stack = createArrayStack(1);
    node.data = 0;

    EXPECT_EQ(pushLS(stack, node), 1);
    deleteArrayStack(stack);
}

TEST(pushLS, when_StackMaxElement_expect_1) {
    StackNode node;
    stack = createArrayStack(1);
    node.data = 0;
    pushLS(stack, node);

    EXPECT_EQ(pushLS(stack, node), 0);
    deleteArrayStack(stack);
}

TEST(popLS, when_StackIsEmpty_expect_FALSE) {
    stack = createArrayStack(1);
    EXPECT_EQ(popLS(stack), nullptr);
    deleteArrayStack(stack);
}

TEST(popLS, when_StackIsNotEmpty_expect_TRUE) {
    StackNode*  temp;
    StackNode    node;
    node.data = 1;
    stack = createArrayStack(1);
    pushLS(stack, node);
    temp = popLS(stack);
    EXPECT_EQ(temp->data, 1);
    EXPECT_EQ(stack->currentElementCount, 0);
    EXPECT_NE(temp, nullptr);
    deleteArrayStack(stack);
}

TEST(peekLS, when_StackIsEmpty_expect_FALSE) {
    stack = nullptr;
    EXPECT_EQ(peekLS(stack), nullptr);
    stack = createArrayStack(1);
    EXPECT_EQ(peekLS(stack), nullptr);
    deleteArrayStack(stack);
}

TEST(peekLS, when_StackIsEmpty_expect_TRUE) {
    StackNode*  temp;
    StackNode    node;
    node.data = 1;
    stack = createArrayStack(1);
    pushLS(stack, node);
    temp = peekLS(stack);
    EXPECT_EQ(temp->data, 1);
    EXPECT_EQ(stack->currentElementCount, 1);
    EXPECT_NE(temp, nullptr);
    deleteArrayStack(stack);
}

TEST(ArrayStackFull, when_StackIsNotFull_expect_0) {
    stack = createArrayStack(1);
    EXPECT_EQ(isArrayStackFull(stack), 0);
    deleteArrayStack(stack);
}

TEST(ArrayStackFull, when_StackIsFull_expect_1) {
    StackNode*  temp;
    StackNode    node;
    node.data = 1;
    stack = createArrayStack(1);
    pushLS(stack, node);
    EXPECT_EQ(isArrayStackFull(stack), 1);
    deleteArrayStack(stack);
}

TEST(ArrayStackEmpty, when_StackIsNotEmpty_expect_0) {
    StackNode*  temp;
    StackNode    node;
    node.data = 1;
    stack = createArrayStack(1);
    pushLS(stack, node);
    EXPECT_EQ(isArrayStackEmpty(stack), 0);
    deleteArrayStack(stack);
}

TEST(ArrayStackEmpty, when_StackIsEmpty_expect_1) {
    stack = createArrayStack(1);
    EXPECT_EQ(isArrayStackEmpty(stack), 1);
    deleteArrayStack(stack);
}

TEST(leaksTest, logs) { system("leaks test > logs"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}