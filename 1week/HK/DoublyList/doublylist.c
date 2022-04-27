#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList *createDoublyList() {
    DoublyList *list;

    list = (DoublyList *)calloc(1, sizeof(DoublyList));
    if (!list) {
        return NULL;
    }
    list->currentElementCount = 0;
    list->headerNode.pLLink = &list->headerNode;
    list->headerNode.pRLink = &list->headerNode;
    return list;
}

void deleteDoublyList(DoublyList *pList) {
    if (!pList)
        return;
    clearDoublyList(pList);
    free(pList);
}

int addDLElement(DoublyList *pList, int position, DoublyListNode element) {
    DoublyListNode *new_node;
    DoublyListNode *current;

    if (!pList || position < 0 || pList->currentElementCount < position) {
        return -1;
    }

    new_node = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
    *new_node = element;
    current = &pList->headerNode;
    for (int count = 0; count < position; ++count) {
        current = current->pRLink;
    }
    new_node->pRLink = current->pRLink;
    new_node->pLLink = current;
    current->pRLink->pLLink = new_node;
    current->pRLink = new_node;
    ++pList->currentElementCount;
    return position;
}

DoublyListNode *getDLElement(DoublyList *pList, int position) {
    DoublyListNode *current;

    if (!pList || position < 0 || pList->currentElementCount < position + 1)
        return NULL;
    current = &pList->headerNode;
    for (int count = 0; count < position + 1; ++count) {
        current = current->pRLink;
    }
    return current;
}

int removeDLElement(DoublyList *pList, int position) {
    DoublyListNode *target_node;
    target_node = getDLElement(pList, position);

    if (!target_node)
        return -1;
    target_node->pRLink->pLLink = target_node->pLLink;
    target_node->pLLink->pRLink = target_node->pRLink;
    free(target_node);
    --pList->currentElementCount;
    return position;
}

void clearDoublyList(DoublyList *pList) {
    int result = 0;
    while (result == 0) {
        result = removeDLElement(pList, 0);
    }
}

int getDoublyListLength(DoublyList *pList) {
    return pList->currentElementCount;
}

void displayDoublyList(DoublyList *pList) {
    if (!pList)
        return;
    for (int cur = 0; cur < pList->currentElementCount; ++cur) {
        printf("%dth element: %d\n", cur, getDLElement(pList, cur)->data);
    }
}