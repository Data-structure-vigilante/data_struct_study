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

static void swapData(HeapTree *heap, int curr_idx)
{
    int tmp;

    tmp = heap->pRootNode[curr_idx];
    heap->pRootNode[curr_idx] = heap->pRootNode[curr_idx/2];
    heap->pRootNode[curr_idx/2] = tmp;
}

char addHeapData(HeapTree *heap, char data) {
    if (heap == NULL || heap->currentElementCount == heap->maxElementCount)
        return FALSE;
    int idx;
    idx = ++heap->currentElementCount;
    while(data > heap->pRootNode[idx/2])
    {
        if (idx == 1)
            break ;
        swapData(heap, idx);
        idx /= 2;
    }
    heap->pRootNode[idx] = data;
    return TRUE;
}

char removeHeapData(HeapTree *heap)
{
    if (heap == NULL || heap->currentElementCount == 0)
        return FALSE;
    int temp;
    temp = heap->pRootNode[heap->currentElementCount];
    --heap->currentElementCount;
    int parent = 1;
    int child = 2;
    while(child <= heap->currentElementCount)
    {
        if((child < heap->currentElementCount) && (heap->pRootNode[child] < heap->pRootNode[child + 1]))
            ++child;
        if(temp >= heap->pRootNode[child])
            break ;
        heap->pRootNode[parent] = heap->pRootNode[child];
        parent = child;
        child *= 2;
    }
    heap->pRootNode[parent] = temp;
    return TRUE;
}