#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

ArrayGraph *createArrayGraph(int maxVertexCount) {
    ArrayGraph *arrGraph;
    int **ppAdjedge;
    int *pVertex;
    int i;

    arrGraph = (ArrayGraph *)calloc(1, sizeof(ArrayGraph));
    ppAdjedge = (int **)calloc(maxVertexCount, sizeof(int *));
    pVertex = (int *)calloc(maxVertexCount, sizeof(int));
    i = 0;
    while (i < maxVertexCount) {
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

ArrayGraph *createArrayDirectedGraph(int maxVertexCount) {
    ArrayGraph *arrGraph;

    arrGraph = createArrayGraph(maxVertexCount);
    arrGraph->graphType = GRAPH_DIRECTED;
    return (arrGraph);
}

int isEmptyAG(ArrayGraph *pGraph) { return (pGraph->currentVertexCount == 0); }

int checkVertexValid(ArrayGraph *pGraph, int vertexID) {
    if (pGraph == NULL)
        return (FALSE);
    if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
        return (FALSE);
    return (TRUE);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID) {
    if (checkVertexValid(pGraph, vertexID) == FALSE ||
        pGraph->pVertex[vertexID] == USED)
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;

    return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID,
                        int weight) {
    if (weight < 1)
        return (FAIL);
    if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
        pGraph->pVertex[fromVertexID] == NOT_USED)
        return (FAIL);
    if (checkVertexValid(pGraph, toVertexID) == FALSE ||
        pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    return (SUCCESS);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID) {
    return (addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, 1));
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID) {
    if (checkVertexValid(pGraph, vertexID) == FALSE ||
        pGraph->pVertex[vertexID] == NOT_USED)
        return (FAIL);
    int i;

    pGraph->pVertex[vertexID] = NOT_USED;
    i = 0;
    while (i < pGraph->maxVertexCount) {
        pGraph->ppAdjEdge[i][vertexID] = 0;
        pGraph->ppAdjEdge[vertexID][i] = 0;
        i++;
    }
    pGraph->currentVertexCount--;
    return (SUCCESS);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID) {
    if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
        checkVertexValid(pGraph, toVertexID) == FALSE)
        return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
    if (pGraph->graphType == GRAPH_UNDIRECTED)
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
    return SUCCESS;
}

void deleteArrayGraph(ArrayGraph *pGraph) {
    int i;

    if (pGraph == NULL)
        return;
    i = 0;
    while (i < pGraph->maxVertexCount) {
        free(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

void displayArrayGraph(ArrayGraph *pGraph) {
    int i;
    int j;

    if (pGraph == NULL)
        return;

    i = 0;
    printf("    ");
    while (i < pGraph->maxVertexCount) {
        printf("  %03d ", i++);
    }
    printf(" \n");
    i = 0;
    while (i < pGraph->maxVertexCount) {
        j = 0;
        printf("%03d ", i);
        while (j < pGraph->maxVertexCount) {
            printf("| %03d ", pGraph->ppAdjEdge[i][j]);
            ++j;
        }
        printf("|\n");
        ++i;
    }
}