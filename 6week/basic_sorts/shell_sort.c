#include "basic_sort.h"

static void	insert_element_gap(int *array_to_sort, int from, int to, int gap)
{
	int temp;
	int i;

	temp = array_to_sort[from];
	i = from - gap;
	while (i >= to)
	{
		array_to_sort[i + gap] = array_to_sort[i];
		i -= gap;
	}
	array_to_sort[to] = temp;
}

static void	insertion_sort_gap(int *array_to_sort, int start, int end, int gap)
{
	int from;
	int to;

	from = start + gap;
	while (from <= end)
	{
		to = start;
		while (to < from && to <= end)
		{
			if (array_to_sort[from] < array_to_sort[to])
			{
				insert_element_gap(array_to_sort, from, to, gap);
			}
			to += gap;
		}
		from += gap;
	}
}

void	shell_sort(int *arr_to_sort, int size)
{
	int	gap;
	int	start;

	gap = size / 2;
	while (gap >= 1)
	{
		if (gap % 2 == 0)
			++gap;
		start = 0;
		while (start < gap)
		{
			insertion_sort_gap(arr_to_sort, start, size - 1, gap);
			++start;
		}
		gap /= 2;
	}
}
