#include "../arrayGraph/arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct edge_weight_type
{
	int		start;
	int		end;
	int		weight;
	int		edge_count;
}				edge_weight;

int set_find(int vertex, int *parent); // 부모찾기

int	update_parent(edge_weight *info, int *parent, int vertex_id);



edge_weight *kruskal(ArrayGraph *graph);

void set_init(int *parent, int *num, int n, edge_weight *info);