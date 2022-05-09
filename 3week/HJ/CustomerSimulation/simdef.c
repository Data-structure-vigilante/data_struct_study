#include "simdef.h"

// typedef enum SimStatusType
// {
// 	arrival,
// 	start,
// 	end
// } SimStatus;
// typedef struct SimCustomerType
// {
// 	SimStatus status;
// 	int arrivalTime;
// 	int serviceTime;
// 	int startTime;
// 	int endTime;
// } SimCustomer;

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue)
{
	SimCustomer customer;
	DequeNode node;

	customer.arrivalTime = arrivalTime;
	customer.serviceTime = processTime;
	customer.startTime = 0;
	customer.endTime = 0;
	node.data = customer;
	insertRearLD(pQueue, node);
	return;
}
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue)
{
	if (currentTime % 2 == 1)
		return;
	DequeNode *tmp = deleteFrontLD(pArrivalQueue);
	insertRearLD(pWaitQueue, *tmp);
	free(tmp);
	return;
}
DequeNode *processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue);
DequeNode *processServiceNodeEnd(int currentTime, DequeNode *pServiceNode,
								 int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime);

// {3,2,1,1,3}
int main(int ac, char **av)
{
	LinkedDeque *pArrivalQueue;
	LinkedDeque *pWaitQueue;
	int t = 0;
	int i = 1;

	pArrivalQueue = createLinkedDeque();
	pWaitQueue = createLinkedDeque();
	while (i < ac)
	{
		DequeNode node;
		insertCustomer((i - 1) * 2, *av[i] - '0', pArrivalQueue);
		++i;
	}
	// while (1)
	// {
	// 	processArrival(t, pArrivalQueue, pWaitQueue);

	// 	++t;
	// }

	printf("%d\n", deleteFrontLD(pArrivalQueue)->data.serviceTime);
	printf("%d\n", deleteFrontLD(pArrivalQueue)->data.serviceTime);
	printf("%d\n", deleteFrontLD(pArrivalQueue)->data.serviceTime);
	printf("%d\n", deleteFrontLD(pArrivalQueue)->data.serviceTime);
	printf("%d\n", deleteFrontLD(pArrivalQueue)->data.serviceTime);

	return (0);
}