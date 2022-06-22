#include "./dijkstra.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	ArrayGraph* dGraph = createArrayDirectedGraph(6);
	int **result;
	int			idx_for_result;

	for(int i = 0; i < 6; ++i)
		addVertexAG(dGraph, i);
	addEdgewithWeightAG(dGraph, 0, 2, 7);
	addEdgewithWeightAG(dGraph, 0, 4, 14);
	addEdgewithWeightAG(dGraph, 2, 4, 5);
	addEdgewithWeightAG(dGraph, 0, 1, 8);
	addEdgewithWeightAG(dGraph, 0, 3, 20);
	addEdgewithWeightAG(dGraph, 3, 0, 12);
	addEdgewithWeightAG(dGraph, 4, 5, 4);
	addEdgewithWeightAG(dGraph, 4, 0, 11);
	addEdgewithWeightAG(dGraph, 5, 3, 10);
	addEdgewithWeightAG(dGraph, 1, 3, 13);

	displayArrayGraph(dGraph);

	// result = prim(udGraph, 4);
	// if (result == NULL)
	// 	return (0);
	idx_for_result = 0;
	result = dijkstra(dGraph,2);

	while (idx_for_result < dGraph->maxVertexCount - 1)
	{
		printf("( %d, %d )  ", result[0][idx_for_result], result[1][idx_for_result]);
		++idx_for_result;
	}

	//removeVertexAG(udGraph, 2);
	//removeEdgeAG(udGraph, 2, 3);
	//displayArrayGraph(udGraph);

	deleteArrayGraph(dGraph);
	dGraph = NULL;
	idx_for_result = 0;
	while(idx_for_result < 2)
	{
		free(result[idx_for_result]);
		++idx_for_result;
	}
	free(result);
	return 0;
}