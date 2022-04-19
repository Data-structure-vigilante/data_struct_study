#include "../../gtest/include/gtest/gtest.h"
#include "arraylist.h"
#include <stdio.h>
namespace {
TEST(arrayList, case1){
    // EXPECT_EQ(2, sum(1, 1));
    // EXPECT_EQ(3, sum(1, 1));
};
TEST(arrayList, case2) {}
} // namespace
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
