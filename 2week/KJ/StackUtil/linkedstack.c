#include "stackutil.h"
#include <stdio.h>
#include <stdlib.h>

LinkedStack *createLinkedStack()
{
    LinkedStack *stack;

    stack = (LinkedStack *)calloc(1, sizeof(LinkedStack));
    if (stack == NULL)
        fprintf(stderr, "memory allocate failed\n");
    return stack;
}

int pushLS(LinkedStack *pStack, StackNode element)
{
    StackNode *new_node;

    if (pStack == NULL)
        return -1;

    new_node = (StackNode *)calloc(1, sizeof(StackNode));
    if (new_node == NULL)
        return -1;
    *new_node = element;

    if (pStack->pTopElement == NULL)
    {
        pStack->pTopElement = new_node;
    }
    else
    {
        new_node->pLink = pStack->pTopElement;
        pStack->pTopElement = new_node;
    }
    ++pStack->currentElementCount;
    return pStack->currentElementCount - 1;
}

StackNode *popLS(LinkedStack *pStack)
{
    StackNode *top;

    if (pStack == NULL || isLinkedStackEmpty(pStack))
        return NULL;

    top = pStack->pTopElement;
    if (pStack->currentElementCount == 1)
    {
        pStack->pTopElement = NULL;
    }
    else
    {
        pStack->pTopElement = pStack->pTopElement->pLink;
    }
    --pStack->currentElementCount;
    return top;
}

StackNode *peekLS(LinkedStack *pStack)
{
    if (pStack == NULL)
        return NULL;
    return pStack->pTopElement;
}

static void clearLinkedList(LinkedStack *pStack)
{
    StackNode *node;
    StackNode *temp;

    if (pStack == NULL)
        return;
    node = pStack->pTopElement;
    while (node != NULL)
    {
        temp = node;
        node = node->pLink;
        free(temp);
    }
    pStack->pTopElement = NULL;
    pStack->currentElementCount = 0;
}

void deleteLinkedStack(LinkedStack *pStack)
{
    if (pStack == NULL)
        return;
    clearLinkedList(pStack);
    free(pStack);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
    if (pStack == NULL)
        return FALSE;
    return (pStack->currentElementCount == 0);
}