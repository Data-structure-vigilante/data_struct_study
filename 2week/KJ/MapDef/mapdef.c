#include "mapdef.h"
#include "./LinkedStack/linkedstack.h"
#include <stdio.h>

static void initPathStack(MapPosition startPos, LinkedStack *pStack);
static MapPosition lookPosition(MapPosition *position);
static enum Direction switchDirection(enum Direction direction);
static int isOutofMap(MapPosition *position);
static int isBlocked(enum PosStatus posStatus);
static int isStuck(int mazeArray[HEIGHT][WIDTH], MapPosition pos);
static void rotateDirectionClockwise(StackNode *top);
static int isSamePos(MapPosition *posA, MapPosition *posB);

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack) {
    initPathStack(startPos, pStack);
    MapPosition currentPos;

    while (1) {
        currentPos = lookPosition(&peekLS(pStack)->data);
        // 현재 보고있는 좌표가 벽이다. || 현재 보고있는 좌표가 방문한 곳이다.
        // -> 다른 방향을 본다.
        if (isOutofMap(&currentPos) ||
            isBlocked(mazeArray[currentPos.y][currentPos.x]))
            rotateDirectionClockwise(peekLS(pStack));

        // 현재 보고있는 좌표가 방문하지 않은 곳이다.
        // -> 간다
        else if (!isBlocked(mazeArray[currentPos.y][currentPos.x])) {
            pushLSMapPosition(pStack, currentPos);
            mazeArray[currentPos.y][currentPos.x] = VISIT;
        }
        // pop
        if (isStuck(mazeArray, peekLS(pStack)->data)) {
        }

        // 사 방에 대해서 확인을 다 했는데도 위 조건에 맞게 처리되지 않았을
        // 경우에만 여기로 네 방향 모두 벽이거나 방문했다면 빠구할 때는 pop

        //탈출 조건
        // 1. 현재 타겟 포지션이 Goal이다.
        // 2. 스택이 엠티다.
        if (isSamePos(&currentPos, &endPos) || isLinkedStackEmpty(pStack))
            break;
    }
}

static void initPathStack(MapPosition startPos, LinkedStack *pStack) {
    pushLSMapPosition(pStack, startPos);
}

MapPosition lookPosition(MapPosition *position) {
    int *offset = DIRECTION_OFFSETS[position->direction];

    MapPosition ret;

    ret.x = position->x + offset[0];
    ret.y = position->y + offset[1];
    ret.direction = switchDirection(position->direction);
    return ret;
}

static enum Direction switchDirection(enum Direction direction) {
    if (direction == UP || direction == RIGHT)
        direction += 2;
    else
        direction -= 2;
    return (direction);
}

static int isOutofMap(MapPosition *position) {
    if (position->x < 0 || position->x >= WIDTH || //
        position->y < 0 || position->y >= HEIGHT)
        return TRUE;
    return FALSE;
}

static int isBlocked(enum PosStatus posStatus) {
    if (posStatus == WALL || posStatus == VISIT)
        return TRUE;
    else
        return FALSE;
}

static void rotateDirectionClockwise(StackNode *top) {
    ++top->data.direction;
    if (top->data.direction > 3)
        top->data.direction -= 3;
};

static int isStuck(int mazeArray[HEIGHT][WIDTH], MapPosition pos) {
    pos.x += 1;
    if (isOutofMap(&pos) || isBlocked(mazeArray[pos.y][pos.x]))
        return TRUE;
    pos.x -= 2;
    if (isOutofMap(&pos) || isBlocked(mazeArray[pos.y][pos.x]))
        return TRUE;
    pos.y += 1;
    if (isOutofMap(&pos) || isBlocked(mazeArray[pos.y][pos.x]))
        return TRUE;
    pos.y -= 2;
    if (isOutofMap(&pos) || isBlocked(mazeArray[pos.y][pos.x]))
        return TRUE;
    return FALSE;
}

static int isSamePos(MapPosition *posA, MapPosition *posB) {
    return (posA->x == posB->x && posA->y == posB->y);
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]) {
    StackNode *top_node;

    while ((top_node = popLS(pStack)) != NULL) {
        mazeArray[top_node->data.y][top_node->data.x] = '*';
    }
    printMaze(mazeArray);
}

void printMaze(int mazeArray[HEIGHT][WIDTH]) {
    int height = 0;

    while (height < HEIGHT) {
        int width = 0;
        while (width < WIDTH) {
            printf("%d ", mazeArray[height][width]);
            ++width;
        }
        printf("\n");
        ++height;
    }
}