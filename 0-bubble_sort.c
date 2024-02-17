#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Prints an array of integers
 *
 * @array: The array to be sorted and printed
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
    int temp = 0;
    char bubble = 0;
    size_t j = 0;
    while (1)
    {
        bubble = 0;
        for(j = 0; j < size - 1; j++)
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
        if (!bubble)
        {
            break;
        }
    }
}
