#include "avltree.h"

static void insertRootNode(AVLTree *tree, AVLTreeNode element)
{
    tree->pRootNode = createNode(element);
    tree->pRootNode->pParent = tree->nilNode;
    tree->pRootNode->pLeftChild = tree->nilNode;
    tree->pRootNode->pRightChild = tree->nilNode;
}

// 삽입
AVLTreeNode *insertAVL(AVLTree *tree, AVLTreeNode element) {
    if (tree == NULL)
    return  NULL;
    if (isEmptyAVLTree(tree))
        return insertRootNode(tree, element);
    else
        return insertRecursive(tree->pRootNode, element, tree->nilNode);
}

Bool isNilNode(AVLTreeNode *node) { return (node == node->pParent); }

Bool isLeafNode(AVLTreeNode *node) {
    return (isNilNode(node->pLeftChild) && isNilNode(node->pRightChild));
}

int isTimeToInsert(AVLTreeNode *node, AVLTreeNode *newNode) {
    return ((node->data > newNode->data && isNilNode(node->pLeftChild)) ||
            (node->data < newNode->data && isNilNode(node->pRightChild)));
}

static AVLTreeNode *insertNode(AVLTreeNode *parent, AVLTreeNode newNode,
                       AVLTreeNode *nilNode) {
    newNode.pLeftChild = nilNode;
    newNode.pRightChild = nilNode;
    newNode.height = 1;
    if (isNilNode(parent->pLeftChild))
        return insertLeftChildNodeBT(parent, newNode);
    else
        return insertRightChildNodeBT(parent, newNode);
}

int getBalanceFactor(AVLTreeNode *node) {
    return (node->pLeftChild->height - node->pRightChild->height);
}

void updateHeight(AVLTreeNode *node) {
	node->height = max(node->pLeftChild->height, node->pRightChild->height) + 1;
}

static AVLTreeNode *insertRecursive(AVLTreeNode *root, AVLTreeNode newNode,
                            AVLTreeNode *nilNode) {

    AVLTreeNode *newLeaf;

    if (isTimeToInsert(root, &newNode)) {
        return insertNode(root, newNode, nilNode);
    }
    if (newNode.data < root->data) {
        newLeaf = insertRecursive(root->pLeftChild, newNode, nilNode);
        updateHeight(root);
        if (getBalanceFactor(root) > 1)
            leftBalance(root);
    } else {
        newLeaf = insertRecursive(root->pRightChild, newNode, nilNode);
        updateHeight(root);
        if (getBalanceFactor(root) < -1)
            rightBalance(root);
    }
    return newLeaf;
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
    updateHeight(middle->pLeftChild);
    updateHeight(middle->pRightChild);
    updateHeight(middle);
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
    updateHeight(middle->pLeftChild);
    updateHeight(middle->pRightChild);
    updateHeight(middle);
}