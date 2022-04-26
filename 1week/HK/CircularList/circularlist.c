
#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>

// Static
static int isValidArg(CircularList *pList, int position);
static void addNodeToFirstPosition(CircularList *pList, ListNode *new_node);
static void addNodeToNotFirstPosition(CircularList *pList, ListNode *new_node,
                                      int position);

CircularList *createCircularList() {
    CircularList *list;

    list = (CircularList *)calloc(1, sizeof(CircularList));
    list->headerNode.data = 0;
    list->headerNode.pLink = NULL;
    return list;
};

// Return : 실패 시 -1, 성공 시 인덱스 값.
int addCLElement(CircularList *pList, int position, ListNode element) {
    ListNode *new_node;
    ListNode *current;

    if (!isValidArg(pList, position)) {
        return -1;
    }

    new_node = (ListNode *)calloc(1, sizeof(ListNode));
    if (!new_node)
        return -1;

    *new_node = element;
    if (position == 0)
        addNodeToFirstPosition(pList, new_node);
    else
        addNodeToNotFirstPosition(pList, new_node, position);
    ++pList->currentElementCount;
    return position;
};

static void addNodeToFirstPosition(CircularList *pList, ListNode *new_node) {
    ListNode *last_element;

    if (pList->currentElementCount == 0) {
        pList->headerNode.pLink = new_node;
        new_node->pLink = new_node;
    } else {
        last_element = getCLElement(pList, pList->currentElementCount);
        last_element->pLink = new_node;
        new_node->pLink = pList->headerNode.pLink;
        pList->headerNode.pLink = new_node;
    }
}

static void addNodeToNotFirstPosition(CircularList *pList, ListNode *new_node,
                                      int position) {
    ListNode *current = &pList->headerNode;

    for (int count = 0; count < position; ++count) {
        current = current->pLink;
    }
    new_node->pLink = current->pLink;
    current->pLink = new_node;
}

int removeCLElement(CircularList *pList, int position) {
    if (!pList || position < 0 || pList->currentElementCount < position + 1)
        return -1;

    ListNode *prev_node = getCLElement(pList, position - 1);
    ListNode *target_node;

    if (!prev_node) {
        prev_node = &pList->headerNode;
    }
    target_node = prev_node->pLink;
    prev_node->pLink = prev_node->pLink->pLink;
    free(target_node);
    --pList->currentElementCount;
    return position;
}
static void removeFirstNode(CircularList *pList) {
    if (pList->currentElementCount == 1) {
        free(pList->headerNode.pLink);
        pList->headerNode.pLink = NULL;
    } else {
        
    }
}
static void removeNotFirstNode(CircularList *pList, int position) {}

ListNode *getCLElement(CircularList *pList, int position) {
    ListNode *current;

    if (!isValidArg(pList, position))
        return NULL;
    current = &pList->headerNode;
    for (int count = 0; count < position + 1; ++count) {
        current = current->pLink;
    }
    return current;
}

void clearCircularList(CircularList *pList) {
    ListNode *temp_element;
    if (!pList)
        return;
    for (int count = 0; count < pList->currentElementCount; ++count) {
        temp_element = pList->headerNode.pLink;
        pList->headerNode.pLink = temp_element->pLink;
        free(temp_element);
    }
    pList->headerNode.pLink = NULL;
    pList->currentElementCount = 0;
}

int getCircularListLength(CircularList *pList) {
    if (!pList)
        return 0;
    return pList->currentElementCount;
}

void deleteCircularList(CircularList *pList) {
    if (!pList)
        return;
    clearCircularList(pList);
    free(pList);
}

static int isValidArg(CircularList *pList, int position) {
    if (!pList || position < 0 || pList->currentElementCount < position)
        return FALSE;
    return TRUE;
}
