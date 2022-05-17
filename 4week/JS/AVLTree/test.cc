#include "bst.h"
#include "binTree.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(bstTest, insertBST) {
	BinTreeNode	temp;

	temp.data = 5;
	temp.pLeftChild = NULL;
	temp.pRightChild = NULL;
	BinTree*	tree = makeBinTree(temp);
	for (int i=0;i<5;i++) {
		temp.data = i;
		EXPECT_EQ(insertBST(tree, temp)->data, i);
	}
	for (int i=0;i<=5;i++) {
		temp.data = i;
		free(deleteBST(tree, temp));
	}
	free(tree);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}