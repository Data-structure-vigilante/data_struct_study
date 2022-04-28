#include "arraystack.h"
#include <stdlib.h>

ArrayStack *createArrayStack(int maxElementCount) {
    ArrayStack *stack;

    if (maxElementCount <= 0)
        return NULL;
    stack = (ArrayStack *)calloc(1, sizeof(ArrayStack));
    if (!stack)
        return NULL;
    stack->pElement = (StackNode *)calloc(maxElementCount, sizeof(StackNode));
    if (!stack->pElement)
        return NULL;
    stack->maxElementCount = maxElementCount;
    return stack;
};

int pushLS(ArrayStack *pStack, StackNode element) {
    if (!pStack)
        return -1;
    if (pStack->currentElementCount < pStack->maxElementCount) {
        pStack->pElement[pStack->currentElementCount] = element;
        ++pStack->currentElementCount;
        return TRUE;
    } else
        return FALSE;
}

StackNode *popLS(ArrayStack *pStack) {
	if (pStack == NULL)
		return NULL;
	if (pStack->currentElementCount == 0)
		return NULL;
	--pStack->currentElementCount;
	return &pStack->pElement[pStack->currentElementCount];
}

StackNode *peekLS(ArrayStack *pStack) {
	if (pStack == NULL)
		return NULL;
	if (pStack->currentElementCount == 0)
		return NULL;
	return &pStack->pElement[pStack->currentElementCount-1];
}

void deleteArrayStack(ArrayStack *pStack) {
    if (!pStack)
        return;
    if (pStack->pElement) {
        free(pStack->pElement);
        pStack->pElement = NULL;
    }
    free(pStack);
    return;
}

int isArrayStackFull(ArrayStack *pStack) {
	if (pStack == NULL)
		return ERROR;
	return pStack->currentElementCount == pStack->maxElementCount;
}

int isArrayStackEmpty(ArrayStack *pStack) {
	if (pStack == NULL)
		return ERROR;
	return pStack->currentElementCount == 0;
}