#include "basic_sort.h"



void	quick_sort(int *array_to_sort, int start_idx, int end_idx)
{
	int		pivot_idx;
	int		left_idx;
	int		right_idx;

	if (end_idx - start_idx < 2)
		return ;
	pivot_idx = end_idx;
	right_idx = end_idx;
	left_idx = start_idx;

	while (left_idx != right_idx)
	{
		if (array_to_sort[left_idx] <= array_to_sort[pivot_idx])
			++left_idx;
		if (array_to_sort[right_idx] >= array_to_sort[pivot_idx])
			--right_idx;
		if (array_to_sort[left_idx] > array_to_sort[pivot_idx] && array_to_sort[right_idx] < array_to_sort[pivot_idx])
			swap(array_to_sort, left_idx, right_idx);
	}

	if (array_to_sort[left_idx] > array_to_sort[pivot_idx])
	{
		swap(array_to_sort, left_idx, pivot_idx);
		pivot_idx = left_idx;
	}

	quick_sort(array_to_sort, start_idx, pivot_idx - 1);
	quick_sort(array_to_sort, pivot_idx + 1, end_idx);

}