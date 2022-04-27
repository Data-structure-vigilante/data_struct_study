#include "../../../gtest/include/gtest/gtest.h"
#include "arraylist.h"
#include <stdio.h>

TEST(create, negative_int) { EXPECT_EQ(createArrayList(-1), nullptr); };

TEST(create, positive_int) { EXPECT_NE(createArrayList(5), nullptr); };

TEST(create, maximum_int) { EXPECT_NE(createArrayList(2147483647), nullptr); };

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
