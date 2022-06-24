#include "merge_sort.h"
#include <stdlib.h>

static void	merge(int *array_to_sort, int start, int end)
{
	int	mid_idx;
	int	result_idx;
	int	size_to_sort;
	int	min;
	int	result[end + 1];

	if (start == end)
		return ;
	size_to_sort = end - start;
	mid_idx = (start + end) / 2;
	result_idx = 0;
	while (result_idx <= size_to_sort)
	{
		if (start > mid_idx || mid_idx > end)
			break ;
		else if (array_to_sort[start] <= array_to_sort[mid_idx + 1])
			min = array_to_sort[start++];
		else
			min = array_to_sort[1 + (mid_idx)++];
		result[result_idx++] = min;
	}
	while (result_idx <= size_to_sort)
	{
		if (start > mid_idx)
			result[result_idx++] = array_to_sort[mid_idx++];
		else
			result[result_idx++] = array_to_sort[start++];

	}
	for(int i = start; i <= size_to_sort; ++i)
		array_to_sort[i] = result[i];
}

static void	devide_array(int *array_to_sort, int start, int end)
{
	int	mid_idx;

	if (start == end)
		return ;
	mid_idx = (start + end) / 2;
	devide_array(array_to_sort, start, mid_idx);
	devide_array(array_to_sort, mid_idx + 1, end);
	merge(array_to_sort, start, end);
}


int	*merge_sort(int *array_to_sort, int size)
{
	devide_array(array_to_sort, 0, size - 1);
}