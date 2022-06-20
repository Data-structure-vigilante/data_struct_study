#ifndef DIJKSTRA_H
# include "../arrayGraph/arraygraph.h"

# define INF 999

int findMin(int *cost, int maxVertexCount);

void fillResult(int **result, int *from, int min, int i);

int	**getSpanningTree(int startVertex, int maxVertexCount, int **adjEdges);

void	switchZeroToInf(ArrayGraph *graph);

int **dijkstra(ArrayGraph *graph, int startVertex);


#endif