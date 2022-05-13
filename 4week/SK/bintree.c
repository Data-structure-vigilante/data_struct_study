#include "bintree.h"

BinTree *makeBinTree(BinTreeNode rootNode) {
    BinTree *tree;
    BinTreeNode *node;

    tree = (BinTree *)calloc(1, sizeof(BinTree));
    if (!tree)
        return NULL;
    node = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
    if (!node) {
        free(tree);
        return NULL;
    }
    *node = rootNode;
    node->pLeftChild = NULL;
    node->pRightChild = NULL;
    tree->pRootNode = node;

    return tree;
}
BinTreeNode *getRootNodeBT(BinTree *pBinTree) {
    if (!pBinTree)
        return NULL;
    return pBinTree->pRootNode;
}
BinTreeNode *createNode(BinTreeNode element) {
    BinTreeNode *node;

    node = (BinTreeNode *)calloc(1, sizeof(BinTreeNode));
    if (node == NULL)
        return NULL;
    *node = element;
    return node;
}

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode,
                                   BinTreeNode element) {
    BinTreeNode *new_node;

    if (pParentNode == NULL)
        return NULL;
    new_node = createNode(element);
    if (new_node == NULL)
        return NULL;
    pParentNode->pLeftChild = new_node;
    return new_node;
}
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode,
                                    BinTreeNode element) {
    BinTreeNode *new_node;

    if (pParentNode == NULL)
        return NULL;
    new_node = createNode(element);
    if (new_node == NULL)
        return NULL;
    pParentNode->pRightChild = new_node;
    return new_node;
};

BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL)
        return NULL;
    return pNode->pLeftChild;
};

BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL)
        return NULL;
    return pNode->pRightChild;
}

void deleteBinTree(BinTree *pBinTree) {
    if (pBinTree == NULL)
        return;
    deleteNodeRecursive(pBinTree->pRootNode);
    pBinTree->pRootNode = NULL;
    free(pBinTree);
}

void deleteNodeRecursive(BinTreeNode *node) {
    // 노드 래프트 차일드 지워, 라이트 차일드 지워 , 나 지워
    if (node == NULL)
        return;
    if (node->pLeftChild)
        deleteNodeRecursive(node->pLeftChild);
    if (node->pRightChild)
        deleteNodeRecursive(node->pRightChild);
    deleteBinTreeNode(node);
}

void deleteBinTreeNode(BinTreeNode *pNode) {
    if (pNode == NULL)
        return;
    free(pNode);
}