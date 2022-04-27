#include "circularlist.h"
#include <stdlib.h>
#include <stdio.h>

CircularList* createCircularList() {
	CircularList* temp;

	temp = (CircularList*)calloc(1, sizeof(CircularList));
	if (temp == NULL) {
		fprintf(stderr, "memory allocate failed\n");
		return NULL;
	}
	temp->headerNode.pLLink = &temp->headerNode;
	temp->headerNode.pRLink = &temp->headerNode;
	return temp;
}

void deleteCircularList(CircularList* pList) {
	if (pList == NULL) {
		fprintf(stderr, "NULL pointer detected\n");
		return;
	}
	clearCircularList(pList);
	free(pList);
}

//TODO 원형리스트에선 position을 currentElementCount로 나눈 나머지 리턴으로 수정
int addCLElement(CircularList* pList, int position, CircularListNode element) {
	CircularListNode*	curr;
	CircularListNode*	next;
	int 				currentIndex;

	if (pList == NULL) {
		fprintf(stderr, "NULL pointer detected\n");
		return (-1);
	}
	
	currentIndex = pList->currentElementCount -1;

	if (position < 0 || position > currentIndex + 1)
		return (-1);
	
	curr = &pList->headerNode;

	for (int i=0;i<position;++i)
		curr = curr->pRLink;
	next = curr->pRLink;
	curr->pRLink = (CircularListNode*)calloc(1, sizeof(CircularListNode));
	*curr->pRLink = element;
	curr->pRLink->pRLink = next;
	curr->pRLink->pLLink = curr;
	next->pLLink = curr->pRLink;
	++pList->currentElementCount;
	return (position);
}

//TODO: 원형리스트에선 position을 currentElementCount로 나눈 나머지
int removeCLElement(CircularList* pList, int position) {
	int currentIndex;
	CircularListNode *curr;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return (-1);
	}

	currentIndex = pList->currentElementCount - 1;

	if (position < 0 || position > currentIndex)
		return (-1);

	curr = &pList->headerNode;

	for (int i = 0; i <= position; ++i)
		curr = curr->pRLink;
	curr->pLLink->pRLink = curr->pRLink;
	curr->pRLink->pLLink = curr->pLLink;
	--pList->currentElementCount;
	free(curr);
	return (position);
}

void clearCircularList(CircularList* pList) {
	CircularListNode* node;

	if (pList == NULL) {
		fprintf(stderr, "NULL pointer detected\n");
		return;
	}
	node = pList->headerNode.pRLink;
	while (node != &pList->headerNode) {
		CircularListNode* temp;
		temp = node;
		node = node->pRLink;
		free(temp);
	}
	node->pLLink = &pList->headerNode;
	node->pRLink = &pList->headerNode;
}

int getCircularListLength(CircularList* pList) {
	if (pList == NULL) {
		fprintf(stderr, "NULL pointer detected\n");
		return -1;
	}
	return pList->currentElementCount;
}

CircularListNode* getCLElement(CircularList* pList, int position) {
	CircularListNode *curr;
	int currentIndex;

	if (pList == NULL)
	{
		fprintf(stderr, "NULL pointer detected");
		return (NULL);
	}

	if (pList->currentElementCount == 0)
		return (NULL);

	currentIndex = position % pList->currentElementCount;

	if (position < 0)
		return (NULL);

	curr = pList->headerNode.pRLink;

	for (int i = 0; i <= position; ++i)
		curr = curr->pRLink;
	return (curr);
}

void displayCircularList(CircularList* pList) {
	CircularListNode *node;
	int cnt = 0;

	if (pList == NULL) {
		fprintf(stderr, "NULL pointer detected\n");
		return;
	}
	node = pList->headerNode.pRLink;
	while (node != &pList->headerNode) {
		printf("Index : [%d], Data : [%d]\n", cnt, node->data);
		node = node->pRLink;
		++cnt;
	}
}

// int main(void) {
// 	CircularList* list;

// 	list = createCircularList();

// 	for (int i=0;i<10;i++) {
// 		CircularListNode temp={i, NULL, NULL};
// 		addCLElement(list, i, temp);
// 	}
// 	displayCircularList(list);
// 	removeCLElement(list, 4);
// 	printf("\n");
// 	displayCircularList(list);
// 	removeCLElement(list, 4);
// 	printf("\n");
// 	displayCircularList(list);
// }