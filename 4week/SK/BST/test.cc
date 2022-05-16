#include "BinarySearchTree.h"
#include <gtest/gtest.h>
// #include "../../../gtest/include/gtest/gtest.h"

#include <stdio.h>

TEST(searchTreeNode, when_emptyTree_expect_NULL) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 1;

    tree = makeBinTree(node);

    deleteBinTreeNode(getRootNodeBT(tree));
    tree->pRootNode = NULL;
    EXPECT_EQ(searchTreeNode(tree, 1), nullptr);
    deleteBinTree(tree);
};

TEST(searchTreeNode, when_1NodeTree_expect_node) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 1;

    tree = makeBinTree(node);
    EXPECT_EQ(searchTreeNode(tree, 1), getRootNodeBT(tree));
    EXPECT_EQ(searchTreeNode(tree, 2), nullptr);
    deleteBinTree(tree);
};

TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}