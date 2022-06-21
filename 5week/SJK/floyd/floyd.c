#include "floyd.h"
#include <stdlib.h>

int	**getShortestPath(ArrayGraph *graph)
{
	int		start;
	int		end;
	int		stopover;
	int		maxVertexCount;
	int		**result;

	maxVertexCount = graph->maxVertexCount;
	result = graph->ppAdjEdge;

	stopover = 0;
	while (stopover < maxVertexCount)
	{
		start = 0;
		while (start < maxVertexCount)
		{
			end = 0;
			while (end < maxVertexCount)
			{
				if (result[start][stopover] + result[stopover][end] < result[start][end])
					result[start][end] = result[start][stopover] + result[stopover][end];
				++end;
			}
			++start;
		}
		++stopover;
	}
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

int **floyd(ArrayGraph graph)
{
	int **shortestCost;

	switchZeroToInf(&graph);
	shortestCost = getShortestPath(&graph);
	return (shortestCost);
}