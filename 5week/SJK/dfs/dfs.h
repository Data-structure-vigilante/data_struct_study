
#include "../../../2week/KJ/LinkedStack/linkedstack.h"
#include "../linkedList/linkedlistgraph.h"

// Path 찾기 start vertex, goal vertex, 마지막에 출력.
// return : 성공 여부

int findShortestPath(ListGraph *graph, int startVertexId, int goalVertexId) {
	LinkedStack result; // 최단 경로들 담아 두기
	dfs(graph, startVertexId, goalVertexId, &result) // 종료 시, result에 최단 경로 다 담겨있음.
	if (result == empty)
		print(경로 없음~);
		return FAIL;
	else
	 	print(pop(result)); // 있으면 출력해~
		return SUCCESS;

}


// 재귀 구현
int dfs(ListGraph *graph, int currentVertexId, int goalVertexId, LinkedStack *shortestPaths) {
	// 탈출 조건 : 벽에 막혔을 때, 도착했을 때 - 스택에 조건부 저장, 가능한 모든 지점에 방문했을 때,

}