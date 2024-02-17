#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *                  the selection sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    size_t i, j, min_index;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;

        // Find the index of the minimum element in the unsorted part of the array
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        // Swap the minimum element with the first element of the unsorted part
        if (min_index != i)
        {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            print_array(array, size);
        }
    }
}
