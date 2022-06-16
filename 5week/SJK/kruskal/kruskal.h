#include "../arrayGraph/arraygraph.h"

typedef struct edge_weight_type
{
	int		start;
	int		end;
	int		weight;
	int		edge_count;
}				edge_weight;

void init_infos(edge_weight *info);

void init_parents(int *parent, int vertexCount);

void update_parents(edge_weight *infos, int *parents, int vertex_count);

void get_infos(edge_weight *infos, ArrayGraph *graph);

edge_weight *kruskal(ArrayGraph *graph);

