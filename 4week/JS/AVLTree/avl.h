#ifndef __AVL_H__
#define __AVL_H__

// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>

// An AVL tree node
typedef struct AvlTreeNodeType
{
	int key;
	int height;
	struct AvlTreeNodeType *left;
	struct AvlTreeNodeType *right;
} AvlTreeNode;

typedef struct AvlTreeType
{
	AvlTreeNode *root;
} AvlTree;

AvlTree *createTree();
AvlTreeNode *insertNode(AvlTree *pTree, int key);
AvlTreeNode *deleteNode(AvlTree *pTree, int key);

#endif