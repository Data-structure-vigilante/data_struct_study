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

void insertCustomer(int arrivalTime, int processTime, LinkedDeque *pQueue) {
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
                    LinkedDeque *pWaitQueue) {
    if (isLinkedDequeEmpty(pArrivalQueue))
        return;
    DequeNode *tmp = deleteFrontLD(pArrivalQueue);
    insertRearLD(pWaitQueue, *tmp);
    free(tmp);
    return;
}
DequeNode *processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue) {
    DequeNode *node;
    DequeNode *temp;

    node = peekFrontLD(pWaitQueue);
    if (currentTime - node->data.startTime == node->data.serviceTime) {
        node = deleteFrontLD(pWaitQueue);
        node->data.status = end;
        node->data.endTime = currentTime;
    } else
        node = NULL;
    temp = peekFrontLD(pWaitQueue);
    if (temp && temp->data.status == arrival) {
        temp->data.status = start;
        temp->data.startTime = currentTime;
    }
    return node;
}
DequeNode *processServiceNodeEnd(int currentTime, DequeNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime) {
    *pTotalWaitTime +=
        pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
    *pServiceUserCount += 1;
    return pServiceNode;
}
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue);
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount,
                 int totalWaitTime);

// {3,2,1,1,3}
int main(int ac, char **av) {
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
    while (i < ac || !isLinkedDequeEmpty(pWaitQueue)) {
        if (t % 2 == 0 && i < ac)
            insertCustomer(t, *av[i++] - '0', pArrivalQueue);
        processArrival(t, pArrivalQueue, pWaitQueue);
        if (node != NULL)
            free(processServiceNodeEnd(t, node, &serviceUserCount,
                                       &totalWaitTime));
        node = processServiceNodeStart(t, pWaitQueue);
        ++t;
    }
    if (node != NULL)
        free(processServiceNodeEnd(t, node, &serviceUserCount, &totalWaitTime));
    printf("wait Time: %d\n", totalWaitTime);
    printf("user Count: %d\n", serviceUserCount);
    return (0);
}