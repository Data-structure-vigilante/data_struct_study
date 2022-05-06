#include "linkeddequeue.h"

LinkedDeque *createLinkedDeque() {
    LinkedDeque *deque;

    deque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    if (!deque)
        return NULL;
    return deque;
}

int insertFrontLD(LinkedDeque *pDeque, DequeNode element) {
    if (!pDeque)
        return FALSE;
    if (isLinkedDequeEmpty(pDeque)) {
        pDeque->pFrontNode = &element;
        pDeque->pRearNode = &element;
        element.pLLink = NULL;
        element.pRLink = NULL;
    } else {
        pDeque->pRearNode->pRLink = &element;
        element.pLLink = pDeque->pRearNode;
        pDeque->pRearNode = &element;
        pDeque->pRearNode->pRLink = NULL;
    }
    ++pDeque->currentElementCount;
    return TRUE;
}
int insertRearLD(LinkedDeque *pDeque, DequeNode element);
DequeNode *deleteFrontLD(LinkedDeque *pDeque);
DequeNode *deleteRearLD(LinkedDeque *pDeque);
DequeNode *peekFrontLD(LinkedDeque *pDeque);
DequeNode *peekRearLD(LinkedDeque *pDeque);
void deleteLinkedDeque(LinkedDeque *pDeque);
int isLinkedDequeEmpty(LinkedDeque *pDeque) {
    return pDeque->currentElementCount == 0;
}