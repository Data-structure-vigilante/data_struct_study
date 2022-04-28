#include "arraystack.h"

ArrayStack *createArrayStack(int maxElementCount);
int pushLS(ArrayStack *pStack, StackNode element);
StackNode *popLS(ArrayStack *pStack);
StackNode *peekLS(ArrayStack *pStack);
void deleteArrayStack(ArrayStack *pStack);
int isArrayStackFull(ArrayStack *pStack);
int isArrayStackEmpty(ArrayStack *pStack);