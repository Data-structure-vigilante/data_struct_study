#include "avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static AvlTreeNode* createNode(int key);
static AvlTreeNode* insert(AvlTreeNode* node, int key);
static int getBalance(AvlTreeNode* node);
static int getHeight(AvlTreeNode* node);
static AvlTreeNode* RightRotate(AvlTreeNode* node);
static AvlTreeNode* LeftRotate(AvlTreeNode* node);

AvlTree* createTree() {
	AvlTree* tree;

	tree = (AvlTree*)calloc(1, sizeof(AvlTree));
	if (tree == NULL)
		perror("Tree make fail\n");
	return tree;
}

AvlTreeNode* insertNode(AvlTree* pTree, int key) {
	AvlTreeNode* node;

	if (pTree == NULL) {
		fprintf(stderr, "insert tree is null\n");
		return NULL;
	}

	pTree->root = insert(pTree->root, key);
	return pTree->root;
}

AvlTreeNode* insert(AvlTreeNode* pNode, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = height(node);

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return RightRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

static AvlTreeNode* createNode(int key) {
	AvlTreeNode* node;
	
	node = (AvlTreeNode*)calloc(1, sizeof(AvlTree));
	if (node == NULL) {
		perror("Node make fail\n");
		return NULL;
	}
	node->key = key;
	return node;
}

static AvlTreeNode* insert(AvlTreeNode* node,int key) {
	if (node == NULL)
		return createNode(key);
	
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
		return leftRotate(node);

}

static int getBalance(AvlTreeNode* node) {
	if (node == NULL)
		return 0;
	return getHeight(node->left) - getHeight(node->right);
}

static int getHeight(AvlTreeNode* node) {
	if (node == NULL)
		return 0;
	return 1 + max(getHeight(node->left), getHeight(node->right));
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = height(y);
	x->height = height(x);

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = height(x);
	y->height = height(y);

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key in the subtree rooted
// with node and returns the new root of the subtree.


// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}

/* Driver program to test above function*/
int main()
{
struct Node *root = NULL;

/* Constructing tree given in the above figure */
root = insert(root, 10);
root = insert(root, 20);
root = insert(root, 30);
root = insert(root, 40);
root = insert(root, 50);
root = insert(root, 25);

/* The constructed AVL Tree would be
			30
		/ \
		20 40
		/ \	 \
	10 25 50
*/

printf("Preorder traversal of the constructed AVL"
		" tree is \n");
preOrder(root);

return 0;
}