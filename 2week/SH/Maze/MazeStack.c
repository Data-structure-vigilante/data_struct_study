#include "Map.h"

int range(MapPosition map) {
    return 0 <= map.x && map.x < WIDTH && 0 <= map.y && map.y < HEIGHT;
}

int same(MapPosition *startPos, MapPosition endPos) {
    return (startPos->x == endPos.x && startPos->y == endPos.y);
}

MapPosition addPosition(MapPosition startPos) {
    startPos.x = startPos.x + DIRECTION_OFFSETS[startPos.direction][0];
    startPos.y = startPos.y + DIRECTION_OFFSETS[startPos.direction][1];
    return startPos;
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack) {
    MapPosition temp;
    StackNode node;

    node.data = startPos;
    mazeArray[startPos.x][startPos.y] = VISIT;
    pushLS(pStack, node);

    while (isLinkedStackEmpty(pStack) != 1) {
        if (same(&peekLS(pStack)->data, endPos))
            return;
        temp = addPosition(peekLS(pStack)->data);
        node.data = temp;
        if (range(temp) && mazeArray[temp.x][temp.y] == NOT_VISIT) {
            pushLS(pStack, node);
            mazeArray[temp.x][temp.y] = VISIT;
            continue;
        } else {
            ++peekLS(pStack)->data.direction;
        }
        if (peekLS(pStack)->data.direction == 4) {
            mazeArray[peekLS(pStack)->data.x][peekLS(pStack)->data.y] =
                NOT_VISIT;
            // int tempDirection = peekLS(pStack)->data.direction;
            free(popLS(pStack));
            ++peekLS(pStack)->data.direction == 4;
        }
    }
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d", mazeArray[i][j]);
        }
        printf("\n");
    }
}

void printMaze(int mazeArray[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d", mazeArray[i][j] == 2 ? 0 : mazeArray[i][j]);
        }
        printf("\n");
    }
}