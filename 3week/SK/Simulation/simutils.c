#include "simutils.h"
#include <pthread.h>
#include <stdlib.h>


static BankCounter *initBankCounter(int workerCount, int *currentTime, LinkedDeque *endDQ);

int initBank() {}



void *bankCounterLogic(void *counter) {}




int runBank(int currentTime, int closeTime, int workerCount, LinkedDeque *arrivalDQ) {
	if (currentTime < 0 || closeTime < currentTime || workerCount < 1)
		return FALSE;
	//worker , manager 출근시키기.
	int thr_id;
	pthread_t pthread[workerCount];
	LinkedDeque *waitDQ = createLinkedDeque();
	LinkedDeque *endDQ = createLinkedDeque();
	BankCounter *bankCounters = initBankCounters(workerCount, &currentTime, endDQ);
	Manager manager;
	for (int i =0; i < workerCount; ++i) {
		thr_id = pthread_create(&pthread[i], NULL, bankCounterLogic, (void*)&bankCounters[i]); //2
		if(thr_id < 0)
		{
			perror("pthread create error");
			exit(EXIT_FAILURE);
		}
	}

	while (currentTime < closeTime) {

		++currentTime;
	}

}

static BankCounter *initBankCounter(int workerCount, int *currentTime, LinkedDeque *endDQ) {
	BankCounter *bankCounters;

	bankCounters = (BankCounter *)calloc(workerCount, sizeof(BankCounter));
	if (bankCounters == NULL) {
			return NULL;
	}
	for(int i =0; i < workerCount; ++i) {
		bankCounters[i].currentTime = currentTime;
		bankCounters[i].endDQ = endDQ;
	}
	return bankCounters;
}

