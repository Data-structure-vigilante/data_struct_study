#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	ArrayGraph* udGraph = createArrayGraph(5);
	ArrayGraph* dGraph = createArrayDirectedGraph(5);

	for(int i = 0; i < 5; ++i)
		addVertexAG(udGraph, i);
	addEdgewithWeightAG(udGraph, 0, 1, 4);
	addEdgewithWeightAG(udGraph, 1, 2, 1);
	addEdgewithWeightAG(udGraph, 2, 0, 3);
	addEdgewithWeightAG(udGraph, 2, 3, 10);
	displayArrayGraph(udGraph);
	printf(" 0 : %d 5 : %d \n",checkVertexValid(udGraph,0), checkVertexValid(udGraph, 5));
	//removeVertexAG(udGraph, 2);
	//removeEdgeAG(udGraph, 2, 3);
	//displayArrayGraph(udGraph);
	
	//deleteArrayGraph(udGraph);
	//udGraph = NULL;
	// // while(1)
	// // {
		
	// // }
	system("leaks -atExit -- ./a.out");
	return 0;
}