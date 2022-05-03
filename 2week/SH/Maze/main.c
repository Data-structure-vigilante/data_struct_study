#include "Map.h"
#include "MazeStack.h"

int maze[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0, 0, 1, 1}, {1, 0, 1, 1, 1, 1, 1, 1},
                           {1, 0, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 1, 1, 1, 1},
                           {1, 0, 1, 1, 1, 1, 1, 1}, {1, 0, 1, 1, 0, 0, 0, 0},
                           {1, 0, 0, 1, 0, 1, 1, 1}, {1, 1, 0, 0, 0, 1, 1, 1}};

int main(void) {

    LinkedStack *stack;
    MapPosition start;
    MapPosition end;

    start.x = 0;
    start.y = 0;
    start.direction = 0;

    end.x = 5;
    end.y = 7;
    end.direction = 0;

    stack = createLinkedStack();
    printMaze(maze);
    findPath(maze, start, end, stack);
    showPath(stack, maze);
    return 0;
}
