#include "doublylist.h"
#include <stdlib.h>

static int isValidArg(DoublyList *pList, int position);
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

void deleteDoublyList(DoublyList *pList);
int addDLElement(DoublyList *pList, int position, DoublyListNode element) {
    DoublyListNode *new_node;
    DoublyListNode *current;

    if (!isValidArg(pList, position)) {
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

int removeDLElement(DoublyList *pList, int position);
void clearDoublyList(DoublyList *pList);
int getDoublyListLength(DoublyList *pList);
DoublyListNode *getDLElement(DoublyList *pList, int position);
void displayDoublyList(DoublyList *pList);

static int isValidArg(DoublyList *pList, int position) {
    if (!pList || position < 0 || pList->currentElementCount < position)
        return FALSE;
    return TRUE;
}
