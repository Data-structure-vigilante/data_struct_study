#include "mapdef.h"
#include "./LinkedStack/linkedstack.h"
#include <stdio.h>

static void initPathStack(MapPosition startPos, LinkedStack *pStack,
                          int mazeArray[HEIGHT][WIDTH]);
static MapPosition getLookPosition(MapPosition *position);
static enum Direction switchDirection(enum Direction direction);
static int isBlocked(int mazeArray[HEIGHT][WIDTH], MapPosition *position);
static int isBlockedAllDirection(MapPosition *pos);
static void rotateDirectionClockwise(StackNode *top);
static int isSamePos(MapPosition *posA, MapPosition *posB);
static void cleanUpMaze(int maze[HEIGHT][WIDTH]);

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack)
{
    initPathStack(startPos, pStack, mazeArray);
    MapPosition lookPos;

    while (1)
    {
        lookPos = getLookPosition(&peekLS(pStack)->data);

        if (isBlocked(mazeArray, &lookPos))
            rotateDirectionClockwise(peekLS(pStack));
        else
        {
            pushLSMapPosition(pStack, lookPos);
            mazeArray[lookPos.y][lookPos.x] = VISIT;
        }
        if (isBlockedAllDirection(&peekLS(pStack)->data))
            free(popLS(pStack));
        if (isSamePos(&lookPos, &endPos) || isLinkedStackEmpty(pStack))
            break;
    }
    cleanUpMaze(mazeArray);
}

static void initPathStack(MapPosition startPos, LinkedStack *pStack,
                          int mazeArray[HEIGHT][WIDTH])
{
    pushLSMapPosition(pStack, startPos);
    mazeArray[startPos.y][startPos.x] = VISIT;
}

MapPosition getLookPosition(MapPosition *position)
{
    int *offset = DIRECTION_OFFSETS[position->direction];

    MapPosition ret;

    ret.x = position->x + offset[0];
    ret.y = position->y + offset[1];
    ret.direction = UP;
    return ret;
}

static int isBlocked(int mazeArray[HEIGHT][WIDTH], MapPosition *position)
{
    enum PosStatus status;

    if (position->x < 0 || position->x >= WIDTH || //
        position->y < 0 || position->y >= HEIGHT)
        return TRUE;
    status = mazeArray[position->y][position->x];
    if (status == WALL || status == VISIT)
        return TRUE;
    return FALSE;
}

static void rotateDirectionClockwise(StackNode *top) { ++top->data.direction; };
static int isBlockedAllDirection(MapPosition *pos)
{
    if (pos->direction == STUCK)
        return TRUE;
    return FALSE;
}

static int isSamePos(MapPosition *posA, MapPosition *posB)
{
    return (posA->x == posB->x && posA->y == posB->y);
}

static void cleanUpMaze(int maze[HEIGHT][WIDTH])
{
    int height = 0;

    while (height < HEIGHT)
    {
        int width = 0;
        while (width < WIDTH)
        {
            if (maze[height][width] == 2)
                maze[height][width] = 0;
            ++width;
        }
        ++height;
    }
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
    StackNode *top_node;

    while ((top_node = popLS(pStack)) != NULL)
    {
        mazeArray[top_node->data.y][top_node->data.x] = 5;
        free(top_node);
    }
    printMaze(mazeArray);
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
    int height = 0;

    while (height < HEIGHT)
    {
        int width = 0;
        while (width < WIDTH)
        {
            if (mazeArray[height][width] == 0)
                printf("X ");
            if (mazeArray[height][width] == 1)
                printf("* ");
            if (mazeArray[height][width] == 5)
                printf("P ");
            ++width;
        }
        printf("\n");
        ++height;
    }
}