#include "../arrayGraph/arraygraph.h"

typedef struct edge_weight_type
{
	int		start;
	int		end;
	int		weight;
}				edge_weight;

void init_parents(int *parent, int vertexCount);

void update_parents(edge_weight *infos, int *parents, int vertex_count);

edge_weight *get_infos(ArrayGraph *graph, int edge_count);

edge_weight *kruskal(ArrayGraph *graph);

