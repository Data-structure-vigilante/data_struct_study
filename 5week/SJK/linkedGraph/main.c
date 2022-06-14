#include "linkedlistgraph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	ListGraph* udGraph = createListGraph(5);
	ListGraph* dGraph = createListDirectedGraph(5);

	for(int i = 0; i < 5; ++i)
		addVertexLG(udGraph, i);
	addEdgewithWeightLG(udGraph, 0, 1, 4);
	addEdgewithWeightLG(udGraph, 1, 2, 1);
	addEdgewithWeightLG(udGraph, 2, 0, 3);
	addEdgewithWeightLG(udGraph, 2, 3, 10);
	displayListGraph(udGraph);
	printf(" 0 : %d 5 : %d \n",checkVertexValid(udGraph,0), checkVertexValid(udGraph, 5));
	//removeVertexAG(udGraph, 2);
	//removeEdgeAG(udGraph, 2, 3);
	//displayListGraph(udGraph);
	
	deleteListGraph(udGraph);
	deleteListGraph(dGraph);
	udGraph = NULL;

	return 0;
}