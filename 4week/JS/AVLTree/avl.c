#include "avl.h"
#include <stdlib.h>
#include <stdio.h>

static AvlTreeNode *createNode(int key);
static AvlTreeNode *insert(AvlTreeNode *node, int key);
static AvlTreeNode *remove (AvlTreeNode *root, int key);
static int getBalance(AvlTreeNode *node);
static int getHeight(AvlTreeNode *node);
static AvlTreeNode *RightRotate(AvlTreeNode *node);
static AvlTreeNode *LeftRotate(AvlTreeNode *node);
static AvlTreeNode *minValueNode(AvlTreeNode *node);
static AvlTreeNode *search(AvlTreeNode *node, int key);
static void deleteBinTreeNode(AvlTreeNode* pNode);
static void deletePostOrder(AvlTreeNode *pNode);
static int max(int a, int b);

AvlTree *createTree()
{
	AvlTree *tree;

	tree = (AvlTree *)calloc(1, sizeof(AvlTree));
	if (tree == NULL)
		perror("Tree make fail\n");
	return tree;
}

AvlTreeNode *insertNode(AvlTree *pTree, int key)
{
	AvlTreeNode *node;

	if (pTree == NULL)
	{
		fprintf(stderr, "insert tree is null\n");
		return NULL;
	}

	pTree->root = insert(pTree->root, key);
	return pTree->root;
}

static AvlTreeNode *insert(AvlTreeNode *node, int key)
{
	if (node == NULL) {
		node = createNode(key);
		node->height = 1;
		return node;
	}

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	node->height = getHeight(node);

	int balance = getBalance(node);

	// LL Case
	if (balance > 1 && key < node->left->key)
		return RightRotate(node);
	// LR Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = LeftRotate(node->left);
		return RightRotate(node);
	}
	// RR Case
	if (balance < -1 && key > node->right->key)
		return LeftRotate(node);
	// RL Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = RightRotate(node->right);
		return LeftRotate(node);
	}
	return node;
}

AvlTreeNode *deleteNode(AvlTree *pTree, int key)
{
	AvlTreeNode *node;

	if (pTree == NULL)
	{
		fprintf(stderr, "delete tree is null\n");
		return NULL;
	}

	pTree->root = insert(pTree->root, key);
	return pTree->root;
}

static AvlTreeNode *remove(AvlTreeNode *root, int key)
{
	if (root = NULL)
		return root;
	if (key < root->key)
		root->left = remove(root->left, key);
	else if (key > root->key)
		root->right = remove(root->right, key);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			AvlTreeNode *child;

			child = root->left ? root->left : root->right;

			if (child == NULL)
			{
				child = root;
				root = NULL;
			}
			else
				*root = *child;
			free(child);
		}
		else
		{
			AvlTreeNode *minNode;

			minNode = minValueNode(root->right);
			root->key = minNode->key;
			root->right = remove(root->right, minNode->key);
		}
	}
	if (root == NULL)
		return root;
	root->height = getHeight(root);

	int balance = getBalance(root);

	// LL Case
	if (balance > 1 && key < root->left->key)
		return RightRotate(root);
	// LR Case
	if (balance > 1 && key > root->left->key)
	{
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}
	// RR Case
	if (balance < -1 && key > root->right->key)
		return LeftRotate(root);
	// RL Case
	if (balance < -1 && key < root->right->key)
	{
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}
	return root;
}

AvlTreeNode *searchNode(AvlTree *pTree, int key)
{
	if (pTree == NULL)
	{
		fprintf(stderr, "delete tree is null\n");
		return NULL;
	}

	return (search(pTree->root, key));
}

static AvlTreeNode *search(AvlTreeNode *node, int key)
{
	if (node == NULL)
		return node;
	if (key < node->key)
		return (search(node->left, key));
	else if (key > node->key)
		return (search(node->right, key));
	else
		return node;
}

void deleteTree(AvlTree *pTree) {
	if (pTree == NULL) {
		fprintf(stderr, "pTree address is null\n");
		return;
	}
	deletePostOrder(pTree->root);
	pTree->root = NULL;
	free(pTree);
}

static void deleteBinTreeNode(AvlTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return;
	}
	free(pNode);
}

static void deletePostOrder(AvlTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return;
	}

	if (pNode->left != NULL)
		deletePostOrder(pNode->left);
	if (pNode->right != NULL)
		deletePostOrder(pNode->right);
	deleteBinTreeNode(pNode);
}

static AvlTreeNode *createNode(int key)
{
	AvlTreeNode *node;

	node = (AvlTreeNode *)calloc(1, sizeof(AvlTreeNode));
	if (node == NULL)
	{
		perror("Node make fail\n");
		return NULL;
	}
	node->key = key;
	return node;
}

static int getBalance(AvlTreeNode *node)
{
	if (node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

static int getHeight(AvlTreeNode *node)
{
	if (node == NULL)
		return 0;
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

static AvlTreeNode *RightRotate(AvlTreeNode *grandparent)
{
	AvlTreeNode *parent;
	AvlTreeNode *child;

	parent = grandparent->left;
	child = parent->right;
	parent->right = grandparent;
	grandparent->left = child;

	grandparent->height = getHeight(grandparent);
	parent->height = getHeight(parent);
	return (parent);
}

static AvlTreeNode *LeftRotate(AvlTreeNode *grandparent)
{
	AvlTreeNode *parent;
	AvlTreeNode *child;

	parent = grandparent->right;
	child = parent->left;
	parent->left = grandparent;
	grandparent->right = child;

	grandparent->height = getHeight(grandparent);
	parent->height = getHeight(parent);
	return (parent);
}

static AvlTreeNode *minValueNode(AvlTreeNode *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

static int max(int a, int b) {
	int v;

	v = a > b ? a : b;
	return v;
}