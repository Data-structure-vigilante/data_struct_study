#ifndef __SIMDEF_H__
#define __SIMDEF_H__

typedef enum SimStatusType {
	ARRIVAL,
	START,
	END } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;
	int serviceTime;
	int startTime;
	int endTime;
} SimCustomer;

#endif