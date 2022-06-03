#include "graphlinkedlist.h"
#include "linkedlistgraph.h"

ListGraph *createArrayGraph(int maxVertexCount)
{
	ListGraph *arrGraph;
	int **pAdjedge;
	int *pVertex;
	int i;

	arrGraph = (ListGraph *)calloc(1, sizeof(ListGraph));
	pAdjedge = (int **)calloc(maxVertexCount, sizeof(int *));
	pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	i = 0;
	while (i < maxVertexCount)
	{
		pAdjedge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		i++;
	}
	arrGraph->maxVertexCount = maxVertexCount;
	arrGraph->currentVertexCount = 0;
	arrGraph->graphType = GRAPH_UNDIRECTED;
	arrGraph->pAdjEdge = pAdjedge;
	arrGraph->pVertex = pVertex;
	return (arrGraph);
}

ListGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ListGraph *arrGraph;

	arrGraph = createArrayGraph(maxVertexCount);
	arrGraph->graphType = GRAPH_DIRECTED;
	return (arrGraph);
}

int isEmptyLG(ListGraph *pGraph) { return (pGraph->currentVertexCount == 0); }

int checkVertexValid(ListGraph *pGraph, int vertexID)
{
	if (pGraph == NULL)
		return (FALSE);
	if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
		return (FALSE);
	return (TRUE);
}

int addVertexLG(ListGraph *pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE ||
		pGraph->pVertex[vertexID] == USED)
		return (FAIL);
	pGraph->pVertex[vertexID] = USED;
	pGraph->currentVertexCount++;

	return (SUCCESS);
}

int addEdgewithWeightLG(ListGraph *pGraph, int fromVertexID, int toVertexID,
						int weight)
{
	if (weight < 1)
		return (FAIL);
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
		pGraph->pVertex[fromVertexID] == NOT_USED)
		return (FAIL);
	if (checkVertexValid(pGraph, toVertexID) == FALSE ||
		pGraph->pVertex[toVertexID] == NOT_USED)
		return (FAIL);
	pGraph->pAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->pAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

int addEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID)
{
	return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1));
}

int removeVertexLG(ListGraph *pGraph, int vertexID)
{
	if (checkVertexValid(pGraph, vertexID) == FALSE ||
		pGraph->pVertex[vertexID] == NOT_USED)
		return (FAIL);
	int i;

	pGraph->pVertex[vertexID] = NOT_USED;
	i = 0;
	while (i < pGraph->maxVertexCount)
	{
		pGraph->pAdjEdge[i][vertexID] = 0;
		pGraph->pAdjEdge[vertexID][i] = 0;
		i++;
	}
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

int removeEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
		checkVertexValid(pGraph, toVertexID) == FALSE)
		return FAIL;
	pGraph->pAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->pAdjEdge[toVertexID][fromVertexID] = 0;
	return SUCCESS;
}

void deleteArrayGraph(ListGraph *pGraph)
{
	int i;

	if (pGraph == NULL)
		return;
	i = 0;
	while (i < pGraph->maxVertexCount)
	{
		free(pGraph->pAdjEdge[i]);
		++i;
	}
	free(pGraph->pAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

void displayArrayGraph(ListGraph *pGraph)
{
	int i;
	int j;

	if (pGraph == NULL)
		return;

	i = 0;
	printf("    ");
	while (i < pGraph->maxVertexCount)
	{
		printf("  %3d ", i++);
	}
	printf(" \n");
	i = 0;
	while (i < pGraph->maxVertexCount)
	{
		j = 0;
		printf("%3d ", i);
		while (j < pGraph->maxVertexCount)
		{
			printf("| %3d ", pGraph->pAdjEdge[i][j]);
			++j;
		}
		printf("|\n");
		++i;
	}
}