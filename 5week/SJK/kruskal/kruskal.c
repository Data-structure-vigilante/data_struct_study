#include "kruskal.h"

void set_init(int *parent, int *num, int n, edge_weight *info)
{
	int		i;

	i = 0;
	while (i < n)
	{
		parent[i] = -1;
		num[i] = 1;
		++i;
	}
	i = 0;
	while(i <= 1000)
	{
		info->start = -1;
		info->end = -1;
		info->weight = 0;
	}
	i = 0;
	while(i < n - 1)
	{

	}
}

void get_info(edge_weight *info, ArrayGraph *graph)
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
				info->start = a;
				info->end = b;
				info->weight = graph->ppAdjEdge[a][b];
				++count;
			}
			++b;
		}
		++a;
	}
}

void sort_info(edge_weight *info)
{
	int	temp;

	for (int i = 0; i < info->edge_count - 1; i++)
    {
        for (int j = 0; j < info->edge_count - 1 - i; j++)
        {
            if (info[j].weight > info[j + 1].weight)
            {
                temp        = info[j].weight;
                info[j].weight     = info[j + 1].weight;
                info[j + 1].weight = temp;
            }
        }
    }
}

void kruskal(ArrayGraph *graph)
{
	int		*parent;
	int 	*num; //++++++++
	int		*spanning_edge;
	edge_weight *info;
	int		a;
	int		b;

	parent = (int *)calloc(graph->maxVertexCount, sizeof(int));
	num = (int *)calloc(graph->maxVertexCount, sizeof(int));
	info = (edge_weight *)calloc(1000, sizeof(edge_weight));
	spanning_edge = (int *)calloc(graph->maxVertexCount - 1, sizeof(int));
	set_init(parent, num, graph->maxVertexCount, info, spanning_edge);
	get_info(info, graph); //간선과 가중치 정보 배열
	sort_info(info); //간선 오름차순(가중치)정렬
	
	while(b < n - 1 && a < info->edge_count)
	{
		if ( ! (is_cycle(info[a]))) //->start end 부모(루트)가 같은지 확인
		{
			set_union(info[a]);
			spanning_edge[b] = info[a];
		}
		a++;
	}
	if (b != n - 1)
	{
		printf("실패!");
		return;
	}
	~~~성공시 반환
}

int main()
{
	ArrayGraph *graph;

	graph = createListGraph(10);

}