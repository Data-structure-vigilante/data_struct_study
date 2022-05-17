#ifndef __BST_H__
#define __BST_H__

#include "binTree.h"

BinTreeNode* searchTreeNode(BinTree *pBinTree, int data);
BinTreeNode* searchParentNode(BinTree *pBinTree, int data);
int addTreeData(BinTree *tree, BinTreeNode node);
int removeTreeNode(BinTree *tree, int data);

#endif