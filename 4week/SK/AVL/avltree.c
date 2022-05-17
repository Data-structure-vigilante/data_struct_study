#include "avltree.h"

// 삽입
AVLTreeNode *insertAVL(AVLTree *tree, AVLTreeNode element) {}

Bool isNilNode(AVLTreeNode *node) { return (node == node->pParent); }

Bool isLeafNode(AVLTreeNode *node) {
    return (isNilNode(node->pLeftChild) && isNilNode(node->pRightChild));
}

int isTimeToInsert(AVLTreeNode *node, AVLTreeNode *newNode) {
    return ((node->data > newNode->data && isNilNode(node->pLeftChild)) ||
            (node->data < newNode->data && isNilNode(node->pRightChild)));
}

static void insertNode(AVLTreeNode *parent, AVLTreeNode newNode,
                       AVLTreeNode *nilNode) {
    newNode.pLeftChild = nilNode;
    newNode.pRightChild = nilNode;
    newNode.height = 1;
    if (isNilNode(parent->pLeftChild))
        insertLeftChildNodeBT(parent, newNode);
    else
        insertRightChildNodeBT(parent, newNode);
}

int getBalanceFactor(AVLTreeNode *node) {
    return (node->pLeftChild->height - node->pRightChild->height);
}

void updateHeight(AVLTreeNode *node) {
	node->height = max(node->pLeftChild->height, node->pRightChild->height) + 1;
}

static void insertRecursive(AVLTreeNode *root, AVLTreeNode newNode,
                            AVLTreeNode *nilNode) {

    if (isTimeToInsert(root, &newNode)) {
        insertNode(root, newNode, nilNode);
        return root;
    }
    if (newNode.data < root->data) {
        insertRecursive(root->pLeftChild, newNode, nilNode);
        updateHeight(root);
        if (getBalanceFactor(root) > 1)
            leftBalance(root);
    } else {
        insertRecursive(root->pRightChild, newNode, nilNode);
        updateHeight(root);
        if (getBalanceFactor(root) < -1)
            rightBalance(root);
    }
    return root;
}
// 삭제
AVLTreeNode *deleteAVL(AVLTree *tree, int data);

// 검색
AVLTreeNode *searchAVL(AVLTree *tree, int data);

// utils
void leftBalance();
void rightBalance();
Bool rightRotate();
Bool leftRotate();