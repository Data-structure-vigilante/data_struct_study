#include "linkedStack.h"

static int isValidArg(LinkedStack *pStack, int position);
int addLLElement(LinkedStack *pStack, int position, StackNode element);
int removeLLElement(LinkedStack *pStack, int position);
StackNode *getLLElement(LinkedStack *pStack, int position);
void clearLinkedStack(LinkedStack *pStack);
int getLinkedStackLength(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);

LinkedStack* createLinkedStack() {
	LinkedStack *stack;

	stack = (LinkedStack*)calloc(1, sizeof(LinkedStack));
	return stack;
}

int pushLS(LinkedStack* pStack, StackNode element) {
	if (pStack == NULL)
		return ERROR;
	return addLLElement(pStack, pStack->currentElementCount, element);
}

StackNode* popLS(LinkedStack* pStack) {

}
StackNode* peekLS(LinkedStack* pStack);

void deleteLinkedStack(LinkedStack* pStack) {

}
int isLinkedStackEmpty(LinkedStack* pStack);

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
	}
	else {
		current = pStack->pTopElement;
		while (current->pLink != NULL)
			current = current->pLink;
		current->pLink = new_node;
	}
    ++pStack->currentElementCount;
    return position;
};

// int removeLLElement(LinkedStack *pStack, int position) {
//     if (!pStack || position < 0 || pStack->currentElementCount < position + 1)
//         return -1;

//     StackNode *prev_node = getLLElement(pStack, position - 1);
//     StackNode *target_node;

//     if (!prev_node) {
//         prev_node = &pStack->pTopElement;
//     }
//     target_node = prev_node->pLink;
//     prev_node->pLink = prev_node->pLink->pLink;
//     free(target_node);
//     --pStack->currentElementCount;
//     return position;
// }

// StackNode *getLLElement(LinkedStack *pStack, int position) {
//     StackNode *current;

//     if (!isValidArg(pStack, position))
//         return NULL;
//     current = &pStack->pTopElement;
//     for (int count = 0; count < position + 1; ++count) {
//         current = current->pLink;
//     }
//     return current;
// }

// void clearLinkedStack(LinkedStack *pStack) {
//     StackNode *temp_element;
//     if (!pStack)
//         return;
//     for (int count = 0; count < pStack->currentElementCount; ++count) {
//         temp_element = pStack->pTopElement.pLink;
//         pStack->pTopElement.pLink = temp_element->pLink;
//         free(temp_element);
//     }
//     pStack->pTopElement.pLink = NULL;
//     pStack->currentElementCount = 0;
// }

// int getLinkedStackLength(LinkedStack *pStack) {
//     if (!pStack)
//         return 0;
//     return pStack->currentElementCount;
// }

// void deleteLinkedStack(LinkedStack *pStack) {
//     if (!pStack)
//         return;
//     clearLinkedStack(pStack);
//     free(pStack);
// }

static int isValidArg(LinkedStack *pStack, int position) {
    if (!pStack || position < 0 || pStack->currentElementCount < position)
        return FALSE;
    return TRUE;
}
