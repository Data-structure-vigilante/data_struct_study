#include "./LinkedStack/linkedstack.h"
#include "mapdef.h"

int maze[8][8] = {{0, 0, 1, 1, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 0, 0, 0, 1}, //
                  {1, 1, 1, 0, 1, 1, 1, 1}, //
                  {1, 1, 1, 0, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 0, 0, 0, 1}, //
                  {1, 0, 1, 1, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 0, 0, 0, 0}, //
                  {1, 1, 1, 1, 1, 1, 1, 0}};

int maze2[8][8] ={{0, 0, 1, 1, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 0, 0, 0, 1}, //
                  {1, 1, 1, 0, 1, 1, 1, 1}, //
                  {1, 1, 1, 0, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 0, 0, 0, 1}, //
                  {1, 0, 1, 1, 1, 1, 1, 1}, //
                  {1, 0, 0, 0, 1, 0, 0, 0}, //
                  {1, 1, 1, 1, 1, 1, 1, 0}};

int main() {

    LinkedStack *pathStack = createLinkedStack();
    MapPosition startpos = {0, 0, UP};
    MapPosition endpos = {7, 7, DOWN};
    printMaze(maze);
    printf("\n");
    findPath(maze, startpos, endpos, pathStack);
    showPath(pathStack, maze);
    return (0);
}