#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedStackType LinkedStack;
typedef struct StackNodeType StackNode;
typedef struct MapPositionType MapPosition;
LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, StackNode element);
StackNode *popLS(LinkedStack *pStack);
StackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
StackNode *getLLElement(LinkedStack *pStack, int position);
int addLLElement(LinkedStack *pStack, int position, StackNode element);
int isLinkedStackEmpty(LinkedStack *pStack);
void deleteLinkedList(LinkedStack *pStack);

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
    {0, -1}, // ¿ß¬ ¿∏∑Œ ¿Ãµø.
    {1, 0},  // ø¿∏•¬ ¿∏∑Œ ¿Ãµø.
    {0, 1},  // æ∆∑°¬ ¿∏∑Œ ¿Ãµø.
    {-1, 0}  // øﬁ¬ ¿∏∑Œ ¿Ãµø.
};

enum PosStatus { NOT_VISIT = 0, WALL = 1, VISIT = 2 };

struct MapPositionType {
    int x;         // «ˆ¿Á ¿ßƒ° x¡¬«•.
    int y;         // «ˆ¿Á ¿ßƒ° y¡¬«•.
    int direction; // ¥Ÿ¿Ω ¿ßƒ°∑Œ ¿Ãµø πÊ«'.
};

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

struct StackNodeType {
    MapPosition data;
    struct StackNodeType *pLink;
};

struct LinkedStackType {
    int currentElementCount; // 현재 원소의 개수
    StackNode *pTopElement;  // Top 노드의 포인터
};

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0
#define ERROR -1

#endif
