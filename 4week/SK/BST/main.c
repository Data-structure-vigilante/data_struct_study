#include "../treeTraversal.h"
#include "BinarySearchTree.h"

int main() {
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

    removeTreeNode(tree, 200);
    preorderTraversal(tree->pRootNode, printNode);
    deleteBinTree(tree);
}