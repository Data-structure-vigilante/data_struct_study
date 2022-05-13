#if !defined(TREETRAVERSAL_HPP)
#define TREETRAVERSAL_HPP

#include "bintree.h"

void preorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *));  // V L R
void inorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *));   // L V R
void postorderTraversal(BinTreeNode *node, void (*f)(BinTreeNode *)); // L R V

void printNode(BinTreeNode *node);

#endif // TREETRAVERSAL_HPP