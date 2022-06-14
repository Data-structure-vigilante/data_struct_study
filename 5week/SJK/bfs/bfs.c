#include "./bfs.h"
#include <stdio.h>
#include <stdlib.h>

int findPath(ListGraph *graph, int startVertexId, int goalVertexId)
{
	int *allPaths;
	int i;

	i = goalVertexId;
	allPaths = getAllPaths(graph, startVertexId, goalVertexId);
	if (allPaths[i] == -1)
	{
		printf("No Path!+++++++++\n");
		return (0);
	}
	printf("Path : ");
	while (allPaths[i] != i)
	{
		printf(" %d", i);
		if (allPaths[i] == startVertexId)
			break ;
		else
			i = allPaths[i];
	}
	printf("\n");
}

int *getAllPaths(ListGraph *graph, int startVertexId, int goalVertexId)
{
	ArrayQueue		*queue;
	int				parentID;
	ListNode		*candidate;
	ArrayQueueNode	element;
	int				*parentArray;
	int				*visited;
	int				currentVertexCount = graph->currentVertexCount;
	//int				i = 0;

	queue = createArrayQueue(currentVertexCount);
	visited = (int *)calloc(currentVertexCount, sizeof(int));
	parentArray = (int *)calloc(currentVertexCount, sizeof(int));
	visited[startVertexId] = TRUE;
	element.data = startVertexId;
	parentArray[startVertexId] = startVertexId;
	enqueueAQ(queue, element);
	// while (i < currentVertexCount)
	// {
	// 	parentArray[i] = 
	// }
	while (!isArrayQueueEmpty(queue))
	{
		parentID = dequeueAQ(queue)->data;
		candidate = getLLElement(&graph->pAdjEdge[parentID], 0);
		while (candidate != NULL)
		{
			if (visited[candidate->data.vertexID] == FALSE)
			{
				visited[candidate->data.vertexID] = TRUE;
				parentArray[candidate->data.vertexID] = parentID;
				element.data = candidate->data.vertexID;
				enqueueAQ(queue, element);
			}
			candidate = candidate->pLink;
		}
	}
	deleteArrayQueue(queue);
	free(visited);
	return (parentArray);
}