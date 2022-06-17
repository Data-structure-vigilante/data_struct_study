#ifndef PRIM_H
# include "../arrayGraph/arraygraph.h"

# define INF 999

int findMin(int *cost, int maxVertexCount);

void fillResult(int **result, int *from, int min, int i);

void	getSpanningTree(int maxVertexCount, int **adjEdges, \
						int **result, int *from,  \
						int *cost);

void	switchZeroToInf(ArrayGraph *graph);

int **prim(ArrayGraph *graph, int startVertex);


#endif