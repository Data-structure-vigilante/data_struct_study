#include "heap.h"

HeapTree *createHeap(int maxElementCount) {
    if (maxElementCount <= 0)
        return NULL;

    HeapTree *heap;

    heap = (HeapTree *)calloc(1, sizeof(HeapTree));
    heap->pRootNode = (char *)calloc(maxElementCount + 1, sizeof(char));
    heap->currentElementCount = 0;
    heap->maxElementCount = maxElementCount;
    return heap;
}

void deleteHeap(HeapTree *heap) {
    if (heap) {
        free(heap->pRootNode);
        heap->pRootNode = NULL;
        free(heap);
    }
}

char addHeapData(HeapTree *heap, char data) {
    if (heap == NULL || heap->currentElementCount == heap->maxElementCount)
        return FALSE;
    if (heap->currentElementCount == 0)
        heap->pRootNode[0] = data;

    ++heap->currentElementCount;
    return TRUE;
}
char removeHeapData(HeapTree *heap, char data);