#ifndef __SIMUTILS_H__
#define __SIMUTILS_H__

#include "linkeddeque.h"
/// 매니저와, 워커가 존재
/// 매니저는 메인 쓰레드에서 동작, 워커는 워커쓰레드에서 동작
/// 😀 매니저의 책임
//// 1. 워커에게 고객 분배
//// 2. 시간 단위로 현재 워커들 작업상태 체크하여 출력
//// 3. 영업 시간 종료 후, 결산 및 보고 출력

//// 🧑‍⚕️ 워커의 책임
//// 1. 할당 받은 고객 응대
//// 2. 개인 레포트 업데이트.

typedef struct ReportType {
    int serviceUserCount;
    int totalWaitTime;
} Report;

typedef struct ManagerType {
    LinkedDeque *waitDQ;
		pthread_t *workers;
    Report finalReport;
} Manager;

typedef struct WorkerType {
    DequeNode *customerNode;
    Report workerReport;
} Worker;

typedef struct BankCounterType {
	Worker worker;
	LinkedDeque *endDQ;
	int *currentTime;
} BankCounter;

#endif