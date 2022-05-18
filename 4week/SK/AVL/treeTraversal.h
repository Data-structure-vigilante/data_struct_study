#if !defined(TREETRAVERSAL_HPP)
#define TREETRAVERSAL_HPP

#include "avltree.h"

void preorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *));  // V L R
void inorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *));   // L V R
void postorderTraversal(AVLTreeNode *node, void (*f)(AVLTreeNode *)); // L R V

void printNode(AVLTreeNode *node);

#endif // TREETRAVERSAL_HPP