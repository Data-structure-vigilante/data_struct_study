#include "bintree.h"
#include "treeTraversal.h"
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

TEST(PreorderTraversal, Print_preorder) {
    BinTree *tree;
    BinTreeNode node;

    node.pLeftChild = NULL;
    node.pRightChild = NULL;

    node.data = 1;
    tree = makeBinTree(node);
    node.data = 2;
    BinTreeNode *left = insertLeftChildNodeBT(tree->pRootNode, node);
    node.data = 3;
    insertLeftChildNodeBT(left, node);
    node.data = 4;
    insertRightChildNodeBT(left, node);
    node.data = 5;
    insertRightChildNodeBT(tree->pRootNode, node);

    printf("------ preorder -------\n");
    preorderTraversal(tree->pRootNode, printNode);
    printf("------ inorder -------\n");
    inorderTraversal(tree->pRootNode, printNode);
    printf("------ postorder -------\n");
    postorderTraversal(tree->pRootNode, printNode);
}

TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}