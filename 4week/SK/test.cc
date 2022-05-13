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
    EXPECT_EQ(heap->pRootNode[1], 10);
    addHeapData(heap, 20);
    EXPECT_EQ(heap->pRootNode[1], 20);
    EXPECT_EQ(heap->pRootNode[2], 10);
    addHeapData(heap, 1);
    EXPECT_EQ(heap->pRootNode[3], 1);

    deleteHeap(heap);
}

TEST(removeHeapData, when_remove_expect_node) {
    HeapTree *heap;

    heap = createHeap(10);
    addHeapData(heap, 1);
    addHeapData(heap, 2);
    addHeapData(heap, 3);
    addHeapData(heap, 4);
    addHeapData(heap, 5);
    addHeapData(heap, 6);
    removeHeapData(heap);
    EXPECT_EQ(heap->pRootNode[1], 5);
    removeHeapData(heap);
    EXPECT_EQ(heap->pRootNode[1], 4);
    removeHeapData(heap);
    EXPECT_EQ(heap->pRootNode[1], 3);
    deleteHeap(heap);

}

TEST(Leaks, leaks) { system("leaks test"); }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}