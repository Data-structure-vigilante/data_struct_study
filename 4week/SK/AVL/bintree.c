#include "AVLTree.h"

AVLTree *makeAVLTree() {
    AVLTree *tree;
    AVLTreeNode *nilNode;

    tree = (AVLTree *)calloc(1, sizeof(AVLTree));
    if (!tree)
        return NULL;

    nilNode = (AVLTreeNode *)calloc(1, sizeof(AVLTreeNode));
    if (!nilNode) {
        free(tree);
        return NULL;
    }

    nilNode->pLeftChild = nilNode;
    nilNode->pRightChild = nilNode;
    nilNode->pParent = nilNode;
    tree->nilNode = nilNode;
    tree->pRootNode = nilNode;

    return tree;
}

int isSameNode(AVLTreeNode *aNode, AVLTreeNode *bNode) {
    return (aNode == bNode);
}

AVLTreeNode *getRootNodeBT(AVLTree *pAVLTree) {
    if (!pAVLTree)
        return NULL;
    if (isSameNode(pAVLTree->nilNode, pAVLTree->pRootNode))
        return NULL;
    return pAVLTree->pRootNode;
}

AVLTreeNode *createNode(AVLTreeNode element) {
    AVLTreeNode *node;

    node = (AVLTreeNode *)calloc(1, sizeof(AVLTreeNode));
    if (node == NULL)
        return NULL;
    *node = element;
    return node;
}

AVLTreeNode *insertLeftChildNodeBT(AVLTreeNode *pParentNode,
                                   AVLTreeNode element) {
    AVLTreeNode *new_node;

    if (pParentNode == NULL)
        return NULL;
    new_node = createNode(element);
    if (new_node == NULL)
        return NULL;
    pParentNode->pLeftChild = new_node;
    new_node->pParent = pParentNode;
    return new_node;
}
AVLTreeNode *insertRightChildNodeBT(AVLTreeNode *pParentNode,
                                    AVLTreeNode element) {
    AVLTreeNode *new_node;

    if (pParentNode == NULL)
        return NULL;
    new_node = createNode(element);
    if (new_node == NULL)
        return NULL;
    pParentNode->pRightChild = new_node;
    new_node->pParent = pParentNode;
    return new_node;
};

AVLTreeNode *getLeftChildNodeBT(AVLTreeNode *pNode) {
    if (pNode == NULL)
        return NULL;
    return pNode->pLeftChild;
};

AVLTreeNode *getRightChildNodeBT(AVLTreeNode *pNode) {
    if (pNode == NULL)
        return NULL;
    return pNode->pRightChild;
}

void deleteAVLTree(AVLTree *pAVLTree) {
    if (pAVLTree == NULL)
        return;
    deleteNodeRecursive(pAVLTree->pRootNode);
    pAVLTree->pRootNode = NULL;
    free(pAVLTree);
}

void deleteNodeRecursive(AVLTreeNode *node) {
    // 노드 래프트 차일드 지워, 라이트 차일드 지워 , 나 지워
    if (node == NULL)
        return;
    if (node->pLeftChild)
        deleteNodeRecursive(node->pLeftChild);
    if (node->pRightChild)
        deleteNodeRecursive(node->pRightChild);
    deleteAVLTreeNode(node);
}

void deleteAVLTreeNode(AVLTreeNode *pNode) {
    if (pNode == NULL)
        return;
    free(pNode);
}