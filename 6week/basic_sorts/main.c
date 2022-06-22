#include "basic_sort.h"
#include <stdio.h>

void	print_array(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
	}
}

int	main(void)
{
	int array_to_sort[10] = { 9, 3, 1, 4, 0 , 777, 7, 7, -2, -2147483648};

	selection_sort(array_to_sort, 10);
	print_array(array_to_sort, 10);
	return (0);
}