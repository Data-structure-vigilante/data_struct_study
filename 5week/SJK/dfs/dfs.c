#include "../linkedList/linkedlistgraph.h"
#include "../../../2week/SH/linkedStack/linkedstack.h"
#include "./dfs.h"
#include <stdio.h>

int findPath(ListGraph *graph, int startVertexId, int goalVertexId)
{
	LinkedStack *result; // 최단 경로들 담아 두기
	int currentVertexCount = graph->currentVertexCount;
	int visited[currentVertexCount]; //컴파일 안되면 동적할당
	int isFound;

	result = createLinkedStack();
	isFound = NOT_FOUND;
	dfs(graph, startVertexId, goalVertexId, visited, result, &isFound); // 종료 시, result에 최단 경로 다 담겨있음.
	if (isLinkedStackEmpty(result))
	{
		printf("Path is not found\n");
		return FAIL;
	}
	else
	{
		while(isLinkedStackEmpty(result) == FALSE)
		{
			printf(" %d", popLS(result)->data);
			if (isLinkedStackEmpty == FALSE)
				printf(" <-");
		}
		printf("\n");
		return SUCCESS;
	}
}

// 재귀 구현
void dfs(ListGraph *graph, int currentVertexId, int goalVertexId, int *visited, LinkedStack *result, int *isFound)
{
	// 탈출 조건 : 벽에 막혔을 때, 도착했을 때 - 스택에 조건부 저장, 가능한 모든 지점에 방문했을 때,
	//result 스택에 경로를 담아두기
	ListNode *candidate;
	StackNode pathNode;

	visited[currentVertexId] = TRUE;
	pathNode.data = currentVertexId;
	pathNode.pLink = NULL;
	pushLS(result, pathNode);
	candidate = getLLElement(&graph->pAdjEdge[currentVertexId], 0);
	while (candidate != NULL)
	{
		if (visited[candidate->data.vertexID] == FALSE)
			dfs(graph, candidate->data.vertexID, goalVertexId, visited, isFound);
		candidate = candidate->pLink;
	}
	if (*isFound == NOT_FOUND)
		popLS(result);
}