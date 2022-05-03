#include "mapdef.h"
#include "linkedstack.h"
#include <stdio.h>

static void initPathStack(MapPosition startPos, LinkedStack *pStack)
{
	pushLSMapPosition(pStack, startPos);
}

static switchDirection(enum Direction direction)
{
	if (direction == UP || direction == RIGHT)
		direction += 2;
	else
		direction -= 2;
	return (direction);
}

MapPosition lookPosition(MapPosition *position)
{
	int offset[2] = DIRECTION_OFFSETS[position->direction][2];
	MapPosition ret;

	ret.x = position->x + offset[0];
	ret.y = position->y + offset[1];
	ret.direction = switchDirection(position->direction);
}
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	initPathStack(startPos, pStack);
	MapPosition currentPos = startPos;

	while (1)
	{
		currentPos = lookPosition();
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
int pushLSMapPosition(LinkedStack *pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int height = 0;

	while (height < HEIGHT)
	{
		int width = 0;
		while (width < WIDTH)
		{
			printf("%d ", mazeArray[height][width]);
			++width;
		}
		printf("\n");
		++height;
	}
}