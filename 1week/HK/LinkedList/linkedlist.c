
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);
void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);

// Static
static int isValidArg(LinkedList *pList, int position);

LinkedList *createLinkedList() {
    LinkedList *list;

    list = (LinkedList *)calloc(1, sizeof(LinkedList));
    list->headerNode.data = 0;
    list->headerNode.pLink = NULL;
    return list;
};

// Return : 실패 시 -1, 성공 시 인덱스 값.
int addLLElement(LinkedList *pList, int position, ListNode element) {
    ListNode *new_node;
    ListNode *current;

    if (!isValidArg(pList, position)) {
        return -1;
    }

    new_node = (ListNode *)calloc(1, sizeof(ListNode));
    *new_node = element;
    current = &pList->headerNode;
    for (int count = 0; count < position; ++count) {
        current = current->pLink;
    }
    new_node->pLink = current->pLink;
    current->pLink = new_node;
    ++pList->currentElementCount;
    return position;
};

ListNode *getLLElement(LinkedList *pList, int position) {
    ListNode *current;

    if (!isValidArg(pList, position))
        return NULL;
    current = &pList->headerNode;
    for (int count = 0; count < position + 1; ++count) {
        current = current->pLink;
    }
    return current;
}

static int isValidArg(LinkedList *pList, int position) {
    if (!pList || position < 0 || pList->currentElementCount < position)
        return FALSE;
    return TRUE;
}
