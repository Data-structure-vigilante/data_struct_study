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

int maze2[8][8] = {{0, 0, 1, 1, 1, 1, 1, 1}, //
                   {1, 0, 0, 0, 0, 0, 0, 1}, //
                   {1, 1, 1, 0, 1, 1, 1, 1}, //
                   {1, 1, 1, 0, 1, 1, 1, 1}, //
                   {1, 0, 0, 0, 0, 0, 0, 1}, //
                   {1, 0, 1, 1, 1, 1, 1, 1}, //
                   {1, 0, 0, 0, 1, 0, 0, 0}, //
                   {1, 1, 1, 1, 1, 1, 1, 0}};

int maze3[HEIGHT][WIDTH] = {{0, 0, 0, 0, 0, 0, 1, 1}, //
                            {1, 0, 1, 1, 1, 1, 1, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1},
                            {1, 0, 1, 1, 1, 1, 1, 1},
                            {1, 0, 1, 1, 0, 0, 0, 0},
                            {1, 0, 0, 1, 0, 1, 1, 1},
                            {1, 1, 0, 0, 0, 1, 1, 1}};

int main()
{

    LinkedStack *pathStack = createLinkedStack();
    MapPosition startpos = {0, 0, UP};
    MapPosition endpos = {7, 5, DOWN};
    printMaze(maze3);
    printf("\n");
    findPath(maze3, startpos, endpos, pathStack);
    showPath(pathStack, maze3);
    return (0);
}