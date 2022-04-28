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

StackNode *popLS(ArrayStack *pStack);
StackNode *peekLS(ArrayStack *pStack);
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
int isArrayStackFull(ArrayStack *pStack);
int isArrayStackEmpty(ArrayStack *pStack);