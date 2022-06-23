#include "basic_sort.h"

void	sh_insert_element(int *array_to_sort, int from, int to)
{
	int temp;
	int i;

	temp = array_to_sort[from];
	i = from - 1;
	while (i >= to)
	{
		array_to_sort[i + 1] = array_to_sort[i];
		--i;
	}
	array_to_sort[to] = temp;
}

void	sh_insertion_sort(int *array_to_sort, int start, int size , int gap)
{
	//start idx 설정
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (array_to_sort[i] < array_to_sort[j])
				break ;
			++j;
		}
		insert_element(array_to_sort, i, j);
		i += gap;
	}
}

void	shell_sort(int *arr_to_sort, int size)
{
	//gap 설정

	while (gap >= 1)

	//끝
}
