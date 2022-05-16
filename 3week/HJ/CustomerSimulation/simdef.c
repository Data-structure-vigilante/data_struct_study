#include "simdef.h"

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
	SimCustomer customer;
	DequeNode node;

	customer.status = arrival;
	customer.arrivalTime = arrivalTime;
	customer.serviceTime = processTime;
	customer.startTime = 0;
	customer.endTime = 0;
	node.data = customer;
	insertRearLD(pQueue, node);
	return;
}
void processArrival(int currentTime, LinkedDeque *pArrivalQueue,
					LinkedDeque *pWaitQueue)
{
	if (isLinkedDequeEmpty(pArrivalQueue))
		return;
	DequeNode *tmp = deleteFrontLD(pArrivalQueue);
	insertRearLD(pWaitQueue, *tmp);
	free(tmp);
	return;
}
DequeNode *processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue)
{
	DequeNode *node;
	DequeNode *temp;

	node = deleteFrontLD(pWaitQueue);
	if (node)
	{
		node->data.status = start;
		node->data.startTime = currentTime;
		printSimCustomer(currentTime, node->data);
	}

	return node;
}
DequeNode *processServiceNodeEnd(int currentTime, DequeNode *pServiceNode,
								 int *pServiceUserCount, int *pTotalWaitTime)
{
	if (currentTime - pServiceNode->data.startTime == pServiceNode->data.serviceTime)
	{
		pServiceNode->data.status = end;
		pServiceNode->data.endTime = currentTime;
		printSimCustomer(currentTime, pServiceNode->data);
		*pServiceUserCount += 1;
		*pTotalWaitTime +=
			pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
	}
	return pServiceNode;
}
void printSimCustomer(int currentTime, SimCustomer customer)
{
	if (customer.status == start)
	{
		printf("------------------------\n");
		printf("%d sec, Starting service\n", currentTime);
	}
	if (customer.status == end)
		printf("%d sec, Service end\n", currentTime);
}
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue)
{

	DequeNode *node = peekFrontLD(pWaitQueue);
	if (node)
		printf("%d sec, Customer is waiting for %d sec\n", currentTime, currentTime - node->data.arrivalTime);
}
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount,
				 int totalWaitTime)
{
	printf("------------------------\n");
	if (isLinkedDequeEmpty(pWaitQueue))
		printf("Simulation end\n");
	printf("Total wait Time: %d\n", totalWaitTime);
	printf("Service user Count: %d\n", serviceUserCount);
	printf("------------------------\n");
}

int main(int ac, char **av)
{
	LinkedDeque *pArrivalQueue;
	LinkedDeque *pWaitQueue;
	DequeNode *node;
	int t = 0;
	int i = 1;
	int serviceUserCount = 0;
	int totalWaitTime = 0;

	pArrivalQueue = createLinkedDeque();
	pWaitQueue = createLinkedDeque();
	node = NULL;
	while (i < ac || node)
	{
		if (t % 2 == 0 && i < ac)
			insertCustomer(t, *av[i++] - '0', pArrivalQueue);
		processArrival(t, pArrivalQueue, pWaitQueue);
		if (node)
		{
			node = processServiceNodeEnd(t, node, &serviceUserCount, &totalWaitTime);
			if (node->data.status == end)
			{
				printWaitQueueStatus(t, pWaitQueue);
				node = processServiceNodeStart(t, pWaitQueue);
			}
		}
		else
			node = processServiceNodeStart(t, pWaitQueue);
		++t;
	}

	printReport(pWaitQueue, serviceUserCount, totalWaitTime);
	return (0);
}