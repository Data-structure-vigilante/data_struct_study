#ifndef __SIMLINKEDQueque_H__
#define __SIMLINKEDQueque_H__

#include "linkeddeque.h"
#include "simdef.h"

void insertCutomer(int arrivalTime, int processTime, LinkedDeque *pQueue);
void processArrival(int currentTime, LinkedDeque *pArrivalQueue, LinkedDeque *pWaitQueue); 
DequeNode* processServiceNodeStart(int currentTime, LinkedDeque *pWaitQueue); 
DequeNode* processServiceNodeEnd(int currentTime, DequeNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime);
void printSimCustomer(int currentTime, SimCustomer customer);
void printWaitQueueStatus(int currentTime, LinkedDeque *pWaitQueue); 
void printReport(LinkedDeque *pWaitQueue, int serviceUserCount, int totalWaitTime);
#endif