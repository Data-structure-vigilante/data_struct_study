#include "graphlinkedlist.h"
typedef struct GraphVertexType
{
	int vertexID;
	int weight;
} GraphVertex;

typedef struct ListNodeType
{
	GraphVertex data;
	struct ListNodeType *pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;
	ListNode headerNode;
} LinkedList;

typedef struct ArrayGraphType
{
	int maxVertexCount;
	int currentVertexCount;
	int graphType;
	int **ppAdjEdge;
	int *pVertex;
} ArrayGraph;

LinkedList *createLinkedList()
{
}

int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);

void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);

LinkedList *createLinkedList()
{
	LinkedList *list;

	list = (LinkedList *)calloc(1, sizeof(LinkedList));
	list->headerNode.pLink = NULL;
	return list;
};

// Return : 실패 시 -1, 성공 시 인덱스 값.
int addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode *new_node;
	ListNode *current;

	if (!isValidArg(pList, position))
	{
		return -1;
	}

	new_node = (ListNode *)calloc(1, sizeof(ListNode));
	*new_node = element;
	current = &pList->headerNode;
	for (int count = 0; count < position; ++count)
	{
		current = current->pLink;
	}
	new_node->pLink = current->pLink;
	current->pLink = new_node;
	++pList->currentElementCount;
	return position;
};

int removeLLElement(LinkedList *pList, int position)
{
	if (!pList || position < 0 || pList->currentElementCount < position + 1)
		return -1;

	ListNode *prev_node = getLLElement(pList, position - 1);
	ListNode *target_node;

	if (!prev_node)
	{
		prev_node = &pList->headerNode;
	}
	target_node = prev_node->pLink;
	prev_node->pLink = prev_node->pLink->pLink;
	free(target_node);
	--pList->currentElementCount;
	return position;
}

ListNode *getLLElement(LinkedList *pList, int position)
{
	ListNode *current;

	if (!isValidArg(pList, position))
		return NULL;
	current = &pList->headerNode;
	for (int count = 0; count < position + 1; ++count)
	{
		current = current->pLink;
	}
	return current;
}

void clearLinkedList(LinkedList *pList)
{
	ListNode *temp_element;
	if (!pList)
		return;
	for (int count = 0; count < pList->currentElementCount; ++count)
	{
		temp_element = pList->headerNode.pLink;
		pList->headerNode.pLink = temp_element->pLink;
		free(temp_element);
	}
	pList->headerNode.pLink = NULL;
	pList->currentElementCount = 0;
}

int getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		return 0;
	return pList->currentElementCount;
}

void deleteLinkedList(LinkedList *pList)
{
	if (!pList)
		return;
	clearLinkedList(pList);
	free(pList);
}