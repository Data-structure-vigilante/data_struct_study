#include "arraystack.h"
#include <stdlib.h>
#include <stdio.h>

ArrayStack *createArrayStack(int maxElementCount)
{
	ArrayStack *tmp;

	if (maxElementCount <= 0)
		return (NULL);
	tmp = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (tmp == NULL)
		return (NULL);
	tmp->maxElementCount = maxElementCount;
	tmp->currentElementCount = 0;
	tmp->pElement = (StackNode *)malloc(sizeof(StackNode) * maxElementCount);
	if (tmp->pElement == NULL)
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

int pushLS(ArrayStack *pStack, StackNode element)
{
	if (pStack == NULL || isArrayStackFull(pStack))
		return (-1);
	pStack->pElement[pStack->currentElementCount] = element;
	++pStack->currentElementCount;

	return (pStack->currentElementCount - 1);
}
StackNode *popLS(ArrayStack *pStack)
{
	if (pStack == NULL || isArrayStackEmpty(pStack))
		return (NULL);
	StackNode *tmp;

	tmp = (StackNode *)calloc(1, sizeof(StackNode));
	if (tmp == NULL)
		return (NULL);
	*tmp = pStack->pElement[pStack->currentElementCount - 1];
	pStack->pElement[pStack->currentElementCount - 1].data = 0;
	--pStack->currentElementCount;

	return (tmp);
}
StackNode *peekLS(ArrayStack *pStack)
{
	if (pStack == NULL || isArrayStackEmpty(pStack))
		return (NULL);

	return (&pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack *pStack)
{
	if (pStack == NULL)
		return;
	if (pStack->pElement != NULL)
	{
		free(pStack->pElement);
		pStack->pElement = NULL;
	}
	free(pStack);
}

int isArrayStackFull(ArrayStack *pStack)
{
	if (pStack == NULL)
		return FALSE;
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
	if (pStack == NULL)
		return FALSE;
	return (pStack->currentElementCount == 0);
}