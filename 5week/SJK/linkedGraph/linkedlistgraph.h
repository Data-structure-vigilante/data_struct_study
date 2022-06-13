#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include "graphlinkedlist.h"

typedef struct ListGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int graphType;
	LinkedList *pAdjEdge;
	int *pVertex;
} ListGraph;

ListGraph *createListGraph(int maxVertexCount);
ListGraph *createListDirectedGraph(int maxVertexCount);

void deleteListGraph(ListGraph *pGraph);
int isEmptyLG(ListGraph *pGraph);
int addVertexLG(ListGraph *pGraph, int vertexID);
int addEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(ListGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(ListGraph *pGraph, int vertexID);
int removeVertexLG(ListGraph *pGraph, int vertexID);

int removeEdgeLG(ListGraph *pGraph, int fromVertexID, int toVertexID);

void displayListGraph(ListGraph *pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2
#endif
