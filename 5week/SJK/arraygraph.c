#include "arraygraph.h"
#include <stdlib.h>

ArrayGraph*	createArrayGraph(int maxVertexCount)
{
	ArrayGraph	*arrGraph;
	int			**ppAdjedge;
	int			*pVertex;
	int			i;

	arrGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));
	ppAdjedge = (int **)calloc(maxVertexCount, sizeof(int *));
	pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	i = 0;
	while (i < maxVertexCount)
	{
		ppAdjedge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		i++;
	}
	arrGraph->maxVertexCount = maxVertexCount;
	arrGraph->currentVertexCount = 0;
	arrGraph->graphType = GRAPH_UNDIRECTED;
	arrGraph->ppAdjEdge = ppAdjedge;
	arrGraph->pVertex = pVertex;
	return (arrGraph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{

}