#ifndef BFS_H
#define BFS_H

#include "../linkedGraph/linkedlistgraph.h"
#include "../../../3week/HJ/Queue/arrayqueue.h"

int findPath(ListGraph *graph, int startVertexId, int goalVertexId);
void bfs(ListGraph *graph, int currentVertexId, int goalVertexId, int *visited);

#define FOUND 1
#define NOT_FOUND 0

#endif