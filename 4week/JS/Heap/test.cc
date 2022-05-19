#include "heap.h"
#include <gtest/gtest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxCmp(HeapNode left, HeapNode right) {
	return left.data < right.data;
}

int minCmp(HeapNode left, HeapNode right) {
	return left.data > right.data;
}

void print(HeapNode* node) {
	printf("%d", node->data);
}

TEST(maxHeapTest, insert_NotOrdered_Elements) {
	Heap *heap;
	HeapNode node;

	heap = createHeap(5, maxCmp);
	node.data = 3;
	insertHeap(heap, node);
	node.data = 2;
	insertHeap(heap, node);
	node.data = 1;
	insertHeap(heap, node);
	node.data = 4;
	insertHeap(heap, node);
	node.data = 5;
	insertHeap(heap, node);
	EXPECT_EQ(5, getRootNodeHeap(heap)->data);
	deleteHeap(heap);
}

TEST(maxHeapTest, pop_Elements) {
	Heap *heap;
	HeapNode node;

	heap = createHeap(5, maxCmp);
	node.data = 3;
	insertHeap(heap, node);
	node.data = 2;
	insertHeap(heap, node);
	node.data = 1;
	insertHeap(heap, node);
	node.data = 4;
	insertHeap(heap, node);
	node.data = 5;
	insertHeap(heap, node);
	EXPECT_EQ(5, getRootNodeHeap(heap)->data);
	popHeap(heap);
	EXPECT_EQ(4, getRootNodeHeap(heap)->data);
	popHeap(heap);
	EXPECT_EQ(3, getRootNodeHeap(heap)->data);
	popHeap(heap);
	EXPECT_EQ(2, getRootNodeHeap(heap)->data);
	popHeap(heap);
	EXPECT_EQ(1, getRootNodeHeap(heap)->data);
	deleteHeap(heap);
}

TEST(minHeapTest, insert_NotOrdered_Elements) {
	Heap *heap;
	HeapNode node;

	heap = createHeap(5, minCmp);
	node.data = 3;
	insertHeap(heap, node);
	node.data = 2;
	insertHeap(heap, node);
	node.data = 1;
	insertHeap(heap, node);
	node.data = 4;
	insertHeap(heap, node);
	node.data = 5;
	insertHeap(heap, node);
	EXPECT_EQ(1, getRootNodeHeap(heap)->data);
	deleteHeap(heap);
}

TEST(minHeapTest, pop_Elements) {
	Heap *heap;
	HeapNode node;

	heap = createHeap(5, minCmp);
	node.data = 3;
	insertHeap(heap, node);
	node.data = 2;
	insertHeap(heap, node);
	node.data = 1;
	insertHeap(heap, node);
	node.data = 4;
	insertHeap(heap, node);
	node.data = 5;
	insertHeap(heap, node);
	EXPECT_EQ(1, getRootNodeHeap(heap)->data);
	for (int i=1;i<=4;i++) {
		popHeap(heap);
		EXPECT_EQ(i+1, getRootNodeHeap(heap)->data);
	}
	deleteHeap(heap);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}