#include "bintree.h"

// ​ typedef struct BinTreeNodeType {
//     char data;
//     int visited;
//     struct BinTreeNodeType *pLeftChild;
//     struct BinTreeNodeType *pRightChild;
// } BinTreeNode;
// typedef struct BinTreeType {
//     struct BinTreeNodeType *pRootNode;
// } BinTree;
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
    tree->pRootNode = node;
    return tree;
}
BinTreeNode *getRootNodeBT(BinTree *pBinTree) {
    if (!pBinTree)
        return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode,
                                   BinTreeNode element);
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode,
                                    BinTreeNode element);
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode);
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode);
void deleteBinTree(BinTree *pBinTree);
void deleteBinTreeNode(BinTreeNode *pNode);