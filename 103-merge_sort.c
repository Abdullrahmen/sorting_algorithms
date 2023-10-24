#include "sort.h"

void merge_subarr(int *subarr, int *output, size_t left, size_t mid,
		size_t right);
void merge_sort_recursive(int *subarr, int *output, size_t left, size_t right);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @output: A outputer to store the sorted subarray.
 * @left: The left index of the array.
 * @mid: The middle index of the array.
 * @right: The right index of the array.
 */
void merge_subarr(int *subarr, int *output, size_t left, size_t mid,
		size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + left, mid - left);

	printf("[right]: ");
	print_array(subarr + mid, right - mid);

	for (i = left, j = mid; i < mid && j < right; k++)
		output[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		output[k++] = subarr[i];
	for (; j < right; j++)
		output[k++] = subarr[j];
	for (i = left, k = 0; i < right; i++)
		subarr[i] = output[k++];

	printf("[Done]: ");
	print_array(subarr + left, right - left);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @output: A outputer to store the sorted result.
 * @left: The left index of the subarray.
 * @right: The right index of the subarray.
 */
void merge_sort_recursive(int *subarr, int *output, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = left + (right - left) / 2;
		merge_sort_recursive(subarr, output, left, mid);
		merge_sort_recursive(subarr, output, mid, right);
		merge_subarr(subarr, output, left, mid, right);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	merge_sort_recursive(array, output, 0, size);

	free(output);
}
