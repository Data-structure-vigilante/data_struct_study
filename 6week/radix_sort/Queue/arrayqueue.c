#include "arrayqueue.h"

ArrayQueue *createArrayQueue(int maxElementCount)
{
	if (maxElementCount <= 0)
		return (NULL);
	ArrayQueue *queue;
	queue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
	if (queue == NULL)
		return (NULL);
	queue->pElement =
		(ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
	queue->maxElementCount = maxElementCount;
	return (queue);
}

int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
	if (pQueue == NULL ||
		pQueue->maxElementCount == pQueue->currentElementCount)
		return (FALSE);
	if (pQueue->currentElementCount == 0)
	{
		pQueue->pElement[pQueue->rear % pQueue->maxElementCount] = element;
	}
	else
	{
		pQueue->pElement[++pQueue->rear % pQueue->maxElementCount] = element;
	}
	pQueue->rear = pQueue->rear % pQueue->maxElementCount;
	++pQueue->currentElementCount;
	return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue)
{
	if (pQueue == NULL || pQueue->currentElementCount == 0)
		return (NULL);
	--pQueue->currentElementCount;
	if (pQueue->front != pQueue->rear)
		++pQueue->front;
	pQueue->front = pQueue->front % pQueue->maxElementCount;
	return &pQueue->pElement[pQueue->front];
};
ArrayQueueNode *peekAQ(ArrayQueue *pQueue)
{
	if (pQueue == NULL || pQueue->currentElementCount == 0)
		return (NULL);
	return &pQueue->pElement[pQueue->front];
}
void deleteArrayQueue(ArrayQueue *pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue *pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}

int isArrayQueueEmpty(ArrayQueue *pQueue)
{
	return (pQueue->currentElementCount == 0);
}