#include "prim.h"
#include <stdlib.h>

int findMin(int *cost, int maxVertexCount)
{
	int		min;
	int		idx1;

	min = INF;
	idx1 = 0;
	while(idx1 < maxVertexCount)
	{
		if (cost[idx1] != 0 && cost[idx1] < min)
			min = cost[idx1];
		++idx1;
	}
	return (min);
}

int fillResult(int **result, int *from, int min, int i)
{
	result[0][i] = from[min];
	result[1][i] = min;
}

int **getSpanningTree(int currentVertexCount, int **adjEdges, int **result, int *from, int min, int *cost)
{
	int i;
	int j;

	i = 0;
	while (i < currentVertexCount - 1)
	{
		fillResult(result, from, min, i);
		cost[min] = 0;
		j = 1;
		while (j < currentVertexCount)
		{
			if (adjEdges[min][j] < cost[j])
			{
				from[j] = min;
				cost[j] = adjEdges[min][j];
			}
			++j;
		}
		++i;
	}
}

int **prim(ArrayGraph *graph, int startVertex)
{
	int		*from;
	int		*cost;
	int		**result;
	int		i;
	int		maxVertexCount;
	int		**adjEdges;
	int		min;
	int		j;

	adjEdges = graph->ppAdjEdge;
	maxVertexCount = graph->maxVertexCount;
	from = (int *)calloc(graph->maxVertexCount, sizeof(int));
	cost = (int *)calloc(graph->maxVertexCount, sizeof(int));
	result = (int **)calloc(2, sizeof(int *));
	i = 0;
	while (i < 2)
		result[i++] = (int *)calloc(graph->maxVertexCount, sizeof(int)); //할당

	for (int i = 0; i < maxVertexCount; ++i)
	{
		from[i] = startVertex;
		cost[i] = adjEdges[startVertex][i];
		if (i != startVertex)
			if (cost[i] == 0)
				cost[i] == INF;
		else
			from[i] = 0;
	}
	min = findMin(cost, maxVertexCount);
	i = 0;
	getSpanningTree(graph->currentVertexCount, adjEdges, \
					result, from, min, cost);
	return (result);
}