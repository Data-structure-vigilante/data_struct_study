#include "bst.h"
#include <stdlib.h>

BinTreeNode *insertBST(BinTree *pBinTree, BinTreeNode element)
{

	BinTreeNode *node;
	node = pBinTree->pRootNode;

	if (node == NULL)
	{
		node = createNode(element);
		return (node);
	}

	while (node != NULL)
	{
		if (node->data > element.data)
			if (node->pLeftChild == NULL)
			{
				node = createNode(element);
				return (node);
			}
			else
				node = node->pLeftChild;
		else if (node->data < element.data)
			if (node->pRightChild == NULL)
			{
				node = createNode(element);
				return (node);
			}
			else
				node = node->pRightChild;
		else
			break;
	}
	return (NULL);
}

BinTreeNode *searchBST(BinTree *pBinTree, char key)
{
	BinTreeNode *result;

	if (pBinTree == NULL)
		return (NULL);
	result = pBinTree->pRootNode;
	while (result != NULL)
	{
		if (key == result->data)
		{
			break;
		}
		else if (key < result->data)
		{
			result = result->pLeftChild;
		}
		else
		{
			result = result->pRightChild;
		}
	}
	return result;
}

BinTreeNode *deleteBST(BinTree *BinTree, BinTreeNode element)
{
	BinTreeNode *parentNode;
	BinTreeNode *childNode;

	if (BinTree == NULL)
		return (NULL);
	parentNode = BinTree->pRootNode;
	childNode = BinTree->pRootNode;

	while (childNode != NULL)
	{
		if (childNode->data == element.data)
			break;
		else if (childNode->data > element.data)
		{
			parentNode = childNode;
			childNode = childNode->pLeftChild;
		}
		else if (childNode->data < element.data)
		{
			parentNode = childNode;
			childNode = childNode->pRightChild;
		}
	}
	if (childNode->pLeftChild == NULL && childNode->pRightChild == NULL)
	{
		if (parentNode->pLeftChild == childNode)
			parentNode->pLeftChild == NULL;
		else
			parentNode->pRightChild == NULL;
	}
	else if (childNode->pLeftChild && childNode->pRightChild)
	{
		BinTreeNode *node;
		BinTreeNode *childLeftNode;
		BinTreeNode *childRightNode;
		BinTreeNode *subtreeParent;

		childLeftNode = childNode->pLeftChild;
		childRightNode = childNode->pRightChild;
		node = childRightNode;
		subtreeParent = NULL;
		while (node->pLeftChild != NULL)
		{
			subtreeParent = node;
			node = node->pLeftChild;
		}
		if (parentNode->pLeftChild == childNode)
			parentNode->pLeftChild = node;
		else
			parentNode->pRightChild = node;
		node->pLeftChild = childLeftNode;
		while (node->pRightChild != NULL)
			node = node->pRightChild;
		node->pRightChild = childRightNode;
		subtreeParent->pLeftChild = NULL;
		return (childNode);
	}
	else
	{
		BinTreeNode *node;

		if (childNode->pLeftChild)
			node = childNode->pLeftChild;
		else
			node = childNode->pRightChild;
		if (parentNode->pLeftChild == childNode)
			parentNode->pLeftChild = node;
		else
			parentNode->pRightChild = node;
		return (childNode);
	}
}