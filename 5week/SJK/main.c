#include "arraygraph.h"

int main() {
	ArrayGraph* udGraph = createArrayGraph(5);
	ArrayGraph* dGraph = createArrayDirectedGraph(5);

	for(int i = 0; i < 5; ++i)
		addVertexAG(udGraph, i);
	addEdgeAG(udGraph, 0, 1);
	addEdgeAG(udGraph, 1, 2);
	addEdgeAG(udGraph, 2, 0);
	addEdgeAG(udGraph, 2, 3);
	displayArrayGraph(udGraph);
	return 0;
}