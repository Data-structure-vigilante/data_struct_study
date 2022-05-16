#include "treeTraversal.h"

void preorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *)) { // V L R
    if (node == NULL)
        return;
    f(node);
    preorderTraversal(node->pLeftChild, f);
    preorderTraversal(node->pRightChild, f);
}
void inorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *)) {
    if (node == NULL)
        return;
    inorderTraversal(node->pLeftChild, f);
    f(node);
    inorderTraversal(node->pRightChild, f);
}

void postorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *)) {
    if (node == NULL)
        return;
    postorderTraversal(node->pLeftChild, f);
    postorderTraversal(node->pRightChild, f);
    f(node);
}

void printNode(BinTreeNode *node) { printf("data: %d\n", node->data); }
