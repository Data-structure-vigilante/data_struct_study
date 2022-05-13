#ifndef __HEAP_H__
#define __HEAP_H__

typedef struct HeapNodeType {
    int data;
} HeapNode;

typedef struct HeapType {
    int maxElement;
    int currentElement;
    int (*cmp)(HeapNode, HeapNode);
    HeapNode *pElement;
} Heap;

typedef enum BoolEnum { FALSE, TRUE } Bool;

Heap *createHeap(int maxElement, int (*cmp)(HeapNode, HeapNode));
HeapNode *insertHeap(Heap *pHeap, HeapNode element);
Bool popHeap(Heap *pHeap);
HeapNode *getRootNodeHeap(Heap *pHeap);
void deleteHeap(Heap *pHeap);
void printHeap(Heap *pHeap, void (*printNode)(HeapNode *));

#endif