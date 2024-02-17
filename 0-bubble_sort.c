#include <stdio.h>
#include <stdlib.h>
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
    char bubble = 1;
    size_t j = 0;

    while (bubble)
    {
        bubble = 0;
        for (j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                bubble = 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
        }
    }
}
