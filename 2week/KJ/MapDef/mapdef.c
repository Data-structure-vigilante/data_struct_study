#include "mapdef.h"
#include "linkedstack.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos,
              MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack *pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);
void parseMap(char* filepath, int *mazeArray[][]) {

}
LinkedStack *searchPath(int map[][], MapPosition startPos) {
    LinkedStack *result;

    //도착 지점을 찾았거나, 모든 경로가 막혔을 경우.
    while () {
        // 현재 보고있는 좌표가 벽이다.
        // -> 다른 방향을 본다.

        // 현재 보고있는 좌표가 방문한 곳이다.
        // -> 다른 방향을 본다.

        // 현재 보고있는 좌표가 방문하지 않은 곳이다.
        // -> 간다

        // 사 방에 대해서 확인을 다 했는데도 위 조건에 맞게 처리되지 않았을
        // 경우에만 여기로 네 방향으 모두 벽이거나 방문했다면 빠구할 때는 pop
        // 타겟을 벽으로 변경

        //탈출 조건
        // 1. 현재 타겟 포지션이 Goal이다.
        // 2. 스택이 엠티다.
    }
}