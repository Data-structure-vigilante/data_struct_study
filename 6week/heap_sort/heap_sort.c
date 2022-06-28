#include "heap_sort.h"

static void swap(int *array_to_sort, int child)
{
	int temp;


	temp = array_to_sort[child];
	array_to_sort[child] = array_to_sort[(child - 1) / 2];
	array_to_sort[(child - 1) / 2] = temp;
}
void heap_sort(int *array_to_sort, int size)
{
	int		child;
	int		parent;

	for (int i = 1; i < size; ++i)
	{
		child = i;
		while (array_to_sort[parent] < array_to_sort[child])
		{
			parent = (child - 1) / 2;
			if (child == 0)
				break;
			swap(array_to_sort ,child);
			child = parent;
		}
	}
}