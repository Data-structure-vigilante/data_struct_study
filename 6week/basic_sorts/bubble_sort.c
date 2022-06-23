#include "basic_sort.h"


void	bubble_sort(int *array_to_sort, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array_to_sort[j] > array_to_sort[j + 1])
				swap(array_to_sort, j, j + 1);
			++j;
		}
		++i;
	}
}