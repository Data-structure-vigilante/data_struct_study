
#include "polylinkedlist.h"
#include <stdio.h>
#include <stdlib.h>

PolyList *createPolyList()
{
	PolyList *temp;

	temp = (PolyList *)calloc(1, sizeof(PolyList));
	if (temp == NULL)
		fprintf(stderr, "memory allocate failed\n");
	return temp;
}

int addPLElement(PolyList *pList, PolyListNode element)
{
	PolyListNode *node;
	PolyListNode *next;

	if (pList == NULL)
		return (-1);

	node = &pList->headerNode;
	while(node->pLink != NULL) {
		if (node->pLink->degree == element.degree) {
			node->pLink->coef += element.coef;
			return (0);
		}
		else if (node->pLink->degree < element.degree)
			break;
		node = node->pLink;
	}
	next = (PolyListNode*)node->pLink;
	node->pLink = (PolyListNode*)calloc(1, sizeof(PolyListNode));
	if (node->pLink == NULL) {
		fprintf(stderr, "memory allocate failed\n");
		return (-1);
	}
	*(node->pLink) = element;
	node->pLink->pLink = next;
	pList->currentElementCount++;
	return (0);
}

static int addPolyNodeLast(PolyList *pList, float coef, int degree)
{
	int ret = FALSE, i = 0;

	PolyListNode node = {
		0,
	};
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL)
	{
		int length = getPolyListLength(pList);
		ret = addPLElement(pList, node);
	}
	return (ret);
}

PolyList *sumPolyList(PolyList *listA, PolyList *listB)
{
	PolyListNode *currA;
	PolyListNode *currB;
	PolyListNode *currC;
	PolyList *listC;

	if (listA == NULL && listB == NULL)
		return (NULL);
	listC = createPolyList();
	currA = listA == NULL ? NULL : listA->headerNode.pLink;
	currB = listB == NULL ? NULL : listB->headerNode.pLink;
	while (currA != NULL && currB != NULL)
	{
		PolyListNode temp;

		if (currA->degree > currB->degree)
		{
			temp = *currA;
			currA = currA->pLink;
		}
		else if (currA->degree == currB->degree)
		{
			temp.coef = currA->coef + currB->coef;
			temp.degree = currA->degree;
			currA = currA->pLink;
			currB = currB->pLink;
		}
		else
		{
			temp = *currB;
			currB = currB->pLink;
		}
		addPolyNodeLast(listC, temp.coef, temp.degree);
	}
	currC = currA == NULL ? currB : currA;
	while (currC != NULL)
	{
		addPolyNodeLast(listC, currC->coef, currC->degree);
		currC = currC->pLink;
	}
	return (listC);
}

int removePLElement(PolyList *pList, int position)
{
	PolyListNode *node;
	PolyListNode *target;
	int i;

	if (pList == NULL)
		return (-1);
	if (position < 0)
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

PolyListNode *getPLElement(PolyList *pList, int position)
{
	PolyListNode *node;

	if (pList == NULL)
		return (NULL);
	if (position < 0)
		return (NULL);
	node = &pList->headerNode;
	for (int i = 0; i < position; i++)
		node = node->pLink;
	return (node->pLink);
}

void clearPolyList(PolyList *pList)
{
	PolyListNode *node;
	PolyListNode *temp;

	if (pList == NULL)
		return;
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

void printList(PolyList *pList)
{
	PolyListNode *node;

	if (pList == NULL)
		return;

	node = pList->headerNode.pLink;

	while (node != NULL)
	{
		printf("coef : %f, degree : %d\n", node->coef, node->degree);
		node = node->pLink;
	}
}

int getPolyListLength(PolyList *pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->currentElementCount);
}

void deletePolyList(PolyList *pList)
{
	if (pList == NULL)
		return;
	clearPolyList(pList);
	free(pList);
}

int main()
{
	PolyList *listA;

	listA = createPolyList();
	for (int i=0;i<10;i+=2) {
		PolyListNode temp = {i, i, NULL};
		addPLElement(listA, temp);
	}
	printList(listA);
	putc('\n', stdout);
	for (int i=1;i<=9;i+=2) {
		PolyListNode temp = {i, i, NULL};
		addPLElement(listA, temp);
	}
	{
		PolyListNode temp = {1, 9, NULL};
		addPLElement(listA, temp);
	}
	printList(listA);
	deletePolyList(listA);
}
