#include <gtest/gtest.h>
#include "arraylist.h"
#include <stdio.h>

namespace {
TEST(create, negative_int) { EXPECT_EQ(createArrayList(-1), nullptr); };

TEST(create, positive_int) { EXPECT_NE(createArrayList(5), nullptr); };

TEST(create, maximum_int) { EXPECT_NE(createArrayList(2147483647), nullptr); };

TEST(delete, deleteArray) {
    ArrayList *arr = createArrayList(10);
    // deleteArrayList(arr);
    deleteArrayList(arr);

    EXPECT_DEATH(arr->currentElementCount, "DEATH");
    // double free를 잡자.
};

} // namespace
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
