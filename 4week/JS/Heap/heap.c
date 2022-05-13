#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define HEAP_CMP(L, R) pHeap->cmp(pHeap->pElement[L], pHeap->pElement[R])

Heap *createHeap(int maxElement, int (*cmp)(HeapNode, HeapNode)) {
    Heap *heap;

    heap = (Heap *)calloc(1, sizeof(Heap));
    if (heap == NULL) {
        perror("heap allocate fail\n");
        return NULL;
    }
    heap->maxElement = maxElement;
    heap->cmp = cmp;
    heap->pElement = (HeapNode *)calloc(heap->maxElement + 1, sizeof(HeapNode));
    if (heap->pElement == NULL) {
        perror("heap pElement allocate fail\n");
        free(heap);
        return NULL;
    }
    return heap;
}

HeapNode *insertHeap(Heap *pHeap, HeapNode element) {
    int idx;

    if (pHeap == NULL) {
        fprintf(stderr, "insertHeap input in NULL\n");
        return NULL;
    }
    if (pHeap->currentElement == pHeap->maxElement) {
        fprintf(stderr, "heap is full\n");
        return NULL;
    }

    idx = pHeap->currentElement + 1;
    while ((idx != 1) && pHeap->cmp(element, pHeap->pElement[idx])) {
        pHeap->pElement[idx] = pHeap->pElement[idx / 2];
        idx /= 2;
    }
    pHeap->pElement[idx] = element;
    return &pHeap->pElement[idx];
}

Bool deleteHeap(Heap *pHeap) {
    int idx;
    int child;
    int parent;

    HeapNode temp;

    if (pHeap == NULL) {
        fprintf(stderr, "insertHeap input in NULL\n");
        return FALSE;
    }

    temp = pHeap->pElement[pHeap->currentElement];
    --pHeap->currentElement;

    parent = 1;
    child = 2;
    while (child <= pHeap->currentElement) {
        if (child < pHeap->currentElement && !HEAP_CMP(child, child + 1))
					++child;
				if (cmp(temp, pHeap->pElement[child]))
					break;
				pHeap->pElement[parent] = pHeap->pElement[child];
				parent = child;
				child *= 2;
    }
		pHeap->pElement[parent] = temp;
		return TRUE;
}

HeapNode *getRootNodeHeap(Heap *pHeap) {
    if (pHeap == NULL)
        fprintf(stderr, "getRootNodeHeap input in NULL\n");
    if (pHeap->currentElement == 0)
        fprintf(stderr, "getRootNodeHeap currentElement is 0\n");
    return &pHeap->pElement[1];
}

void printHeap(Heap *pHeap, void (*printNode)(HeapNode*)) {
	printf("** Print Heap **\n");
	for(int i = 1; i <= pHeap->currentElement; ++i) {
		printf("[");
		printNode(&pHeap->pElement[i]);
		printf("] ");
	}
	printf("\n** Print End **\n")
}