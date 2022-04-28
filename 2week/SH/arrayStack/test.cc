#include "../../../gtest/include/gtest/gtest.h"
#include "arraystack.h"
#include <stdio.h>

// testCaseName When_StateUnderTest_Expect_ExpectedBehavior

TEST(create, must_success) { EXPECT_NE(createArrayStack(), nullptr); };

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}