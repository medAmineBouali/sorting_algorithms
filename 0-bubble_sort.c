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
    unsigned char bubble = 1;
    size_t j = 0;
    size_t k = size - 1;

    while (bubble)
    {
        bubble = 0;
        for (j = 0; j < k; j++)
        {
            if (array[j] > array[j + 1])
            {
                bubble = 1;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size);
            }
            else if (j == k - 1)
            {
                k--;
            }
        }
    }
}
