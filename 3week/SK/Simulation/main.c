#include "simlinkedqueue.h"
#include "simutils.h"
#include <stdlib.h>

// 1. 어라이벌큐 만들고
// 2. 시간 초기화 후 시간흐름 반복문 돌리면서 로직 실행
// 3. 결과 출력
LinkedDeque *createArrivalQueue() {
    LinkedDeque *arrivalDequeue = createLinkedDeque();
    insertCutomer(0, 2, arrivalDequeue);
    insertCutomer(0, 1, arrivalDequeue);
    insertCutomer(1, 1, arrivalDequeue);
    insertCutomer(4, 2, arrivalDequeue);
    insertCutomer(5, 1, arrivalDequeue);
    return arrivalDequeue;
};

int main() {
    Report report = {0, 0, 0};
    LinkedDeque *arraivalDQ = createArrivalQueue();
		LinkedDeque *waitDQ = createLinkedDeque();
		DequeNode *serviceNode = NULL;

	// 영업시간 동안
		while (report.currentTime < 7) {
			// 사람들이 도착한다.
			processArrival(report.currentTime, arraivalDQ, waitDQ);

			// 워커가 대기 중인 사람을 가져다가 일한다. 워커 쓰레드 함수.
			++report.currentTime;
		}
    printWaitQueueStatus(0, waitDQ);
}