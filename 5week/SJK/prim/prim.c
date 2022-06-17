#include "prim.h"
#include <stdlib.h>
#include <stdio.h>

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

int prim(ArrayGraph *graph, int startVertex)
{
	int		*from;
	int		*cost;
	int		**result;
	int		i;
	int		maxVertexCount;
	int		**adjEdges;
	int		min;

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
	if (min == INF)
		printf("NO PATH!!\n");
	result[0][i] = from[min];
	result[1][i] = min;

}