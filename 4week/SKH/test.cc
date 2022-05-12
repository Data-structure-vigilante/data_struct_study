#include "bintree.h"
#include <gtest/gtest.h>
// #include "../../../gtest/include/gtest/gtest.h"

#include <stdio.h>

TEST(makeBinTree, when_makeBinTree_expect_true) {
    BinTree *tree;
    BinTreeNode node;
    node.data = 10;
    tree = makeBinTree(node);
    EXPECT_NE(tree, nullptr);

    EXPECT_NE(tree->pRootNode->data, 1);
    EXPECT_EQ(tree->pRootNode->data, 10);
    free(tree->pRootNode);
    free(tree);
}

TEST(getRootNodeBT, when_EmptyTree_expext_nullptr) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 10;
    tree = makeBinTree(node);
    free(tree->pRootNode);
    tree->pRootNode = NULL;

    EXPECT_EQ(getRootNodeBT(tree), nullptr);
    free(tree);
}

TEST(getRootNodeBT, when_NotEmptyTree_expext_rootNode) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 10;
    tree = makeBinTree(node);

    EXPECT_NE(getRootNodeBT(tree), nullptr);
    EXPECT_EQ(getRootNodeBT(tree)->data, 10);
    free(tree->pRootNode);
    free(tree);
}

TEST(deleteBinTree, when_notEmptyTree_expext_empty) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 10;
    tree = makeBinTree(node);
    deleteBinTree(tree);
    EXPECT_EQ(getRootNodeBT(tree)->data, nullptr);
}

TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}