#ifndef DFS_H
# define DFS_H

#include "../linkedGraph/linkedlistgraph.h"
#include "../../../2week/SH/arrayStack/arraystack.h"

int findPath(ListGraph *graph, int startVertexId, int goalVertexId);
void dfs(ListGraph *graph, int currentVertexId, int goalVertexId, int *visited, ArrayStack *result, int *isFound);

# define FOUND 1
# define NOT_FOUND 0

#endif