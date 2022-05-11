#include "simutils.h"
#include "simlinkedqueue.h"
#include <pthread.h>
#include <stdlib.h>

static BankCounter *initBankCounter(int bankCount, int *currentTime,
                                    LinkedDeque *endDQ);
static Manager initManager(LinkedDeque *waitDQ, pthread_t *bankCounters);
int initBank() {}

void *bankCounterLogic(void *bankCounter) {
    BankCounter *bc;

    bc = bankCounter;
    if (bc->worker.customerNode == NULL)
}

// WorkerReadyCount * //

int runBank(int currentTime, int closeTime, int bankCount,
            LinkedDeque *arrivalDQ) {
    if (currentTime < 0 || closeTime < currentTime || bankCount < 1)
        return FALSE;

    pthread_t workerThread[bankCount];
    LinkedDeque *waitDQ = createLinkedDeque();
    LinkedDeque *endDQ = createLinkedDeque();
    BankCounter *bankCounters =
        initBankCounters(bankCount, &currentTime, endDQ);
    Manager manager = initManager(waitDQ, workerThread);
    int thr_id;

    for (int i = 0; i < bankCount; ++i) {
        thr_id = pthread_create(&workerThread[i], NULL, bankCounterLogic,
                                (void *)&bankCounters[i]); // 2
        if (thr_id < 0) {
            perror("pthread create error");
            exit(EXIT_FAILURE);
        }
    }

    // simulation
    while (currentTime < closeTime) {
        while(1) {
        	pthread_mutex_lock(&mutex);
            if (count == workercount)
                break;
            unlock
        }

        processArrival(currentTime, arrivalDQ, waitDQ);
        // 대기열에서 분배하는 로직

        // 작업 완료된 후 처리
        ///	1. woker들이 자신의 일을 처리 후 덱에 삽입.

        provideService(bankCounters);
        /// 2. manager가 정보를 취합.
        ++currentTime;
    }
}

static BankCounter *initBankCounter(int bankCount, int *currentTime,
                                    LinkedDeque *endDQ) {
    BankCounter *bankCounters;

    bankCounters = (BankCounter *)calloc(bankCount, sizeof(BankCounter));
    if (bankCounters == NULL) {
        return NULL;
    }
    for (int i = 0; i < bankCount; ++i) {
        bankCounters[i].currentTime = currentTime;
        bankCounters[i].endDQ = endDQ;
    }
    return bankCounters;
}

static Manager initManager(LinkedDeque *waitDQ, pthread_t *bankCounters) {
    Manager manager;

    manager.waitDQ = waitDQ;
    manager.workerThread = bankCounters;
    manager.finalReport.serviceUserCount = 0;
    manager.finalReport.totalWaitTime = 0;
    return manager;
}