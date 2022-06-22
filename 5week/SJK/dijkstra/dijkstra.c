#include "dijkstra.h"
#include <stdlib.h>

int findMin(int *cost, int maxVertexCount)
{
	int		minIdx;
	int		minValue;
	int		idx1;

	minValue = INF;
	idx1 = 0;
	while(idx1 < maxVertexCount)
	{
		if (cost[idx1] != 0 && cost[idx1] < minValue)
		{
			minValue = cost[idx1];
			minIdx = idx1;
		}
		++idx1;
	}
	return (minIdx);
}

void fillResult(int **result, int *from, int minIdx, int i)
{
	result[0][i] = from[minIdx];
	result[1][i] = minIdx;
}

int *createFromArray(int maxVertexCount, int startVertex)
{
	int *from;

	from = (int *)calloc(maxVertexCount, sizeof(int));
	for (int i = 0; i < maxVertexCount; ++i)
		from[i] = startVertex;
	return (from);
}

int *createCostArray(int maxVertexCount, int startVertex, int **adjEdges)
{
	int *cost;

	cost = (int *)calloc(maxVertexCount, sizeof(int));
	for (int i = 0; i < maxVertexCount; ++i)
		cost[i] = adjEdges[startVertex][i];
	return (cost);
}

int **createResultArray(int maxVertexCount)
{
	int i;
	int **result;

	result = (int **)calloc(2, sizeof(int *));
	i = 0;
	while (i < 2)
		result[i++] = (int *)calloc(maxVertexCount, sizeof(int));
	return (result);
}

int	**getShortestPath(int maxVertexCount, int *from, int *cost, int **adjEdges)
{
	int i;
	int j;
	int **result;
	int minIdx;
	int aroundPath;

	result = createResultArray(maxVertexCount);
	i = 0;
	while (i < maxVertexCount - 1)
	{
		minIdx = findMin(cost, maxVertexCount);
		fillResult(result, from, minIdx, i);
		j = 0;
		while (j < maxVertexCount)
		{
			aroundPath = cost[minIdx] + adjEdges[minIdx][j];
			if (aroundPath < cost[j])
			{
				from[j] = minIdx;
				cost[j] = aroundPath;
			}
			++j;
		}
		cost[minIdx] = 0;
		++i;
	}
	return (result);
}

int	**getSpanningTree(int startVertex, int maxVertexCount, int **adjEdges)
{

	int *from;
	int *cost;
	int **result;

	from = createFromArray(maxVertexCount, startVertex);
	cost = createCostArray(maxVertexCount, startVertex, adjEdges);
	result = getShortestPath(maxVertexCount, from, cost, adjEdges);
	free(from);
	free(cost);
	return (result);
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

int **dijkstra(ArrayGraph *graph, int startVertex)
{
	int		**result;

	switchZeroToInf(graph);
	result = getSpanningTree(startVertex, graph->maxVertexCount, graph->ppAdjEdge);
	return (result);
}