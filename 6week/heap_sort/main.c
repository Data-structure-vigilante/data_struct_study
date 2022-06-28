#include "heap_sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void	print_array(int *array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf(" %d", array[i]);
	}
}

int *createBigArray(int size)
{
	int *arr;
	int value;

	value = size;
	arr = (int *)calloc(size, sizeof(int));
	for (int i = 0; i < size; ++i)
	{
		arr[i] = value;
		--value;
	}
	return (arr);
}

int	main(void)
{
	int array_to_sort[10] = { 9, 3, 1, 4, 0 , 777, 7, 7, -2, -2147483648};
	int *arr;
	float start, end;
	int size;

	size = 10;
	// size = 10;

	arr = createBigArray(size);
	start = (float)clock()/CLOCKS_PER_SEC;

	heap_sort(array_to_sort, size);
	print_array(array_to_sort, size);

	end = (float)clock()/CLOCKS_PER_SEC;
	printf("\nTime : %f\n", end - start);
}