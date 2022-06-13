#include "dfs.h"
#include "../linkedGraph/linkedlistgraph.h"

int main() {
	ListGraph* dGraph = createListDirectedGraph(6);

	for(int i = 0; i < 7; ++i)
		addVertexLG(dGraph, i);
	addEdgeLG(dGraph, 0, 1);
	addEdgeLG(dGraph, 0, 3);
	addEdgeLG(dGraph, 1, 2);
	addEdgeLG(dGraph, 1, 4);
	addEdgeLG(dGraph, 2, 3);
	addEdgeLG(dGraph, 4, 5);
	addEdgeLG(dGraph, 5, 3);

	// removeVertexAG(dGraph, 2);
	// removeEdgeAG(dGraph, 2, 3);
	displayListGraph(dGraph);
	findPath(dGraph, 0, 1);
	deleteListGraph(dGraph);
	dGraph = NULL;
}