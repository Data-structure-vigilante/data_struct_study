#include "avl.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TEST(AVLTest, integrationAVL) {
	AvlTree *tree;

	tree = createTree();
	for(int i=1;i<=9;i++)
		insertNode(tree, i);
	EXPECT_EQ(searchNode(tree, 1)->height, 1);
	EXPECT_EQ(searchNode(tree, 2)->height, 2);
	EXPECT_EQ(searchNode(tree, 3)->height, 1);
	EXPECT_EQ(searchNode(tree, 4)->height, 4);
	EXPECT_EQ(searchNode(tree, 5)->height, 1);
	EXPECT_EQ(searchNode(tree, 6)->height, 3);
	EXPECT_EQ(searchNode(tree, 7)->height, 1);
	EXPECT_EQ(searchNode(tree, 8)->height, 2);
	EXPECT_EQ(searchNode(tree, 9)->height, 1);
	deleteNode(tree, 9);
	deleteNode(tree, 7);
	EXPECT_EQ(searchNode(tree, 1)->height, 1);
	EXPECT_EQ(searchNode(tree, 2)->height, 2);
	EXPECT_EQ(searchNode(tree, 3)->height, 1);
	EXPECT_EQ(searchNode(tree, 4)->height, 3);
	EXPECT_EQ(searchNode(tree, 5)->height, 1);
	EXPECT_EQ(searchNode(tree, 6)->height, 2);
	EXPECT_EQ(searchNode(tree, 8)->height, 1);
	deleteTree(tree);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}