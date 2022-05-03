#include "MazeStack.h"

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
	pStack->pTopElement = current->pLink;
	--pStack->currentElementCount;
	return current;
}

StackNode *peekLS(LinkedStack *pStack) {
	if (pStack == NULL || pStack->currentElementCount == 0)
		return NULL;
	return getLLElement(pStack, 0);
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

	new_node = (StackNode *)calloc(1, sizeof(StackNode));
	*new_node = element;
	new_node->pLink = pStack->pTopElement;
	pStack->pTopElement = new_node;
	++pStack->currentElementCount;
	return position;
};

StackNode *getLLElement(LinkedStack *pStack, int position) {
	StackNode *current;

	current = pStack->pTopElement;
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