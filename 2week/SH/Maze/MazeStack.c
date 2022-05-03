#include "MazeStack.h"

int range(MapPosition map) {
	return 0 <= map.x && map.x < WIDTH && 0 <= map.y && map.y < HEIGHT;
}

int	same(MapPosition *startPos, MapPosition endPos) {
	return (startPos->x == endPos.x && startPos->y == endPos.y);
}

MapPosition addPosition(MapPosition startPos) {
	startPos.x = startPos.x + DIRECTION_OFFSETS[startPos.direction][0];
	startPos.y = startPos.y + DIRECTION_OFFSETS[startPos.direction][1];
	return startPos;
}

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack) {
	MapPosition temp;
	pushLS(pStack, startPos);

	while (isLinkedStackEmpty(pStack) != 1) {
		if (same(&peekLS(pStack)->data, endPos))
			return;
		temp = addPosition(peekLS(pStack)->data);
		if (range(temp) && mazeArray[temp.x][temp.y] == NOT_VISIT) {
			pushLS(pStack, temp);
			mazeArray[temp.x][temp.y] = VISIT;
			continue;
		}
		else {
			temp = peekLS(pStack)->data;
			++temp.direction;
		}
		if (temp.direction == 4)
			free(popLS(pStack));
	}
}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data) {

}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]) {
	while (isLinkedStackEmpty(pStack) != 1) {

	}
}

void printMaze(int mazeArray[HEIGHT][WIDTH]) {

}