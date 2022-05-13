#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct HeapNodeType {
	int	data;
} HeapNode;

typedef struct HeapType {
	int maxElement;
	int currentElement;
	int (*cmp)(HeapNode, HeapNode);
	HeapNode *pElement;
} Heap;

Heap* createHeap(int maxElement, int (*cmp)(HeapNode, HeapNode));
HeapNode* insertHeap(Heap *pHeap, HeapNode element);
HeapNode* deleteHeap(Heap *pHeap, HeapNode element);
HeapNode* getRootNodeHeap(Heap *pHeap);
void printHeap(Heap *pHeap);
#endif