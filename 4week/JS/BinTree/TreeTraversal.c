#include "TreeTraversal.h"
#include <stdlib.h>

void preorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	fp(pNode);
	preorderTraversal(pNode->pLeftChild, fp);
	preorderTraversal(pNode->pRightChild, fp);
}

void inorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	inorderTraversal(pNode->pLeftChild, fp);
	fp(pNode);
	inorderTraversal(pNode->pRightChild, fp);
}

void postorderTraversal(BinTreeNode* pNode, void (*fp)(BinTreeNode*)) {
	if (pNode == NULL)
		return;
	postorderTraversal(pNode->pLeftChild, fp);
	postorderTraversal(pNode->pRightChild, fp);
	fp(pNode);
}