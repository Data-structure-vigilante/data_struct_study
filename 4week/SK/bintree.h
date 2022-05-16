#ifndef _BIN_TREE_
#define _BIN_TREE_

#include <stdio.h>
#include <stdlib.h>

typedef struct BinTreeNodeType {
    int data;
    int visited;
    struct BinTreeNodeType *pLeftChild;
    struct BinTreeNodeType *pRightChild;
} BinTreeNode;

typedef struct BinTreeType {
    struct BinTreeNodeType *pRootNode;
} BinTree;

BinTree *makeBinTree(BinTreeNode rootNode);
BinTreeNode *getRootNodeBT(BinTree *pBinTree);
BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode,
                                   BinTreeNode element);
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode,
                                    BinTreeNode element);
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode);
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode);
void deleteBinTree(BinTree *pBinTree);
void deleteNodeRecursive(BinTreeNode *node);
void deleteBinTreeNode(BinTreeNode *pNode);
BinTreeNode *createNode(BinTreeNode element);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif
