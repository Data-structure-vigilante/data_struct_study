#include "graphlinkedlist.h"


static int isValidArg(LinkedList *pList, int position) {
    if (!pList || position < 0 || pList->currentElementCount < position)
        return FALSE;
    return TRUE;
}

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

int findLLElement(LinkedList *pList, int vertexId) {
	int i;
	ListNode *currentNode;

	if (pList == NULL)
		return -1;

	i = 0;
	currentNode = pList->headerNode.pLink;
	while (i < pList->currentElementCount) {
		if (currentNode->data.vertexID == vertexId)
			break;
		currentNode = currentNode->pLink;
		++i;
	}
	if (currentNode == NULL)
		return -1;
	return i;
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

void printLinkedList(LinkedList *pList)
{
	ListNode *currentNode;
	int	i;

	i = 0;
	currentNode = pList->headerNode.pLink;
	while (i < pList->currentElementCount) {
		printf(" --> %d(%d)", currentNode->data.vertexID, currentNode->data.weight);
		currentNode = currentNode->pLink;
		++i;
	}
	printf("\n");
}