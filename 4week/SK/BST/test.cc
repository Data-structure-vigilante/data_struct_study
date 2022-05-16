#include "../treeTraversal.h"
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

TEST(AddTest, add9ElementsAndPrintTest) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 100;
    tree = makeBinTree(node);

    // insert
    node.pLeftChild = NULL;
    node.pRightChild = NULL;

    node.data = 50;
    addTreeData(tree, node);
    node.data = 200;
    addTreeData(tree, node);
    node.data = 25;
    addTreeData(tree, node);
    node.data = 75;
    addTreeData(tree, node);
    node.data = 120;
    addTreeData(tree, node);
    node.data = 220;
    addTreeData(tree, node);
    node.data = 110;
    addTreeData(tree, node);
    node.data = 130;
    addTreeData(tree, node);

    preorderTraversal(tree->pRootNode, printNode);
    deleteBinTree(tree);
}

TEST(Remove, remove200) {
    BinTree *tree;
    BinTreeNode node;

    node.data = 100;
    tree = makeBinTree(node);

    // insert
    node.pLeftChild = NULL;
    node.pRightChild = NULL;

    node.data = 50;
    addTreeData(tree, node);
    node.data = 200;
    addTreeData(tree, node);
    node.data = 25;
    addTreeData(tree, node);
    node.data = 75;
    addTreeData(tree, node);
    node.data = 120;
    addTreeData(tree, node);
    node.data = 220;
    addTreeData(tree, node);
    node.data = 110;
    addTreeData(tree, node);
    node.data = 130;
    addTreeData(tree, node);

    removeTreeNode(tree, 130);
    removeTreeNode(tree, 100);
    preorderTraversal(tree->pRootNode, printNode);
    deleteBinTree(tree);
}


TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}