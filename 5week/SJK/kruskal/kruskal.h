#include "../arrayGraph/arraygraph.h"

typedef struct edge_weight_type
{
	int		start;
	int		end;
	int		weight;
	int		edge_count;
}				edge_weight;

int set_find(int vertex); // 부모찾기

void set_union(edge_weight info); //집합 합치기

void kruskal(ArrayGraph *graph);

void set_init(int *parent, int *num, int n, edge_weight *info);