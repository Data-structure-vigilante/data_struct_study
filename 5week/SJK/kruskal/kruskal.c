#include "kruskal.h"
#include <stdio.h>
#include <stdlib.h>

void init_infos(edge_weight *infos)
{
	int	i;

	i = 0;
	while(i < 1000)
	{
		infos[i].start = -1;
		infos[i].end = -1;
		infos[i].weight = 0;
		++i;
	}
}

void init_parents(int *parents, int vertexCount)
{
	int	i;

	i = 0;
	while (i < vertexCount)
	{
		parents[i] = i;
		++i;
	}
}

void get_infos(edge_weight *infos, ArrayGraph *graph)
{
	int		a;
	int		b;
	int		count;

	a = 0;
	count = 0;
	while (a < graph->maxVertexCount)
	{
		b = a + 1;
		while (b < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[a][b] != 0)
			{
				infos->start = a;
				infos->end = b;
				infos->weight = graph->ppAdjEdge[a][b];
				++count;
			}
			++b;
		}
		++a;
	}
	infos->edge_count = count;
}

void sort_infos(edge_weight *infos)
{
	int	temp;

	for (int i = 0; i < infos->edge_count - 1; i++)
    {
        for (int j = 0; j < infos->edge_count - 1 - i; j++)
        {
            if (infos[j].weight > infos[j + 1].weight)
            {
                temp        = infos[j].weight;
                infos[j].weight     = infos[j + 1].weight;
                infos[j + 1].weight = temp;
            }
        }
    }
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

void update_parents(edge_weight *infos, int *parents, int vertex_count)
{
	int big_parent;
	int small_parent;
	int	i;

	small_parent = min(parents[infos->start], parents[infos->end]);
	big_parent = max(parents[infos->start], parents[infos->end]);
	i = 0;
	while (i < vertex_count)
	{
		if (parents[i] == big_parent)
			parents[i] = small_parent;
		++i;
	}
}

int is_cycle(edge_weight infos, int *parents)
{
	if (parents[infos.start] == parents[infos.end])
		return (TRUE);
	else
		return (FALSE);

}

edge_weight *kruskal(ArrayGraph *graph)
{
	int		*parents;
	edge_weight	*result;
	edge_weight *infos;
	int		a;
	int		b;

	parents = (int *)calloc(graph->maxVertexCount, sizeof(int));
	infos = (edge_weight *)calloc(1000, sizeof(edge_weight));
	result = (edge_weight *)calloc(graph->currentVertexCount - 1, sizeof(edge_weight));
	init_infos(infos);
	init_parents(parents, graph->currentVertexCount);
	get_infos(infos, graph); //간선과 가중치 정보 배열
	sort_infos(infos); //간선 오름차순(가중치)정렬

	a = 0;
	b = 0;
	while (b < graph->currentVertexCount - 1 && a < infos->edge_count)
	{
		if (!is_cycle(infos[a], parents)) //->start end 부모(루트)가 같은지 확인
		{
			update_parents(&infos[a], parents, graph->currentVertexCount);
			result[b] = infos[a];
			++b;
		}
		a++;
	}
	if (b != graph->currentVertexCount - 1)
	{
		printf("No PATH!!!!!!!\n");
		return (result);
	}
	printf("SUCCESS!!!\n");
	return (result);
}
