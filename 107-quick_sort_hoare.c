#include "sort.h"

/**
 * _swap - Swap two integers in an array.
 * @i1: The first integer to swap.
 * @i2: The second integer to swap.
 */
void _swap(int *i1, int *i2)
{
	int tmp = *i1;

	*i1 = *i2;
	*i2 = tmp;
}

/**
 * partition_hoare - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @full_size: The size of the array.
 * @low: The starting index of the subset to order.
 * @high: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int partition_hoare(int *array, int low, int high, size_t full_size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{

		while (array[i] < pivot)
			++i;
		while (array[j] > pivot)
			--j;

		if (i >= j)
			return (i);

		_swap(&array[i], &array[j]);
		print_array(array, full_size);
	}
}

/**
 * hoare_quick_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @full_size: The size of the array.
 * @low: The starting index of the array partition to order.
 * @high: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_quick_sort(int *array, int low, int high, size_t full_size)
{
	int pivot = 0;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, full_size);

		hoare_quick_sort(array, low, pivot - 1, full_size);
		hoare_quick_sort(array, pivot, high, full_size);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_quick_sort(array, 0, size - 1, size);
}
