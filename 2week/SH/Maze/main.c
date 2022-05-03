#include "Map.h"
#include "MazeStack.h"

int main(void) {
	int maze[HEIGHT][WIDTH];
	LinkedStack *stack;
	MapPosition start;
	MapPosition end;

	start.x = 0;
	start.y = 0;
	start.direction = 0;

	end.x = 7;
	end.y = 7;
	end.direction = 0;

	stack = createLinkedStack();
	findPath(maze, start, end, stack);
	return;
}