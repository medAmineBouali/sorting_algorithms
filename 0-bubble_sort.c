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

    for (size_t i = 0; i < size - 1; i++)
    {
        if(array[i] > array[i + 1])
        {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            print_array(array,size);
        }
    }
    
}