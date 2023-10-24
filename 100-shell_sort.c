#include "sort.h"

/**
 * _swap - Swap two integers in an array.
 * @i1: The first integer to swap.
 * @i2: The second integer to swap.
 */
void _swap(int *i1, int *i2)
{
	int temp = *i1;

	*i1 = *i2;
	*i2 = temp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 * The shell sort is an optimized version of insertion sort.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i = 0, j = 0, k = 0;

	if (!array || size < 2)
		return;

	/* init gap with Knuth sequence*/
	while (gap * 3 + 1 < size)
		gap = gap * 3 + 1;

	for (i = gap; i; i = (i - 1) / 3)
	{
		for (j = i; j < size; ++j)
			for (k = j;
			(int)(k - i) >= 0 && array[k] < array[k - i]; k -= i)
				_swap(&array[k - i], &array[k]);
		print_array(array, size);
	}
}
