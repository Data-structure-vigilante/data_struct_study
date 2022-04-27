#include <gtest/gtest.h>
#include <stdio.h>
#include "circularlist.h"

CircularList* test;
CircularListNode temp = {0, NULL, NULL};

TEST(create, create_list) {
    test = createCircularList();
    EXPECT_NE(test, nullptr);
}

TEST(add_invalid, pList_is_NULL) {
    EXPECT_EQ(addCLElement(NULL, 10, temp), -1);
}

TEST(add_invalid, position_negative) {
    EXPECT_EQ(addCLElement(test, -1, temp), -1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}