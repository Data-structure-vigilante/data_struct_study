#include "arrayqueue.h"

ArrayQueue *createArrayQueue(int maxElementCount)
{

	if (maxElementCount <= 0)
		return (NULL);

	ArrayQueue *queue;

	queue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
	if (queue == NULL)
		return (NULL);
	queue->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
	queue->maxElementCount = maxElementCount;

	return (queue);
}

int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
	if (pQueue == NULL ||
		pQueue->maxElementCount == pQueue->currentElementCount)
		return (FALSE);

	pQueue->pElement[pQueue->rear] = element;
	++pQueue->rear;

	return (TRUE);
}
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue);
ArrayQueueNode *peekAQ(ArrayQueue *pQueue);
void deleteArrayQueue(ArrayQueue *pQueue);
int isArrayQueueFull(ArrayQueue *pQueue);
int isArrayQueueEmpty(ArrayQueue *pQueue);