#ifndef __SIMUTILS_H__
#define __SIMUTILS_H__

#include "linkeddeque.h"
typedef struct ReportType {
    int currentTime;
    int serviceUserCount;
    int totalWaitTime;
} Report;

typedef struct ManagerType {
    LinkedDeque *waitDQ;
    Report report;
} Manager;

typedef struct WorkerType {
    DequeNode *customerNode;
    Report report;
} Worker;

#endif