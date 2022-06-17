#include "prim.h"
#include <stdlib.h>

int findMin(int *cost, int maxVertexCount)
{
	int		minIdx;
	int		idx1;

	minIdx = INF;
	idx1 = 0;
	while(idx1 < maxVertexCount)
	{
		if (cost[idx1] != 0 && cost[idx1] < minIdx)
			minIdx = cost[idx1];
		++idx1;
	}
	idx1 = 0;
	while (idx1 < maxVertexCount)
	{
		if (cost[idx1] == minIdx)
			break ;
		++idx1;
	}
	return (idx1);
}

void fillResult(int **result, int *from, int minIdx, int i)
{
	result[0][i] = from[minIdx];
	result[1][i] = minIdx;
}

void	getSpanningTree(int maxVertexCount, int **adjEdges, int **result, int *from, int *cost)
{
	int i;
	int j;
	int minIdx;

	i = 0;
	while (i < maxVertexCount - 1)
	{
		minIdx = findMin(cost, maxVertexCount);
		fillResult(result, from, minIdx, i);
		cost[minIdx] = 0;
		j = 0;
		while (j < maxVertexCount)
		{
			if (adjEdges[minIdx][j] < cost[j])
			{
				from[j] = minIdx;
				cost[j] = adjEdges[minIdx][j];
			}
			++j;
		}
		++i;
	}
}

void	switchZeroToInf(ArrayGraph *graph)
{
	int		i;
	int		j;
	int		**matrix;

	matrix = graph->ppAdjEdge;
	i = 0;
	while (i < graph->maxVertexCount)
	{
		j = 0;
		while (j < graph->maxVertexCount)
		{
			if (matrix[i][j] == 0 && i != j)
				matrix[i][j] = INF;
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
	int		minIdx;
	int		j;

	adjEdges = graph->ppAdjEdge;
	switchZeroToInf(graph);
	maxVertexCount = graph->maxVertexCount;
	from = (int *)calloc(graph->maxVertexCount, sizeof(int));
	cost = (int *)calloc(graph->maxVertexCount, sizeof(int));
	result = (int **)calloc(2, sizeof(int *));
	i = 0;
	while (i < 2)
		result[i++] = (int *)calloc(graph->maxVertexCount, sizeof(int)); //할당

	for (int i = 0; i < maxVertexCount; ++i)
	{
		if (i == startVertex)
			from[i] = 0;
		else
			from[i] = startVertex;
		cost[i] = adjEdges[startVertex][i];
	}
	getSpanningTree(maxVertexCount, adjEdges, \
					result, from, cost);
	return (result);
}