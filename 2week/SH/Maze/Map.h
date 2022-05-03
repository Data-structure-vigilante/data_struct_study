#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
		{0, -1},		// ¿ß¬ ¿∏∑Œ ¿Ãµø.
		{1, 0},			// ø¿∏•¬ ¿∏∑Œ ¿Ãµø.
		{0, 1},			// æ∆∑°¬ ¿∏∑Œ ¿Ãµø.
		{-1, 0}			// øﬁ¬ ¿∏∑Œ ¿Ãµø.
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2  };

typedef struct MapPositionType
{
	int x;				// «ˆ¿Á ¿ßƒ° x¡¬«•.
	int y;				// «ˆ¿Á ¿ßƒ° y¡¬«•.
	int direction;		// ¥Ÿ¿Ω ¿ßƒ°∑Œ ¿Ãµø πÊ«'.
} MapPosition;

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]); void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif
