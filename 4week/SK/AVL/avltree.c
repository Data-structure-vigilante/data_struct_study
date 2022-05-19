#include "avltree.h"

static AVLTreeNode *insertRootNode(AVLTree *tree, AVLTreeNode element);
static int isNilNode(AVLTreeNode *node);
static int isLeafNode(AVLTreeNode *node);
static int isRootNode(AVLTreeNode *node);
static int isTimeToInsert(AVLTreeNode *node, AVLTreeNode *newNode);
static int getBalanceFactor(AVLTreeNode *node);
static void updateHeight(AVLTreeNode *node);
static AVLTreeNode *insertRecursive(AVLTreeNode *root, AVLTreeNode newNode,
                                    AVLTreeNode *nilNode);
static AVLTreeNode *insertNode(AVLTreeNode *parent, AVLTreeNode newNode,
                               AVLTreeNode *nilNode);
static void leftBalance(AVLTreeNode *topNode);
static void rightBalance(AVLTreeNode *topNode);
static void rightRotate(AVLTreeNode *top);
static void leftRotate(AVLTreeNode *top);
static int max(int a, int b);
static void changeRootAfterInsert(AVLTree *tree);

AVLTreeNode *insertAVL(AVLTree *tree, AVLTreeNode element) {
    AVLTreeNode *insertNode;

    if (tree == NULL || searchAVL(tree, element.data) != NULL)
        return NULL;
    if (isEmptyAVLTree(tree))
        insertNode = insertRootNode(tree, element);
    else {
        insertNode = insertRecursive(tree->pRootNode, element, tree->nilNode);
        changeRootAfterInsert(tree);
    }
    return insertNode;
}

AVLTreeNode *deleteAVL(AVLTree *tree, int data){};

AVLTreeNode *searchAVL(AVLTree *tree, int data) {
    if (tree == NULL)
        return NULL;

    AVLTreeNode *node;
    node = tree->pRootNode;
    while (!isNilNode(node) && node->data != data) {
        if (node->data > data) {
            node = getLeftChildNodeBT(node);
        } else if (node->data < data) {
            node = getRightChildNodeBT(node);
        }
    }
    if (isNilNode(node))
        return NULL;
    return node;
}

static AVLTreeNode *insertRootNode(AVLTree *tree, AVLTreeNode element) {
    AVLTreeNode *newNode = createNode(element);

    newNode->pParent = tree->nilNode;
    newNode->pLeftChild = tree->nilNode;
    newNode->pRightChild = tree->nilNode;
    newNode->height = 1;
    tree->pRootNode = newNode;
    return newNode;
}

static AVLTreeNode *insertRecursive(AVLTreeNode *root, AVLTreeNode newNode,
                                    AVLTreeNode *nilNode) {

    AVLTreeNode *newLeaf;

    if (isTimeToInsert(root, &newNode)) {
        newLeaf = insertNode(root, newNode, nilNode);
        updateHeight(root);
        return newLeaf;
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
static int isNilNode(AVLTreeNode *node) { return (node == node->pParent); }

static int isRootNode(AVLTreeNode *node) { return isNilNode(node->pParent); }

static int isLeafNode(AVLTreeNode *node) {
    return (isNilNode(node->pLeftChild) && isNilNode(node->pRightChild));
}

static int isTimeToInsert(AVLTreeNode *node, AVLTreeNode *newNode) {
    return ((node->data > newNode->data && isNilNode(node->pLeftChild)) ||
            (node->data < newNode->data && isNilNode(node->pRightChild)));
}

static AVLTreeNode *insertNode(AVLTreeNode *parent, AVLTreeNode newNode,
                               AVLTreeNode *nilNode) {
    newNode.pLeftChild = nilNode;
    newNode.pRightChild = nilNode;
    newNode.height = 1;
    if (parent->data > newNode.data)
        return insertLeftChildNodeBT(parent, newNode);
    else
        return insertRightChildNodeBT(parent, newNode);
}

static void changeRootAfterInsert(AVLTree *tree) {
    AVLTreeNode *newRoot;

    newRoot = tree->pRootNode;
    while (!isRootNode(newRoot))
        newRoot = newRoot->pParent;
    tree->pRootNode = newRoot;
}

static int getBalanceFactor(AVLTreeNode *node) {
    return (node->pLeftChild->height - node->pRightChild->height);
}

static void updateHeight(AVLTreeNode *node) {
    node->height = max(node->pLeftChild->height, node->pRightChild->height) + 1;
}


// utils
static void leftBalance(AVLTreeNode *topNode) {
    if (getBalanceFactor(topNode->pLeftChild) > 0)
        rightRotate(topNode);
    else {
        leftRotate(topNode->pLeftChild);
        rightRotate(topNode);
    }
}

static void rightBalance(AVLTreeNode *topNode) {
    if (getBalanceFactor(topNode->pRightChild) < 0)
        leftRotate(topNode);
    else {
        rightRotate(topNode->pRightChild);
        leftBalance(topNode);
    }
}

static void rightRotate(AVLTreeNode *top) {
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

static void leftRotate(AVLTreeNode *top) {
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

static int max(int num1, int num2) { return (num1 > num2) ? num1 : num2; }
