#include "kruskal.h"
#include <stdio.h>
#include <stdlib.h>

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

edge_weight *get_infos(ArrayGraph *graph, int edge_count)
{
	int		a;
	int		b;
	int		c;
	int		count;
	edge_weight *infos;

	infos = (edge_weight *)calloc(edge_count, sizeof(edge_weight));
	a = 0;
	c = 0;
	while (a < graph->maxVertexCount)
	{
		b = a + 1;
		while (b < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[a][b] != 0)
			{
				infos[c].start = a;
				infos[c].end = b;
				infos[c].weight = graph->ppAdjEdge[a][b];
				++c;
			}
			++b;
		}
		++a;
	}
	return (infos);
}

void sort_infos(edge_weight *infos, int edge_count)
{
	edge_weight temp;

    for (int i = 0; i < edge_count; i++)    // 요소의 개수만큼 반복
    {
        for (int j = 0; j < edge_count - 1; j++)   // 요소의 개수 - 1만큼 반복
        {
            if (infos[j].weight > infos[j + 1].weight)          // 현재 요소의 값과 다음 요소의 값을 비교하여
            {                                 // 큰 값을
                temp = infos[j];
                infos[j] = infos[j + 1];
                infos[j + 1] = temp;            // 다음 요소로 보냄
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

int	get_edge_count(ArrayGraph *graph)
{
	int a;
	int b;
	int count;

	a = 0;
	count = 0;
	while (a < graph->maxVertexCount)
	{
		b = a + 1;
		while (b < graph->maxVertexCount)
		{
			if (graph->ppAdjEdge[a][b] != 0)
				++count;
			++b;
		}
		++a;
	}
	return (count);
}

edge_weight *kruskal(ArrayGraph *graph)
{
	int		*parents;
	edge_weight	*result;
	edge_weight *infos;
	int		a;
	int		b;
	int		edge_count;

	edge_count = get_edge_count(graph);
	parents = (int *)calloc(graph->maxVertexCount, sizeof(int));
	infos = get_infos(graph, edge_count);
	result = (edge_weight *)calloc(graph->currentVertexCount - 1, sizeof(edge_weight));
	init_parents(parents, graph->currentVertexCount);
	sort_infos(infos, edge_count); //간선 오름차순(가중치)정렬

	a = 0;
	b = 0;
	while (b < graph->currentVertexCount - 1 && a < edge_count)
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
