#include "./dfs.h"
#include <stdio.h>
#include <stdlib.h>

int findPath(ListGraph *graph, int startVertexId, int goalVertexId)
{
	ArrayStack *result;
	int currentVertexCount = graph->currentVertexCount;
	int *visited;
	int isFound;

	visited = (int *)calloc(currentVertexCount, sizeof(int));
	result = createArrayStack(currentVertexCount);
	isFound = NOT_FOUND;
	dfs(graph, startVertexId, goalVertexId, visited, result, &isFound); // 종료 시, result에 최단 경로 다 담겨있음.
	if (isArrayStackEmpty(result))
	{
		printf("Path is not found\n");
		free(visited);
		deleteArrayStack(result);
		return FAIL;
	}
	else
	{
		while (isArrayStackEmpty(result) == FALSE)
		{
			printf(" %d", popLS(result)->data);
			if (isArrayStackEmpty(result) == FALSE)
				printf(" <-");
		}
		printf("\n");
		free(visited);
		deleteArrayStack(result);
		return SUCCESS;
	}
}

void dfs(ListGraph *graph, int currentVertexId, int goalVertexId, int *visited, ArrayStack *result, int *isFound)
{
	ListNode *candidate;
	StackNode pathNode;

	visited[currentVertexId] = TRUE;
	pathNode.data = currentVertexId;
	pushLS(result, pathNode);
	if (currentVertexId == goalVertexId)
	{
		*isFound = FOUND;
		return;
	}
	candidate = getLLElement(&graph->pAdjEdge[currentVertexId], 0);
	while (candidate != NULL)
	{
		if (*isFound == FOUND)
			break;
		if (visited[candidate->data.vertexID] == FALSE)
			dfs(graph, candidate->data.vertexID, goalVertexId, visited, result, isFound);
		candidate = candidate->pLink;
	}
	if (*isFound == NOT_FOUND)
		popLS(result);
}