#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>

LinkedDeque *createLinkedDeque() {
    LinkedDeque *deque;

    deque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    if (deque == NULL)
        fprintf(stderr, "memory allocat fail");
    deque->headerNode.pLLink = &deque->headerNode;
    deque->headerNode.pRLink = &deque->headerNode;
    return deque;
}

inline DequeNode *createNode(DequeNode element) {
    DequeNode *newNode;

    newNode = (DequeNode *)calloc(1, sizeof(DequeNode));
    if (newNode == NULL) {
        fprintf(stderr, "memory allocate fail");
        return newNode;
    }
    *newNode = element;
    return newNode;
}

static void insertNewNode(DequeNode *prevNode, DequeNode *newNode) {
    newNode->pRLink = prevNode->pRLink;
    newNode->pLLink = prevNode;
    prevNode->pRLink->pLLink = newNode;
    prevNode->pRLink = newNode;
}

int insertFrontLD(LinkedDeque *pDeque, DequeNode element) {
    DequeNode *newNode;

    if (pDeque == NULL) {
        return ERROR;
    }
    newNode = createNode(element);
    insertNewNode(&pDeque->headerNode, newNode);
    ++pDeque->currentElementCount;
}

int insertRearLD(LinkedDeque *pDeque, DequeNode element) {
    DequeNode *newNode;
    DequeNode *nextNode;

    if (pDeque == NULL) {
        return ERROR;
    }
    newNode = createNode(element);
    insertNewNode(pDeque->headerNode.pLLink, newNode);
    ++pDeque->currentElementCount;
}
static DequeNode *popLD(DequeNode *targetNode) {
    targetNode->pRLink->pLLink = targetNode->pLLink;
    targetNode->pLLink->pRLink = targetNode->pRLink;
    return targetNode;
}

DequeNode *popFrontLD(LinkedDeque *pDeque) {
    DequeNode *targetNode = pDeque->headerNode.pRLink;

    if (isLinkedDequeEmpty(pDeque))
        return NULL;
    --pDeque->currentElementCount;
    return popLD(targetNode);
}

DequeNode *popRearLD(LinkedDeque *pDeque) {
    DequeNode *targetNode = pDeque->headerNode.pLLink;

    if (isLinkedDequeEmpty(pDeque))
        return NULL;
    --pDeque->currentElementCount;
    return popLD(targetNode);
}

DequeNode *peekFrontLD(LinkedDeque *pDeque) {
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return NULL;
    return pDeque->headerNode.pRLink;
}

DequeNode *peekRearLD(LinkedDeque *pDeque) {
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return NULL;
    return pDeque->headerNode.pLLink;
}

void deleteLinkedDeque(LinkedDeque *pDeque) {
    DequeNode *popNode;

		if (pDeque == NULL)
        return;
    while (isLinkedDequeEmpty(pDeque) == FALSE) {
			popNode = popFrontLD(pDeque);
			free(popNode);
		}
		free(pDeque);
}

int isLinkedDequeEmpty(LinkedDeque *pDeque) {
    if (pDeque == NULL)
        return ERROR;
    return (pDeque->currentElementCount == 0);
};