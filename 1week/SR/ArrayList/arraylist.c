#include "arraylist.h"
#include <stdlib.h>
#include <stdio.h>

ArrayList *createArrayList(int maxElementCount)
{
	ArrayList *tmp;

	if (maxElementCount <= 0)
		return (NULL);
	tmp = (ArrayList *)malloc(sizeof(ArrayList));
	if (tmp == NULL)
		return (NULL);
	tmp->maxElementCount = maxElementCount;
	tmp->currentElementCount = 0;
	tmp->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (tmp->pElement == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

void deleteArrayList(ArrayList *pList) // 댕글링포인터를 예방하기 위해서 이중포인터로 인자를 받을 수 있음.
{
	if (pList == NULL)
		return ;
	if (pList->pElement != NULL)
	{
		free(pList->pElement);
		pList->pElement = NULL;
	}
	free(pList);
}

int isArrayListFull(ArrayList *pList)
{
	if (pList == NULL)
		return FALSE;
	return (pList->currentElementCount == pList->maxElementCount);
}

int addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int i;
	int currentIndex;

	if (pList == NULL || pList->pElement == NULL)
		return (-1);
	if (isArrayListFull(pList))
		return (-1);
	if (position < 0 || position > currentIndex + 1)
		return (-1);
	currentIndex = pList->currentElementCount - 1;

	if (position < pList->currentElementCount)
	{
		i = currentIndex;
		while(i != position)
		{
			pList->pElement[i + 1] = pList->pElement[i];
			i--;
		}
	}
	pList->pElement[position] = element;
	pList->currentElementCount++;
	return (position);
}

int removeALElement(ArrayList *pList, int position)
{
	int i;
	int currentIndex;

	if (pList == NULL || pList->pElement == NULL)
		return (-1);
	if (position < 0 || position > currentIndex)
		i = position;
	currentIndex = pList->currentElementCount - 1;
	while (i < currentIndex)
	{
		pList->pElement[i] = pList->pElement[i + 1];
		i++;
	}
	pList->pElement[i].data = 0;
	pList->currentElementCount--;
	return (position);
}

ArrayListNode *getALElement(ArrayList *pList, int position)
{
	int currentIndex;

	if (pList == NULL || pList->pElement == NULL)
		return (NULL);
	currentIndex = pList->currentElementCount - 1;
	if (position < 0 || position > currentIndex)
		return (NULL);
	return (&pList->pElement[position]);
}

void displayArrayList(ArrayList *pList)
{
	int i;
	int currentIndex;

	if (pList == NULL || pList->pElement == NULL)
		return;
	i = 0;
	currentIndex = pList->currentElementCount - 1;
	while (i <= currentIndex)
	{
		printf("Index[%d] Data : %d\n", i, pList->pElement[i].data);
		i++;
	}
}
void clearArrayList(ArrayList *pList)
{
	if (pList == NULL)
		return;
	pList->currentElementCount = 0;
}

int getArrayListLength(ArrayList *pList)
{
	if (pList == NULL)
		return (-1);
	return (pList->maxElementCount);
}
