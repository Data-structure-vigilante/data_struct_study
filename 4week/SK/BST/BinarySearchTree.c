#include "BinarySearchTree.h"

BinTreeNode *searchTreeNode(BinTree *tree, int data) {
    if (tree == NULL)
        return NULL;

    BinTreeNode *node;
    node = tree->pRootNode;
    while (node && node->data != data) {
        if (node->data > data) {
            node = getLeftChildNodeBT(node);
        } else if (node->data < data) {
            node = getRightChildNodeBT(node);
        }
    }
    return node;
}

int addTreeData(BinTree *tree, BinTreeNode node) {
    if (tree == NULL || searchTreeNode(tree, node.data) != NULL)
        return FALSE;

    BinTreeNode *pNode;
    BinTreeNode *pNodeParent;
    pNode = tree->pRootNode;
    while (pNode) {
        pNodeParent = pNode;
        if (pNode->data > node.data) {
            pNode = getLeftChildNodeBT(node);
        } else if (pNode->data < node.data) {
            pNode = getRightChildNodeBT(node);
        }
    }
    if (pNodeParent->data > node.data) {
        insertLeftChildNodeBT(pNodeParent, node);
    } else {
        insertRightChildNodeBT(pNodeParent, node);
    }
    return TRUE;
}
int removeTreeNode(BinTree *tree, int data) {}
