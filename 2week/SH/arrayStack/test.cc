#include "../../../gtest/include/gtest/gtest.h"
#include "arraystack.h"
#include <stdio.h>
#include <stdlib.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

ArrayStack *stack;

TEST(create, when_create_expect_notNull) {
    stack = createArrayStack(1);
    EXPECT_NE(stack, nullptr);
    free(stack);
};

TEST(create, when_createMinus1_expect_Null) {
    EXPECT_EQ(createArrayStack(0), nullptr);
    EXPECT_EQ(createArrayStack(-1), nullptr);
};

TEST(create, when_createMaxelement1_expect_1) {
    stack = createArrayStack(1);
    EXPECT_EQ(stack->maxElementCount, 1);
    free(stack);
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
    free(stack);
}

TEST(pushLS, when_StackMaxElement_expect_1) {
    StackNode node;
    stack = createArrayStack(1);
    node.data = 0;
    pushLS(stack, node);

    EXPECT_EQ(pushLS(stack, node), 0);
    free(stack);
}

TEST(leaksTest, logs) { system("leaks test > logs"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}