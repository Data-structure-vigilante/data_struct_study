#ifndef BASIC_SORT_H
# define BASIC_SORT_H

# define MIN 2147483647

void	selection_sort(int *array_to_sort, int size);
void	bubble_sort(int *array_to_sort, int size);
void	insertion_sort(int *array_to_sort, int size);
void	swap(int *array_to_sort, int i, int j);
void	shell_sort(int *arr_to_sort, int size);

#endif