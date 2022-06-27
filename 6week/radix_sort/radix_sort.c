#include "radix_sort.h"
#include <stdlib.h>
#include <string.h>

int	get_maximum_digits(int *temp_array, int size)
{
	int	max = -2147483648;
	int max_digits = 0;
	int	i = 0;

	while (i < size)
	{
		if (temp_array[i] > max)
			max = temp_array[i];
		i++;
	}
	i = 0;
	if (max == 0)
		return (1);
	while (max > 0)
	{
		++max_digits;
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
	LinkedList	*bucket_array;

	temp_array = (int *)calloc(size, sizeof(int));
	bucket_array = (LinkedList *)calloc(10, sizeof(LinkedList));
	memcpy(temp_array, array_to_sort, size * sizeof(int));
	max_digits = get_maximum_digits(temp_array, size);
	while (i < max_digits)
	{
		//버킷에 옮겼다가 
		while (j < size)
		{
			//i * 10
		}
		//버킷 순으로 템프에 옮기기
		while (j < size)
		{

		}
	}
}