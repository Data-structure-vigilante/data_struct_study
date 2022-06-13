#include "../linkedList/linkedlistgraph.h"
#include "../../../2week/KJ/LinkedStack/linkedstack.h"

int findPath(ListGraph *graph, int startVertexId, int goalVertexId)
{
	LinkedStack result; // 최단 경로들 담아 두기
	int currentVertexCount = graph->currentVertexCount;
	int visited[currentVertexCount]; //컴파일 안되면 동적할당

	dfs(graph, startVertexId, goalVertexId, visited) // 종료 시, result에 최단 경로 다 담겨있음.

	// if (result == empty)
	// 	print(경로 없음~);
	// 	return FAIL;
	// else
	//  	print(pop(result)); // 있으면 출력해~
	// 	return SUCCESS;
}

// 재귀 구현
int dfs(ListGraph *graph, int currentVertexId, int goalVertexId, int *visited)
{
	// 탈출 조건 : 벽에 막혔을 때, 도착했을 때 - 스택에 조건부 저장, 가능한 모든 지점에 방문했을 때,
	ListNode *candidate;

	visited[currentVertexId] = TRUE;
	candidate = getLLElement(&graph->pAdjEdge[currentVertexId], 0);
	while (candidate != NULL)
	{
		if (visited[candidate->data.vertexID] == FALSE)
			dfs(graph, candidate->data.vertexID, goalVertexId, visited);
		candidate = candidate->pLink;
	}
}