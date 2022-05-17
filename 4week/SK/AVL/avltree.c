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
void leftBalance(AVLTreeNode *topNode){
    if (getBalanceFactor(topNode->pLeftChild) > 0)
        rightRotate(topNode);
    else{
        leftRotate(topNode->pLeftChild);
        rightRotate(topNode);
    }
}

void rightBalance(AVLTreeNode *topNode){
    if (getBalanceFactor(topNode->pRightChild) < 0)
        leftRotate(topNode);
    else{
        rightRotate(topNode->pRightChild);
        leftBalance(topNode);
    }
}

// function rotateRight (root):
//   exchange left subtree with right subtree of left subtree
//   make left subtree a new root
// function rotateLeft (root):
//   exchange right subtree with left subtree of right subtree
//   make right subtree a new root

void rightRotate(AVLTreeNode *top){
    AVLTreeNode *parent;
    AVLTreeNode *middle;
    AVLTreeNode *bottom;

    parent = top->pParent;
    middle = top->pLeftChild;
    bottom = middle->pLeftChild;
    if (top == parent->pLeftChild)
        parent->pLeftChild = middle;
    else
        parent->pRightChild = middle;
    middle->pParent = parent;
    top->pLeftChild = middle->pRightChild;
    middle->pRightChild = top;
    top->pParent = middle;
}

void leftRotate(AVLTreeNode *top){
    AVLTreeNode *parent;
    AVLTreeNode *middle;
    AVLTreeNode *bottom;

    parent = top->pParent;
    middle = top->pRightChild;
    bottom = middle->pRightChild;
    if (top == parent->pLeftChild)
        parent->pLeftChild = middle;
    else
        parent->pRightChild = middle;
    middle->pParent = parent;
    top->pRightChild = middle->pLeftChild;
    middle->pLeftChild = top;
    top->pParent = middle;
}