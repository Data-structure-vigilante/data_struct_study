#include "linkedStack.h"

static int isValidArg(LinkedStack *pStack, int position);
int addLLElement(LinkedStack *pStack, int position, StackNode element);
int removeLLElement(LinkedStack *pStack, int position);
StackNode *getLLElement(LinkedStack *pStack, int position);
void clearLinkedStack(LinkedStack *pStack);
int getLinkedStackLength(LinkedStack *pStack);
void deleteLinkedList(LinkedStack *pStack);

LinkedStack *createLinkedStack() {
    LinkedStack *stack;

    stack = (LinkedStack *)calloc(1, sizeof(LinkedStack));
    return stack;
}

int pushLS(LinkedStack *pStack, StackNode element) {
    if (pStack == NULL)
        return ERROR;
    return addLLElement(pStack, pStack->currentElementCount, element);
}

StackNode *popLS(LinkedStack *pStack) {
    if (pStack == NULL || pStack->currentElementCount == 0)
        return NULL;

    StackNode *current;
    StackNode *prev;

    current = pStack->pTopElement;
    while (current->pLink != NULL) {
        prev = current;
        current = current->pLink;
    }
    prev->pLink = NULL;
    --pStack->currentElementCount;
    return current;
}

StackNode *peekLS(LinkedStack *pStack) {
    if (pStack == NULL || pStack->currentElementCount == 0)
        return NULL;
    return getLLElement(pStack, pStack->currentElementCount);
}

void deleteLinkedStack(LinkedStack *pStack) { deleteLinkedList(pStack); }
int isLinkedStackEmpty(LinkedStack *pStack) {
    if (pStack == NULL)
        return ERROR;
    return pStack->currentElementCount == 0;
}

// list

// Return : 실패 시 -1, 성공 시 인덱스 값.
int addLLElement(LinkedStack *pStack, int position, StackNode element) {
    StackNode *new_node;
    StackNode *current;

    if (!isValidArg(pStack, position)) {
        return -1;
    }

    new_node = (StackNode *)calloc(1, sizeof(StackNode));
    *new_node = element;
    new_node->pLink = NULL;
    if (pStack->currentElementCount == 0) {
        pStack->pTopElement = new_node;
    } else {
        current = pStack->pTopElement;
        while (current->pLink != NULL)
            current = current->pLink;
        current->pLink = new_node;
    }
    ++pStack->currentElementCount;
    return position;
};

StackNode *getLLElement(LinkedStack *pStack, int position) {
    StackNode *current;

    if (!isValidArg(pStack, position))
        return NULL;
    current = pStack->pTopElement;
    while (current->pLink != NULL)
        current = current->pLink;
    return current;
}

void clearLinkedStack(LinkedStack *pStack) {
    StackNode *temp_element;
    StackNode *current;

    if (!pStack)
        return;
    current = pStack->pTopElement;
    while (current != NULL) {
        temp_element = current;
        current = current->pLink;
        free(temp_element);
    }
    pStack->pTopElement = NULL;
    pStack->currentElementCount = 0;
}

// int getLinkedStackLength(LinkedStack *pStack) {
//     if (!pStack)
//         return 0;
//     return pStack->currentElementCount;
// }

void deleteLinkedList(LinkedStack *pStack) {
    if (!pStack)
        return;
    clearLinkedStack(pStack);
    free(pStack);
}

static int isValidArg(LinkedStack *pStack, int position) {
    if (!pStack || position < 0 || pStack->currentElementCount < position)
        return FALSE;
    return TRUE;
}
