#include "./floyd.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	ArrayGraph* dGraph = createArrayDirectedGraph(4);
	int **result;
	int			idx_for_result;

	for(int i = 0; i < 4; ++i)
		addVertexAG(dGraph, i);
	addEdgewithWeightAG(dGraph, 0, 1, 5);
	addEdgewithWeightAG(dGraph, 0, 3, 8);
	addEdgewithWeightAG(dGraph, 1, 0, 7);
	addEdgewithWeightAG(dGraph, 1, 2, 9);
	addEdgewithWeightAG(dGraph, 2, 0, 2);
	addEdgewithWeightAG(dGraph, 2, 3, 4);
	addEdgewithWeightAG(dGraph, 3, 2, 3);

	result = floyd(*dGraph);

	int i;
    int j;

    i = 0;
    printf("    ");
    while (i < dGraph->maxVertexCount) {
        printf("  %3d ", i++);
    }
    printf(" \n");
    i = 0;
    while (i < dGraph->maxVertexCount) {
        j = 0;
        printf("%3d ", i);
        while (j < dGraph->maxVertexCount) {
            printf("| %3d ", result[i][j]);
            ++j;
        }
        printf("|\n");
        ++i;
    }
	deleteArrayGraph(dGraph);
	dGraph = NULL;
	return 0;
}