#include "simlinkedqueue.h"
#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pDeque) {
	DequeNode node;

	node.data.arrivalTime = arrivalTime;
	node.data.serviceTime = processTime;
	node.data.endTime = 0;
	node.data.startTime = 0;
	node.data.status = ARRIVAL;
	node.pLLink = NULL;
	node.pRLink = NULL;
	insertRearLD(pDeque, node);
}

static int isArrived(int currentTime, DequeNode* node) {
	if (node == NULL || node->pLLink == node)
		return FALSE;
	return node->data.arrivalTime == currentTime;
}

void processArrival(int currentTime, LinkedDeque *pArrivalDeque, LinkedDeque *pWaitDeque) {
	while (isArrived(currentTime, peekFrontLD(pArrivalDeque))) {
		insertRearLD(pWaitDeque, *peekFrontLD(pArrivalDeque));
		free(popFrontLD(pArrivalDeque));
	}
}

DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitDeque) {
	DequeNode* temp = popFrontLD(pWaitDeque);
	temp->data.startTime = currentTime;
	temp->data.status = START;
	return temp;
}

DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime) {
	pServiceNode->data.endTime = currentTime;
	pServiceNode->data.status = END;
	*pServiceUserCount += 1;
	*pTotalWaitTime += pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	return pServiceNode;
}

//
void printSimCustomer(int currentTime, SimCustomer customer) {
	printf("고객 도착 시간 : %d\n고객 서비스 이용 시간 : %d\n고객 서비스 시작 시간 : %d\n고객 서비스 종료 시간 : %d\n",
	customer.arrivalTime, customer.serviceTime, customer.startTime, customer.endTime);
	switch (customer.status)
	{
		case ARRIVAL:
		printf("서비스 대기중\n");
		break;
		case START:
		printf("서비스 이용중\n");
		break;
		case END:
		printf("서비스 이용 종료\n");
		break;
	}
	printf("\n");
}

void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue) {
	DequeNode* node;

	printf("현재시간 : %d\n", currentTime);
	node = pWaitQueue->headerNode.pRLink;
	while (node != &pWaitQueue->headerNode) {
		printSimCustomer(currentTime, node->data);
		node = node->pRLink;
	}
}

void printReport(LinkedDeque *pWaitDeque, int serviceUserCount, int totalWaitTime) {
	printf("하루 이용 고객 수 : %d\n", serviceUserCount);
	printf("고객 총 대기 시간 : %d\n", totalWaitTime);
	if (isLinkedDequeEmpty(pWaitDeque) == FALSE)
		printf("%d의 고객의 업무를 처리하지 못했습니다.", pWaitDeque->currentElementCount);
}