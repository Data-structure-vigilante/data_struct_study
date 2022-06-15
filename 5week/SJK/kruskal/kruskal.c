#include "kruskal.h"

void set_init(int *parent, int *num, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		parent[i] = -1;
		num[i] = 1;
		++i;
	}
}

void kruskal(ArrayGraph *graph)
{
	int		*parent;
	int 	*num;
	int		a;
	int		b;
	edge_weight *info;

	a = 0;
	parent = (int *)calloc(graph->maxVertexCount, sizeof(int));
	num = (int *)calloc(graph->maxVertexCount, sizeof(int));
	set_init(parent, num, graph->maxVertexCount);


	while (a < graph->maxVertexCount)
	{
		b = a + 1;
		while (b < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[a][b] != 0)
			{
				info->start = a;
				info->end = b;
				info->weight = graph->ppAdjEdge[a][b];
			}
			++b;
		}
		++a;
	}

}

int main()
{
	ArrayGraph *graph;

	graph = createListGraph(10);

}