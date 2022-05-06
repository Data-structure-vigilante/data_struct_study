#include "linkeddeque.h"
#include <stdlib.h>
#include <stdio.h>

LinkedDeque* createLinkedDeque() {
	LinkedDeque *deque;

	deque = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
    if (deque == NULL)
        fprintf(stderr, "memory allocat fail");
	return deque;
}

inline void* createNode(DequeNode element) {
	DequeNode	*newNode;

	newNode = (DequeNode*)calloc(1, sizeof(DequeNode));
	if (newNode == NULL) {
		fprintf(stderr, "memory allocate fail");
		return newNode;
	}
	*newNode = element;
	return newNode;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element) {
	DequeNode	*newNode;
	if (pDeque == NULL) {
		return ERROR;
	}
	newNode = createNode(element);
	if (pDeque->pFrontNode == NULL && pDeque->pRearNode == NULL) {
		pDeque->pFrontNode = newNode;
		pDeque->pRearNode= newNode;
	}
	else {
		// pDeque->pRearNode->
	}
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element) {

}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) {

}

DequeNode* deleteRearLD(LinkedDeque* pDeque) {

}

DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque) {

}
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);