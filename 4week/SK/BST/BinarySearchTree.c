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

BinTreeNode *searchParentNode(BinTree *tree, int data) {
    if (tree == NULL)
        return NULL;

    BinTreeNode *pNode;
    BinTreeNode *pNodeParent;
    pNode = tree->pRootNode;
    pNodeParent = pNode;
    while (pNode && pNode->data != data) {
        pNodeParent = pNode;
        if (pNode->data > data) {
            pNode = getLeftChildNodeBT(pNode);
        } else if (pNode->data < data) {
            pNode = getRightChildNodeBT(pNode);
        }
    }
    if (pNode == NULL)
        return NULL;
    return pNodeParent;
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
            pNode = getLeftChildNodeBT(pNode);
        } else if (pNode->data < node.data) {
            pNode = getRightChildNodeBT(pNode);
        }
    }
    if (pNodeParent->data > node.data) {
        insertLeftChildNodeBT(pNodeParent, node);
    } else {
        insertRightChildNodeBT(pNodeParent, node);
    }
    return TRUE;
}
int removeTreeNode(BinTree *tree, int data) {
    if (tree == NULL)
        return FALSE;

    BinTreeNode *pNode;
    BinTreeNode *parent;
    BinTreeNode *tempParent;
    BinTreeNode *temp;
    parent = searchParentNode(tree, data);
    pNode = searchTreeNode(tree, data);
    if (parent == pNode && !parent->pLeftChild && !parent->pRightChild){
        deleteBinTree(tree);
        return TRUE;
    }
    if (parent == NULL)
        return FALSE;
    if (pNode->pLeftChild == NULL && pNode->pRightChild == NULL)
    {
        deleteBinTreeNode(pNode);
        if(data < parent->data)
            parent->pLeftChild = NULL;
        else
            parent->pRightChild = NULL;
    }
    else if (pNode->pLeftChild == NULL || pNode->pRightChild == NULL)
    {
        if (pNode->pLeftChild == NULL)
            temp = pNode->pRightChild;
        else
            temp = pNode->pLeftChild;
        if (data < parent->data)
            parent->pLeftChild = temp;
        else
            parent->pRightChild = temp;
    }
    else
    {
        temp = pNode->pLeftChild;
        tempParent = pNode;
        while (temp->pRightChild)
        {
           tempParent = temp;
           temp = temp->pRightChild;
        }
        if (temp == pNode->pLeftChild)
        {
            pNode->data = temp->data;
            pNode->pLeftChild = temp->pLeftChild;
            free(temp);
        }
        else
        {
            pNode->data = temp->data;
            tempParent->pRightChild = temp->pLeftChild;
            free(temp);
        }
    }
    return TRUE;
}

