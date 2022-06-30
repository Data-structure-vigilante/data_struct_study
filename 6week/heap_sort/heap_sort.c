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
		parent = (child - 1) / 2;
		while (array_to_sort[parent] < array_to_sort[child])
		{
			if (child == 0)
				break;
			swap(array_to_sort, child);
			child = parent;
			parent = (child - 1) / 2;
		}
	}
	for (int i = size - 1; i >= 0; --i)
	{
		int tmp;

		tmp = array_to_sort[0];
		array_to_sort[0] = array_to_sort[i];
		array_to_sort[i] = tmp;
		parent = 0;
		child = 1;
		while (child < i)
		{
			if (array_to_sort[child] < array_to_sort[child + 1] && child < i - 1)
				++child;
			if (array_to_sort[parent] < array_to_sort[child] && child < i)
				swap(array_to_sort, child);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}