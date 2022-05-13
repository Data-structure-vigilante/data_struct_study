#include "bintree.h"
#include "heap.h"
#include "treeTraversal.h"
#include <gtest/gtest.h>
// #include "../../../gtest/include/gtest/gtest.h"

#include <stdio.h>

TEST(createHeap, when_create_expect_true) {
    HeapTree *heap;

    heap = createHeap(10);
    EXPECT_NE(heap, nullptr);
    EXPECT_EQ(heap->currentElementCount, 0);
    EXPECT_EQ(heap->maxElementCount, 10);
    deleteHeap(heap);
}

TEST(createHeap, when_createMax0_expect_true) {
    HeapTree *heap;

    heap = createHeap(0);
    EXPECT_EQ(heap, nullptr);
    deleteHeap(heap);
}

TEST(addHeapData, when_add_expect_node) {
    HeapTree *heap;

    heap = createHeap(10);

    addHeapData(heap, 10);
    EXPECT_EQ(heap->pRootNode[0], 10);
    addHeapData(heap, 20);
    EXPECT_EQ(heap->pRootNode[0], 20);
    EXPECT_EQ(heap->pRootNode[1], 10);

    deleteHeap(heap);
}

TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}