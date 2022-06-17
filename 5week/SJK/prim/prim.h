#ifndef PRIM_H
# include "../arrayGraph/arrayGraph.h"

# define INF 999

int findMin(int *cost, int maxVertexCount);

int fillResult(int **result, int *from, int min, int i);

int **getSpanningTree(int currentVertexCount, int **adjEdges, \
						int **result, int *from, int min,  \
						int *cost);

int **prim(ArrayGraph *graph, int startVertex);


#endif