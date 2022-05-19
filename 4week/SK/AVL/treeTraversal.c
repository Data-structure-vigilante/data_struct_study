#include "treeTraversal.h"

void preorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *)) { // V L R
    if (node == NULL)
        return;
    f(node);
    preorderTraversal(node->pLeftChild, f);
    preorderTraversal(node->pRightChild, f);
}
void inorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *)) {
    if (node == NULL)
        return;
    inorderTraversal(node->pLeftChild, f);
    f(node);
    inorderTraversal(node->pRightChild, f);
}

void postorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *)) {
    if (node == NULL)
        return;
    postorderTraversal(node->pLeftChild, f);
    postorderTraversal(node->pRightChild, f);
    f(node);
}

void printNode(AVLTreeNode *node) { printf("data: %d\n", node->data); }
