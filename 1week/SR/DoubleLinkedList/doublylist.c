#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

DoublyList *createDoublyList()
{
	DoublyList *temp;

	temp = (DoublyList *)calloc(1, sizeof(DoublyList));
	if (temp == NULL)
		fprintf(stderr, "memory allocate failed");
	temp->headerNode.pRLink = &temp->headerNode;
	temp->headerNode.pLLink = &temp->headerNode;
	return (temp);
}
void deleteDoublyList(DoublyList *pList)
{
	if (pList == NULL)
	{
		fprintf(stderr, "memory allocate failed");
		return;
	}
	clearDoublyList(pList);
	free(pList);
}
int addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	int currentIndex;
	DoublyListNode *curr;
	DoublyListNode *next;

	if (pList == NULL)
	{
		fprintf(stderr, "memory allocate failed");
		return (-1);
	}
	currentIndex = pList->currentElementCount - 1;
	if (position < 0 || position > currentIndex + 1)
		return (-1);

	curr = &pList->headerNode;

	for (int i = 0; i <= position; ++i)
		curr = curr->pRLink;
	next = curr->pRLink;
	curr->pRLink = (DoublyListNode *)calloc(1, sizeof(DoublyListNode));
	*curr->pRLink = element;
	curr->pRLink->pRLink = next;
	curr->pRLink->pLLink = curr;
	next->pLLink = curr->pRLink;
	++pList->currentElementCount;
	return (position);
}
int removeDLElement(DoublyList *pList, int position)
{
	int currentIndex;
	DoublyListNode *curr;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return (-1);
	}
	if (position < 0 || position > currentIndex)
		return (-1);

	currentIndex = pList->currentElementCount - 1;
	curr = &pList->headerNode;

	for (int i = 0; i <= position; ++i)
		curr = curr->pRLink;
	curr->pLLink->pRLink = curr->pRLink;
	curr->pRLink->pLLink = curr->pLLink;
	--pList->currentElementCount;
	free(curr);
	return (position);
}
void clearDoublyList(DoublyList *pList)
{
	DoublyListNode *curr;
	DoublyListNode *temp;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return;
	}

	curr = pList->headerNode.pRLink;

	while (curr != &pList->headerNode)
	{
		temp = curr;
		curr = curr->pRLink;
		free(temp);
	}
	curr->pRLink = curr;
	curr->pLLink = curr;
	pList->currentElementCount = 0;
}
int getDoublyListLength(DoublyList *pList)
{
	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return (-1);
	}
	return (pList->currentElementCount);
}
DoublyListNode *getDLElement(DoublyList *pList, int position)
{
	DoublyListNode *curr;
	int currentIndex;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return (NULL);
	}
	if (position < 0 || position > currentIndex)
		return (NULL);

	currentIndex = pList->currentElementCount - 1;
	curr = pList->headerNode.pRLink;

	for (int i = 0; i <= position; ++i)
		curr = curr->pRLink;
	return (curr);
}
void displayDoublyList(DoublyList *pList)
{
	DoublyListNode *curr;
	int cnt = 0;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return;
	}

	curr = pList->headerNode.pRLink;

	while (curr != &pList->headerNode)
	{
		printf("Index : [%d], Data : [%d]\n", cnt++, curr->data);
		curr = curr->pRLink;
	}
}