#include "linkeddequeue.h"

LinkedDeque *createLinkedDeque()
{
    LinkedDeque *deque;

    deque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    if (!deque)
        return NULL;
    return deque;
}

int insertFrontLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return FALSE;

    DequeNode *node = (DequeNode *)calloc(1, sizeof(DequeNode));
    if (node == NULL)
        return FALSE;

    *node = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
        node->pLLink = NULL;
        node->pRLink = NULL;
    }
    else
    {
        pDeque->pFrontNode->pLLink = node;
        node->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = node;
        pDeque->pFrontNode->pLLink = NULL;
    }
    ++pDeque->currentElementCount;
    return TRUE;
}
int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return FALSE;

    DequeNode *node = (DequeNode *)calloc(1, sizeof(DequeNode));
    if (node == NULL)
        return FALSE;

    *node = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
        node->pLLink = NULL;
        node->pRLink = NULL;
    }
    else
    {
        pDeque->pRearNode->pRLink = node;
        node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = node;
        pDeque->pRearNode->pRLink = NULL;
    }
    ++pDeque->currentElementCount;
    return TRUE;
}
DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);

    DequeNode *node = pDeque->pFrontNode;

    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    if (pDeque->pFrontNode != NULL)
        pDeque->pFrontNode->pLLink = NULL;
    --pDeque->currentElementCount;
    return node;
}
DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);

    DequeNode *node = pDeque->pRearNode;

    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    if (pDeque->pRearNode != NULL)
        pDeque->pRearNode->pRLink = NULL;
    --pDeque->currentElementCount;
    return node;
}
DequeNode *peekFrontLD(LinkedDeque *pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pFrontNode);
}
DequeNode *peekRearLD(LinkedDeque *pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);
    return (pDeque->pRearNode);
}
void deleteLinkedDeque(LinkedDeque *pDeque)
{
    while (pDeque->currentElementCount)
        free(deleteFrontLD(pDeque));
    free(pDeque);
}
int isLinkedDequeEmpty(LinkedDeque *pDeque)
{
    return pDeque->currentElementCount == 0;
}