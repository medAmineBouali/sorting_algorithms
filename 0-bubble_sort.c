#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{

	int temp = 0;
	size_t i, j;
	char bubble;

	for (i = 0; i < size - 1; i++)
	{
		bubble = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				bubble = 1;
				print_array(array, size);
			}
		}
		if (!bubble)
		{
			break;
		}
	}
}
