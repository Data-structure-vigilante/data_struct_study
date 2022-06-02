#include "arraygraph.h"
#include <stdlib.h>

ArrayGraph *createArrayGraph(int maxVertexCount)
{
	ArrayGraph *arrGraph;
	int **ppAdjedge;
	int *pVertex;
	int i;

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

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *arrGraph;

	arrGraph = createArrayGraph(maxVertexCount);
	arrGraph->graphType = GRAPH_DIRECTED;
	return (arrGraph);
}

void deleteArrayGraph(ArrayGraph *pGraph);

int isEmptyAG(ArrayGraph *pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FALSE);
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FALSE);
	return (TRUE);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FAIL);
	if (checkVertexValid(pGraph, vertexID) == FALSE || pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;

	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (pGraph == NULL)
		return (FAIL);
	if (checkVertexValid(pGraph, fromVertexID) == FALSE || pGraph->pVertex[fromVertexID] == NOT_USED)
		return (FAIL);
	if (checkVertexValid(pGraph, toVertexID) == FALSE || pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, 1));
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (pGraph == NULL || checkVertexValid(pGraph, vertexID) == FALSE || pGraph->pVertex[vertexID] == NOT_USED)
		return (FAIL);
	int i;

	pGraph->pVertex[vertexID] == NOT_USED;
	i = 0;
	while (i < pGraph->maxVertexCount)
	{
		pGraph->ppAdjEdge[i][vertexID] = 0;
		pGraph->ppAdjEdge[vertexID][i] = 0;
		i++;
	}
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph *pGraph);