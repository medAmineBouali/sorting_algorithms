#include "sort.h"

/**
 * heap_sort - Sorts an array of integers using Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	build_heap(array, size);

	for (size_t i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0);
	}
}

/**
 * build_heap - Builds a max heap from the array
 * @array: Array to build the heap from
 * @size: Size of the array
 */
void build_heap(int *array, size_t size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);
}

/**
 * heapify - Maintains the heap property
 * @array: Array representing the heap
 * @size: Size of the heap
 * @root: Index of the root of the heap
 */
void heapify(int *array, size_t size, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
