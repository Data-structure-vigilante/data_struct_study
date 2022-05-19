#include "avltree.h"
#include <gtest/gtest.h>
#include <stdio.h>

TEST(Insert, oneToTen) {
    AVLTree *tree = makeAVLTree();
    AVLTreeNode element;

    for (int i = 1; i <= 9; ++i) {
        element.data = i;
        insertAVL(tree, element);
    }
    EXPECT_EQ(searchAVL(tree, 1)->height, 1);
    EXPECT_EQ(searchAVL(tree, 2)->height, 2);
    EXPECT_EQ(searchAVL(tree, 3)->height, 1);
    EXPECT_EQ(searchAVL(tree, 4)->height, 4);
    EXPECT_EQ(searchAVL(tree, 5)->height, 1);
    EXPECT_EQ(searchAVL(tree, 6)->height, 3);
    EXPECT_EQ(searchAVL(tree, 7)->height, 1);
    EXPECT_EQ(searchAVL(tree, 8)->height, 2);
    EXPECT_EQ(searchAVL(tree, 9)->height, 1);
}

// TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}