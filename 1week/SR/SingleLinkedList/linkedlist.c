#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

LinkedList *createLinkedList() {
	LinkedList*	temp;

	temp = (LinkedList*)calloc(1, sizeof(LinkedList));
	if (temp == NULL)
		fprintf(stderr, "memory allocate failed\n");
	return temp;
}

int addLLElement(LinkedList *pList, int position, ListNode element) {
	ListNode*	node;
	ListNode*	next;

	if (pList == NULL)
		return (-1);

	if (position < 0 || pList->currentElementCount < position)
		return (-1);

	node = &pList->headerNode;
	for (int i=0;i<position;i++) {
		node = node->pLink;
	}
	next = (ListNode*)node->pLink;
	node->pLink = (ListNode*)calloc(1, sizeof(ListNode));
	if (node->pLink == NULL) {
		fprintf(stderr, "memory allocate failed\n");
		return (-1);
	}
	*(node->pLink) = element;
	node->pLink->pLink = next;
	pList->currentElementCount++;
	return (0);
}

int removeLLElement(LinkedList *pList, int position) {
	ListNode* node;
	ListNode* target;
	int i;

	if (pList == NULL)
		return (-1);
	if (position < 0 || position > pList->currentElementCount-1)
		return (-1);

	i = 0;
	node = &pList->headerNode;

	while (i < position)
	{
		node = node->pLink;
		i++;
	}
	target = node->pLink;
	node->pLink = node->pLink->pLink;
	free(target);
	pList->currentElementCount--;
	return (0);
}

ListNode *getLLElement(LinkedList *pList, int position) {
	ListNode *node;
	
	if (pList == NULL)
		return (NULL);
	if (position < 0)
		return (NULL);
	node = &pList->headerNode;
	for (int i = 0; i < position; i++)
		node = node->pLink;
	return (node->pLink);
}

void clearLinkedList(LinkedList *pList) {
	ListNode *node;
	ListNode *temp;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pLink;
	while (node != NULL)
	{
		temp = node;
		node = node->pLink;
		free(temp);
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

void printList(LinkedList *pList) {
	ListNode* node;

	if (pList == NULL)
		return;

	node = pList->headerNode.pLink;

	while (node != NULL) {
		printf("result : %d\n", node->data);
		node = node->pLink;
	}
}

int getLinkedListLength(LinkedList *pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList *pList)
{
	if (pList == NULL)
		return;
	clearLinkedList(pList);
	free(pList);
}

