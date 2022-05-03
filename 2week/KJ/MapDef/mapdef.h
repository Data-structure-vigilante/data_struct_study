#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

typedef struct LinkedStackType LinkedStack;

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
    {0, -1}, {1, 0}, {0, 1}, {-1, 0}};

enum Direction {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    STUCK = 4,
};

enum PosStatus { NOT_VISIT = 0, WALL = 1, VISIT = 2 };

typedef struct MapPositionType {
    int x;
    int y;
    enum Direction direction;
} MapPosition;

void printMaze(int mazeArray[HEIGHT][WIDTH]);
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);

#endif
