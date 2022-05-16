#include "bst.h"
#include <stdlib.h>

BinTreeNode* insertBST(BinTree* pBinTree, BinTreeNode element) {
}

BinTreeNode* searchBST(BinTree* pBinTree, char key) {
	BinTreeNode* result;

	result = pBinTree->pRootNode;
	while (result != NULL) {
		if (key == result->data) {
			break;
		}
		else if (key < result->data) {
			result = result->pLeftChild;
		}
		else {
			result = result->pRightChild;
		}
	}
	return result;
}