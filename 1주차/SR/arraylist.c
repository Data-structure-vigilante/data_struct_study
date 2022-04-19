#include "arraylist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ArrayList *createArrayList(int maxElementCount) {
	if (maxElementCount <= 0) {
		return NULL;
	}
	ArrayList	*arry;
	arry = (ArrayList*)calloc(1, sizeof(ArrayList));
	if (arry == NULL) {
		fprintf(stderr, "memory allocate failed\n");
	}
	arry->maxElementCount = maxElementCount;
	arry->currentElementCount = 0;
	arry->pElement = (ArrayListNode*)calloc(arry->maxElementCount, sizeof(ArrayListNode));
	if (arry->pElement == NULL) {
		fprintf(stderr, "memory allocate failed\n");
	}
	return arry;
}

void deleteArrayList(ArrayList *pList) {
	if (pList == NULL)
		return;
	
	if (pList->pElement != NULL) {
		free(pList->pElement);
		pList->pElement = NULL;
	}
	free(pList);
}

// bool type이 아닌 이유
int isArrayListFull(ArrayList *pList) {
	if (pList->currentElementCount == pList->maxElementCount)
		return true;
	return false;
}

int addALElement(ArrayList *pList, int position, ArrayListNode element) {
	// position이 음수, 리스트가 full인 경우, ArrayList의 경우 논리적 순서와 물리적 저장 순서가 같다
	if (position < 0 || 
		position >= pList->maxElementCount ||
		position > pList->currentElementCount + 1)
		return false;
	
	if (position <= pList->currentElementCount - 1) {
		for (int i=pList->currentElementCount;i>position;i--) {
			pList->pElement[i].data = pList->pElement[i-1].data;
		}
	}
	pList->pElement[position].data = element.data;
	pList->currentElementCount++;
	
	return position;
}

int removeALElement(ArrayList *pList, int position) {
	if (pList == NULL || pList->pElement == NULL)
		return false;

	if (position < 0 || position > pList->currentElementCount -1)
		return false;

	for (int i = position;i<pList->currentElementCount;i++) {
		pList->pElement[i] = pList->pElement[i + 1];
	}
	pList->pElement[pList->currentElementCount-1].data = 0;
	pList->currentElementCount--;
	return 0;
}

ArrayListNode *getALElement(ArrayList *pList, int position) {
	if (pList == NULL || pList->pElement == NULL)
		return NULL;

	if (position < 0 || position > pList->currentElementCount)
		return NULL;

	return &pList->pElement[position];
}

void displayArrayList(ArrayList *pList) {
	if (pList == NULL || pList->pElement == NULL)
		return;
	
	for (int i=0;i<pList->currentElementCount;i++)
		printf("%d index element is : %d\n", i, pList->pElement[i].data);
}

void clearArrayList(ArrayList *pList) {
	if (pList == NULL || pList->pElement == NULL)
			return;

	for (int i = 0; i < pList->currentElementCount; i++)
	{
		pList->pElement[i].data = 0;
	}
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList *pList) {
	if (pList == NULL || pList->pElement == NULL)
			return false;

	return pList->currentElementCount;
}