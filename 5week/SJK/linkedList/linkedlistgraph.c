#include "linkedlistgraph.h"
#include "graphlinkedlist.h"

ListGraph *createListGraph(int maxVertexCount) {
    ListGraph *arrGraph;
    LinkedList *pAdjEdge;
    int *pVertex;
    int i;

    arrGraph = (ListGraph *)calloc(1, sizeof(ListGraph));
    pAdjEdge = (LinkedList *)calloc(maxVertexCount, sizeof(LinkedList));
    pVertex = (int *)calloc(maxVertexCount, sizeof(int));
    i = 0;
    arrGraph->maxVertexCount = maxVertexCount;
    arrGraph->currentVertexCount = 0;
    arrGraph->graphType = GRAPH_UNDIRECTED;
    arrGraph->pAdjEdge = pAdjEdge;
    arrGraph->pVertex = pVertex;
    return (arrGraph);
}

ListGraph *createListDirectedGraph(int maxVertexCount) {
    ListGraph *arrGraph;

    arrGraph = createListGraph(maxVertexCount);
    arrGraph->graphType = GRAPH_DIRECTED;
    return (arrGraph);
}

int isEmptyLG(ListGraph *pGraph) { return (pGraph->currentVertexCount == 0); }

int checkVertexValid(ListGraph *pGraph, int vertexID) {
    if (pGraph == NULL)
        return (FALSE);
    if (vertexID >= pGraph->maxVertexCount || vertexID < 0)
        return (FALSE);
    return (TRUE);
}

int isExistEdge(LinkedList *fromVertex, int toVertexId) {
    if (findLLElement(fromVertex, toVertexId) == -1)
        return FALSE;
    return TRUE;
}

int addVertexLG(ListGraph *pGraph, int vertexID) {
    if (checkVertexValid(pGraph, vertexID) == FALSE ||
        pGraph->pVertex[vertexID] == USED)
        return (FAIL);
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;

    return (SUCCESS);
}

int addEdgewithWeightLG(ListGraph *pGraph, int fromVertexID, int toVertexID,
                        int weight) {
    LinkedList *fromVertex;
    ListNode newEdge;

    if (weight < 1)
        return (FAIL);
    if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
        pGraph->pVertex[fromVertexID] == NOT_USED)
        return (FAIL);
    if (checkVertexValid(pGraph, toVertexID) == FALSE ||
        pGraph->pVertex[toVertexID] == NOT_USED)
        return (FAIL);

    fromVertex = &pGraph->pAdjEdge[fromVertexID];
    if (isExistEdge(fromVertex, toVertexID))
        return (FAIL);

    newEdge.data.vertexID = toVertexID;
    newEdge.data.weight = weight;
    newEdge.pLink = NULL;
    addLLElement(fromVertex, fromVertex->currentElementCount, newEdge);
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        newEdge.data.vertexID = fromVertexID;
        fromVertex = &pGraph->pAdjEdge[toVertexID];
        addLLElement(fromVertex, fromVertex->currentElementCount, newEdge);
    }
    return (SUCCESS);
}

int addEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID) {
    return (addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, 1));
}

int removeVertexLG(ListGraph *pGraph, int vertexID) {
    if (checkVertexValid(pGraph, vertexID) == FALSE ||
        pGraph->pVertex[vertexID] == NOT_USED)
        return (FAIL);
    // 1.모든 버택스 순회하며 해당 버택스 관련 엣지 찾아 지우기

    for (int i = 0; i < pGraph->maxVertexCount; ++i) {
        //존재하는 버택스 이면서 자기자신이 아닌 버택스들만 검사해야함
        if (pGraph->pVertex[i] == NOT_USED || i == vertexID)
            continue;
        removeEdgeLG(pGraph, i, vertexID);
    }
// 2.해당 버택스의 리스트 클리어하기
pGraph->pVertex[vertexID] = NOT_USED;
clearLinkedList(&pGraph->pAdjEdge[vertexID]);

pGraph->currentVertexCount--;
return (SUCCESS);
}

int removeEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID) {
    LinkedList *fromVertex;
    int targetPos;

    if (checkVertexValid(pGraph, fromVertexID) == FALSE ||
        checkVertexValid(pGraph, toVertexID) == FALSE)
        return FAIL;
    // 1. fromVertex에서 toVertex 엣지 찾아서 지워
    fromVertex = &pGraph->pAdjEdge[fromVertexID];
    targetPos = findLLElement(fromVertex, toVertexID);
    if (targetPos == -1)
        return FAIL;
    removeLLElement(fromVertex, targetPos);
    // 2. 언다이렉티드면 toVertex에서도 fromVertex 방향 엣지 찾아서 지워.
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        fromVertex = &pGraph->pAdjEdge[toVertexID];
        targetPos = findLLElement(fromVertex, fromVertexID);
        removeLLElement(fromVertex, targetPos);
    }
    return SUCCESS;
}

void deleteListGraph(ListGraph *pGraph) {
    int i;

    if (pGraph == NULL)
        return;
    i = 0;
    while (i < pGraph->maxVertexCount) {
        clearLinkedList(&pGraph->pAdjEdge[i]);
        ++i;
    }
    free(pGraph->pAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

void displayListGraph(ListGraph *pGraph) {
    int i;

    if (pGraph == NULL)
        return;

    i = 0;

    while (i < pGraph->maxVertexCount)
    {
        if(pGraph->pVertex[i] == USED)
        {
            printf("%d :", i);
            printLinkedList(&pGraph->pAdjEdge[i]);
        }
        i++;
    }
}