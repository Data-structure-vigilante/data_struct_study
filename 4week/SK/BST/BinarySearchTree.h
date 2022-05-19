#if !defined(BINARYSEARCHTREE_HPP)
#define BINARYSEARCHTREE_HPP
#include "../bintree.h"

BinTreeNode *searchTreeNode(BinTree *tree, int data);
int addTreeData(BinTree *tree, BinTreeNode node);
int removeTreeNode(BinTree *tree, int data);

#endif // BINARYSEARCHTREE_HPP