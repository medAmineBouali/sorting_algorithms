#include "sort.h"
/**
 * swap - swap two elements of array
 * @i: pointer to element 1
 * @j: pointer to element 2
 * Return: none
 */

void swap(int *i, int *j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
/**
 * partition - Process where the array is organized.
 * @array: Data structure.
 * @low: Index low
 * @high: Index high
 * @size: size array
 * Return: Index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j = low;

	while (j <= high - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}
/**
 * _quicksort - quick sort implementation
 * @array: Data structure.
 * @low: Index low
 * @high: Index high
 * @size: Size Data structure.
 */
void _quicksort(int *array, int low, int high, size_t size)
{

	if (low < high)
	{
		int part = partition(array, low, high, size);

		_quicksort(array, low, part - 1, size);
		_quicksort(array, part + 1, high, size);
	}
}
/**
 * quick_sort -  function that sorts an array of integers in ascending
 *               order using the Quick sort algorithm
 * @array: data structure that the function is applied to
 * @size: Data structure size
 */
void quick_sort(int *array, size_t size)
{
	if (!array  || size < 2)
		return;
	_quicksort(array, 0, size - 1, size);
}
