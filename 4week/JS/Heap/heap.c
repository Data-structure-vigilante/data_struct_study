#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

Heap* createHeap(int maxElement, int (*cmp)(HeapNode, HeapNode)) {
	Heap*	heap;

	heap = (Heap*)calloc(1, sizeof(Heap));
	if (heap == NULL) {
		perror("heap allocate fail\n");
		return NULL;
	}
	heap->maxElement = maxElement;
	heap->cmp = cmp;
	heap->pElement = (HeapNode*)calloc(heap->maxElement + 1, sizeof(HeapNode));
	if (heap->pElement == NULL) {
		perror("heap pElement allocate fail\n");
		free(heap);
		return NULL;
	}
	return heap;
}

HeapNode* insertHeap(Heap *pHeap, HeapNode element) {
	int idx;

	if (pHeap == NULL)
		fprintf(stderr, "insertHeap input in NULL\n");
	if (pHeap->currentElement == pHeap->maxElement)
		fprintf(stderr, "heap is full\n");	
	idx = pHeap->currentElement + 1;
	while ((idx != 1) && pHeap->cmp(element, pHeap->pElement[idx])) {
		pHeap->pElement[idx] = pHeap->pElement[idx/2];
		idx /= 2;
	}
	pHeap->pElement[idx] = element;
	return &pHeap->pElement[idx];
}

HeapNode* deleteHeap(Heap *pHeap, HeapNode element) {

}

HeapNode* getRootNodeHeap(Heap *pHeap) {
	if (pHeap == NULL)
		fprintf(stderr, "getRootNodeHeap input in NULL\n");
	if (pHeap->currentElement == 0)
		fprintf(stderr, "getRootNodeHeap currentElement is 0\n");
	return &pHeap->pElement[1];
}

void printHeap(Heap *pHeap) {

}