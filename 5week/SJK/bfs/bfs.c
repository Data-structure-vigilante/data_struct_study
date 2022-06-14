#include "./bfs.h"
#include <stdio.h>
#include <stdlib.h>

int findPath(ListGraph *graph, int startVertexId, int goalVertexId)
{
	ArrayQueue *result;
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
void bfs(ListGraph *graph, int startVertexId, int goalVertexId)
{
	ArrayQueue *queue;
	ArrayQueueNode *node;
	ListNode *candidate;
	ArrayQueueNode element;

	int *visited;
	int currentVertexCount = graph->currentVertexCount;

	queue = createArrayQueue(currentVertexCount);
	visited = (int *)calloc(currentVertexCount, sizeof(int));
	visited[startVertexId] = TRUE;
	element.data = startVertexId;
	enqueueAQ(queue, element);
	candidate = getLLElement(&graph->pAdjEdge[startVertexId], 0);
	while (!isArrayQueueEmpty(queue))
	{
		// while candidate의 인접 노드들
		if (candidate != FALSE)
		{
			visited[candidate->data.vertexID] = TRUE;
			enqueueAQ(queue, candidate);
		}
		candidate = candidate->pLink;
	}
}