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

#include <string.h>
char *reverseString(char *src) {
	LinkedStack* stack;
	StackNode 	*pNode, temp;
	char* result;
	int len = strlen(src);

	stack = createLinkedStack();
	result = (char*)calloc(len + 1, sizeof(char));
	while (*src) {
		temp.data = *src;
		pushLS(stack, temp);
		src++;
	}

	for (int i=0;i<len;i++) {
		pNode = popLS(stack);
		result[i] = pNode->data;
		free(pNode);
	}
	result[len] = 0;
	deleteLinkedStack(stack);
	return result;
}

int validatePoly(const char* str) {
	LinkedStack *stack;
	StackNode 	temp, *pNode;

	stack  = createLinkedStack();
	while (*str) {
		temp.data = *str;
		if (*str == '(' || *str == '{' || *str == '[')
			pushLS(stack, temp);
		else if (*str == ')' || *str == '}' || *str == ']') {
			pNode = peekLS(stack);
			if ((pNode->data == '(' && *str == ')') ||
			    (pNode->data == '{' && *str == '}') ||
				(pNode->data == '[' && *str == ']')) {
				pNode = popLS(stack);
				free(pNode);
				str++;
				continue;
			}
			deleteLinkedStack(stack);
			return (FALSE);
		}
		str++;
	}
	if (isLinkedStackEmpty(stack)) {
		deleteLinkedStack(stack);
		return TRUE;
	}
	else {
		deleteLinkedStack(stack);
		return FALSE;
	}
}