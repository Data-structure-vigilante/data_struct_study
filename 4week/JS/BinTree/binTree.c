#include "binTree.h"
#include <stdlib.h>
#include <stdio.h>

static void deletePostOrder(BinTreeNode* pNode);

BinTree* makeBinTree(BinTreeNode rootNode) {
	BinTree* tree;
	BinTreeNode *node;

	tree = (BinTree*)calloc(1, sizeof(BinTree));
	if (tree == NULL)
		perror("Tree memory allocate fail\n");
	node = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	if (node == NULL)
		perror("Root Node allocate fail\n");
	*node = rootNode;
	tree->pRootNode = node;
	return tree;
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree) {
	if (pBinTree == NULL) {
		fprintf(stderr, "pBinTree address is null\n");
		return NULL;
	}
	return pBinTree->pRootNode;
}

BinTreeNode* createNode(BinTreeNode element) {
	BinTreeNode* node;

	node = (BinTreeNode*)calloc(1, sizeof(BinTreeNode));
	if (node == NULL) {
		perror("Node allocate fail\n");
		return NULL;
	}
	*node = element;
	return node;
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	if (pParentNode == NULL) {
		fprintf(stderr, "pParentNode address is null\n");
		return NULL;
	}
	pParentNode->pLeftChild = createNode(element);
	if (pParentNode->pLeftChild == NULL) {
		perror("Left Node allocate fail\n");
		return NULL;
	}
	return pParentNode->pLeftChild;
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element) {
	if (pParentNode == NULL) {
		fprintf(stderr, "pParentNode address is null\n");
		return NULL;
	}
	pParentNode->pRightChild = createNode(element);
	if (pParentNode->pRightChild == NULL) {
		perror("Left Node allocate fail\n");
		return NULL;
	}
	return pParentNode->pRightChild;
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return NULL;
	}
	return pNode->pLeftChild;
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return NULL;
	}
	return pNode->pRightChild;
}

void deleteBinTree(BinTree* pBinTree) {
	if (pBinTree == NULL) {
		fprintf(stderr, "pBinTree address is null\n");
		return;
	}
	deletePostOrder(pBinTree->pRootNode);
	pBinTree->pRootNode = NULL;
	free(pBinTree);
}

static void deletePostOrder(BinTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return;
	}

	if (pNode->pLeftChild)
		deletePostOrder(pNode->pLeftChild);
	if (pNode->pRightChild != NULL)
		deletePostOrder(pNode->pRightChild);
	deleteBinTreeNode(pNode);
}

void preOrder(BinTreeNode* pNode) {
	printf("data : %c\n", pNode->data);
}

void inOrder(BinTreeNode* pNode) {

}

void postOrder(BinTreeNode* pNode) {

}

void deleteBinTreeNode(BinTreeNode* pNode) {
	if (pNode == NULL) {
		fprintf(stderr, "pNode address is null\n");
		return;
	}
	free(pNode);
}