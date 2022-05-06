#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>

ArrayQueue *createArrayQueue(int maxElementCount) {
    ArrayQueue *queue;

    if (maxElementCount <= 0) {
        fprintf(stderr, "Invalid input");
        return NULL;
    }
    queue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
    if (queue == NULL)
        fprintf(stderr, "memory allocat fail");
    queue->pElement =
        (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
    if (queue->pElement == NULL)
        fprintf(stderr, "memory allocat fail");
    queue->maxElementCount = maxElementCount;
    return queue;
}

int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element) {
    int idx = 0;

    if (pQueue == NULL)
        return ERROR;

    if (pQueue->currentElementCount == pQueue->maxElementCount) {
        fprintf(stderr, "Queue is full");
        return FALSE;
    }
    //비었을 때 다르게 동작해야하는게 있나>? (빈 큐일 때, 프론트와 리어가
    //가르키고 있는 인덱스에 요소가 없다.)
    if (isArrayQueueEmpty(pQueue) == FALSE) {
        ++pQueue->rear;
        pQueue->rear = pQueue->rear % pQueue->maxElementCount;
    }
    idx = pQueue->rear;
    pQueue->pElement[idx] = element;
    ++pQueue->currentElementCount;
    return TRUE;
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue) {
    int idx = 0;

    if (pQueue == NULL || isArrayQueueEmpty(pQueue))
        return NULL;
    --pQueue->currentElementCount;

		idx = pQueue->front;

		if (pQueue->currentElementCount != 0) {
        ++pQueue->front;
        pQueue->rear = pQueue->rear % pQueue->maxElementCount;
    }

		return &pQueue->pElement[idx];
}

ArrayQueueNode *peekAQ(ArrayQueue *pQueue) {
	if (pQueue == NULL || isArrayQueueEmpty(pQueue))
        return NULL;
	return &pQueue->pElement[pQueue->front];
}

void deleteArrayQueue(ArrayQueue *pQueue) {
    if (pQueue == NULL)
        return;
    free(pQueue->pElement);
    pQueue->pElement = NULL;
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue *pQueue) {
	if (pQueue == NULL)
		return ERROR;
	return pQueue->currentElementCount == pQueue->maxElementCount;
}
int isArrayQueueEmpty(ArrayQueue *pQueue) {
	if (pQueue == NULL)
		return ERROR;
	return pQueue->currentElementCount == 0;
}