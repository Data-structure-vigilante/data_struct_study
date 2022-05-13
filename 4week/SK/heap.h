#if !defined(HEAP_HPP)
#define HEAP_HPP

#include "bintree.h"
#include "treeTraversal.h"

// typedef struct BinTreeNodeType {
//     char data;
//     int visited;
//     struct BinTreeNodeType *pLeftChild;
//     struct BinTreeNodeType *pRightChild;
// } BinTreeNode;

typedef struct HeapTreeType {
    char *pRootNode;
    int currentElementCount;
    int maxElementCount;
} HeapTree;

HeapTree *createHeap(int maxElementCount);
void deleteHeap(HeapTree *heap);
char addHeapData(HeapTree *heap, char data);
char removeHeapData(HeapTree *heap, char data);

#endif // HEAP_HPP