#include "arrayqueue.h"
#include <stdlib.h>
#include <stdio.h>

ArrayQueue* createArrayQueue(int maxElementCount) {
	ArrayQueue*	queue;

	if (maxElementCount <= 0) {
		fprintf(stderr, "Invalid input");
		return NULL;
	}
	queue = (ArrayQueue*)calloc(1, sizeof(ArrayQueue));
	if (queue == NULL)
		fprintf(stderr, "memory allocat fail");
	queue->pElement = (ArrayQueueNode*)calloc(maxElementCount, sizeof(ArrayQueueNode));
	if (queue->pElement == NULL)
		fprintf(stderr, "memory allocat fail");
	queue->maxElementCount = maxElementCount;
	queue->front = -1;
	queue->rear = -1;
	return queue;
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
	int idx = 0;

	if (pQueue == NULL)
		return ERROR;
	
	if (pQueue->currentElementCount == pQueue->maxElementCount) {
		fprintf(stderr, "Queue is full");
		return FALSE;
	}

	if (pQueue->currentElementCount == 0)
		++pQueue->front;

	idx = ++pQueue->rear;
	pQueue->pElement[idx] = element;
	++pQueue->currentElementCount;
	pQueue->rear = pQueue->rear % pQueue->maxElementCount;
	return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) {

}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue) {

}
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);