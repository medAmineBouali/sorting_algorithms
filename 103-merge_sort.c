#include "sort.h"

/**
 * merge_sort - Sorts an array of integers using Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_recursive(array, size);
}

/**
 * merge_sort_recursive - Recursive helper function for merge_sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		int *left = array;
		int *right = array + mid;
		size_t left_size = mid;
		size_t right_size = size - mid;

		merge_sort_recursive(left, left_size);
		merge_sort_recursive(right, right_size);

		merge_arrays(array, left, left_size, right, right_size);
	}
}

/**
 * merge_arrays - Merges two arrays into one sorted array
 * @array: Array to store the merged result
 * @left: Left array
 * @left_size: Size of the left array
 * @right: Right array
 * @right_size: Size of the right array
 */
void merge_arrays(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *tmp = malloc(sizeof(int) * (left_size + right_size));

	if (tmp == NULL)
		return;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			tmp[k++] = left[i++];
		else
			tmp[k++] = right[j++];
	}

	while (i < left_size)
		tmp[k++] = left[i++];
	while (j < right_size)
		tmp[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = tmp[i];

	free(tmp);
}
