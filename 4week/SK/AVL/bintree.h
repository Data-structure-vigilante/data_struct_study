#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdio.h>
#include <stdlib.h>

typedef enum BoolType {
    FALSE,
    TRUE
} Bool;

typedef struct AVLTreeNodeType {
    int height;
    int data;
    struct AVLTreeNodeType *pParent;
    struct AVLTreeNodeType *pLeftChild;
    struct AVLTreeNodeType *pRightChild;
} AVLTreeNode;

typedef struct AVLTreeType {
    struct AVLTreeNodeType *nilNode;
    struct AVLTreeNodeType *pRootNode;
} AVLTree;

AVLTree *makeAVLTree();
AVLTreeNode *getRootNodeBT(AVLTree *pAVLTree);
AVLTreeNode *insertLeftChildNodeBT(AVLTreeNode *pParentNode,
                                   AVLTreeNode element);
AVLTreeNode *insertRightChildNodeBT(AVLTreeNode *pParentNode,
                                    AVLTreeNode element);
AVLTreeNode *getLeftChildNodeBT(AVLTreeNode *pNode);
AVLTreeNode *getRightChildNodeBT(AVLTreeNode *pNode);
void deleteAVLTree(AVLTree *pAVLTree);
void deleteNodeRecursive(AVLTreeNode *node);
void deleteAVLTreeNode(AVLTreeNode *pNode);
AVLTreeNode *createNode(AVLTreeNode element);
Bool isEmptyAVLTree(AVLTree *tree);

#endif
