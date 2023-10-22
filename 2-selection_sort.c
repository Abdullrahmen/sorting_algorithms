#include "sort.h"

/**
 * _swap - Swaps two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void _swap(int *i1, int *i2)
{
	int i3 = *i1;

	*i1 = *i2;
	*i2 = i3;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t min_idx = 0, idx = 0, i = 0;

	while (idx != size - 1)
	{
		min_idx = idx;
		for (i = idx; i < size; ++i)
			if (array[i] < array[min_idx])
				min_idx = i;

		if (min_idx != idx)
		{
			_swap(&array[min_idx], &array[idx]);
			print_array(array, size);
		}
		++idx;
	}
}
