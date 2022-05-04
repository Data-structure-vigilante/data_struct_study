#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

#include <stdio.h>
#include <stdlib.h>
typedef struct StackNodeType {
    int data;
} StackNode;

typedef struct ArrayStackType {
    int maxElementCount;     // 최대 원소 개수
    int currentElementCount; // 현재 원소의 개수
    StackNode *pElement;
} ArrayStack;

ArrayStack *createArrayStack(int maxElementCount);
int pushLS(ArrayStack *pStack, StackNode element);
StackNode *popLS(ArrayStack *pStack);
StackNode *peekLS(ArrayStack *pStack);
void deleteArrayStack(ArrayStack *pStack);
int isArrayStackFull(ArrayStack *pStack);
int isArrayStackEmpty(ArrayStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0
#define ERROR -1

#endif
