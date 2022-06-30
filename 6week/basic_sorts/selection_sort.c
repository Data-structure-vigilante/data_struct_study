#include "basic_sort.h"

void swap(int *array_to_sort, int i, int j)
{
	int temp;

	temp = array_to_sort[i];
	array_to_sort[i] = array_to_sort[j];
	array_to_sort[j] = temp;
}

void	selection_sort(int *array_to_sort, int size)
{
	int	min_value;
	int	min_idx;
	int	i;
	int	j;

	min_idx = 0;
	i = 0;
	while (i < size - 1)
	{
		min_value = MIN;
		j = i + 1;
		while (j < size)
		{
			if (min_value > array_to_sort[j])
			{
				min_value = array_to_sort[j];
				min_idx = j;
			}
			++j;
		}
		swap(array_to_sort, i, min_idx);
		++i;
	}
}