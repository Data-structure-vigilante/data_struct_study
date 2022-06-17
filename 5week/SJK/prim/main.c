#include "./prim.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	ArrayGraph* udGraph = createArrayGraph(6);
	int **result;
	int			idx_for_result;

	for(int i = 0; i < 6; ++i)
		addVertexAG(udGraph, i);`
	addEdgewithWeightAG(udGraph, 0, 1, 6);
	addEdgewithWeightAG(udGraph, 0, 2, 7);
	addEdgewithWeightAG(udGraph, 0, 4, 10);
	addEdgewithWeightAG(udGraph, 0, 5, 9);
	addEdgewithWeightAG(udGraph, 1, 2, 8);
	addEdgewithWeightAG(udGraph, 2, 4, 5);
	addEdgewithWeightAG(udGraph, 2, 3, 4);
	addEdgewithWeightAG(udGraph, 3, 4, 3);
	addEdgewithWeightAG(udGraph, 4, 5, 11);

	displayArrayGraph(udGraph);
	
	result = prim(udGraph, 0);
	// if (result == NULL)
	// 	return (0);
	idx_for_result = 0;
	while (idx_for_result < udGraph->maxVertexCount - 1)
	{
		printf("( %d, %d )  ", result[0][idx_for_result], result[1][idx_for_result]);
		++idx_for_result;
	}
	//removeVertexAG(udGraph, 2);
	//removeEdgeAG(udGraph, 2, 3);
	//displayArrayGraph(udGraph);
	
	deleteArrayGraph(udGraph);
	udGraph = NULL;

	return 0;
}