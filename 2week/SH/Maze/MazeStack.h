#ifndef _LINKED_STACK_
#define _LINKED_STACK_

#include <stdio.h>
#include <stdlib.h>
#include "Map.h"

typedef struct StackNodeType {
    MapPosition data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct LinkedStackType {
    int currentElementCount; // 현재 원소의 개수
    StackNode *pTopElement;  // Top 노드의 포인터
} LinkedStack;

LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, StackNode element);
StackNode *popLS(LinkedStack *pStack);
StackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
StackNode *getLLElement(LinkedStack *pStack, int position);
int addLLElement(LinkedStack *pStack, int position, StackNode element);
int isLinkedStackEmpty(LinkedStack *pStack);
void deleteLinkedList(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0
#define ERROR -1

#endif