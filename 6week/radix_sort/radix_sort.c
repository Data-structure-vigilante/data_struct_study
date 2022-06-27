#include "radix_sort.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct DequeNodeType {
    char data;
    struct DequeNodeType *pRLink;
    struct DequeNodeType *pLLink;
} DequeNode;

typedef struct LinkedDequeType {
    int currentElementCount; // 현재 원소의 개수
    DequeNode *pFrontNode;   // Front 노드의 포인터
    DequeNode *pRearNode;    // Rear 노드의 포인터
} LinkedDeque;

int isLinkedDequeEmpty(LinkedDeque *pDeque)
{
    return pDeque->currentElementCount == 0;
}

int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
    if (!pDeque)
        return FALSE;

    DequeNode *node = (DequeNode *)calloc(1, sizeof(DequeNode));
    if (node == NULL)
        return FALSE;

    *node = element;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = node;
        pDeque->pRearNode = node;
        node->pLLink = NULL;
        node->pRLink = NULL;
    }
    else
    {
        pDeque->pRearNode->pRLink = node;
        node->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = node;
        pDeque->pRearNode->pRLink = NULL;
    }
    ++pDeque->currentElementCount;
    return TRUE;
}

DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
    if (pDeque == NULL || isLinkedDequeEmpty(pDeque))
        return (NULL);

    DequeNode *node = pDeque->pFrontNode;

    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    if (pDeque->pFrontNode != NULL)
        pDeque->pFrontNode->pLLink = NULL;
    --pDeque->currentElementCount;
    return node;
}

int	get_maximum_digits(int *temp_array, int size)
{
	int	max = -2147483648;
	int max_digits = 1;
	int	i = 0;

	while (i < size)
	{
		if (temp_array[i] > max)
			max = temp_array[i];
		i++;
	}
	i = 0;
	if (max < 10)
		return (1);
	while (max >= 10)
	{
		max_digits *= 10;
		max /= 10;
	}
	return (max_digits);
}

void	radix_sort(int *array_to_sort, int size)
{
	int			*temp_array;
	int			max_digits;
	int			i = 1;
	int			j = 0;
	int			k;
	LinkedDeque	*bucket_array;

	temp_array = (int *)calloc(size, sizeof(int));
	bucket_array = (LinkedDeque *)calloc(10, sizeof(LinkedDeque));
	memcpy(temp_array, array_to_sort, size * sizeof(int));
	max_digits = get_maximum_digits(temp_array, size);
	while (i <= max_digits)
	{
		j = 0;
		while (j < size)
		{
			DequeNode element;

			element.data = temp_array[j];

			element.pLLink = NULL;
			element.pRLink = NULL;
			insertRearLD(&bucket_array[(temp_array[j] / i) % 10], element);
			++j;
		}
		//버킷 순으로 템프에 옮기기
		j = 0;
		k = 0;
		DequeNode *temp_node;
		while (j < 10)
		{
			if (bucket_array[j].currentElementCount == 0)
			{
				++j;
				continue;
			}
			temp_node = deleteFrontLD(&bucket_array[j]);
			temp_array[k++] = temp_node->data;
			free(temp_node);
		}
		i *= 10;
	}
	printf("hi");
	// int	*temp_swap;
	i = 0;
	while (i < size)
	{
		array_to_sort[i] = temp_array[i];
		++i;
	}
	// temp_array = NULL;
}