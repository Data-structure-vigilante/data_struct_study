#ifndef __TREETRAVERSAL_H__
#define __TREETRAVERSAL_H__
#include "binTree.h"

void preorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*));
void inorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*));
void postorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*));

#endif