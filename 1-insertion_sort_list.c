#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current = (*list)->next;
    listint_t *insertion_point, *next_node;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (current != NULL)
    {
        insertion_point = current->prev;
        next_node = current->next;

        while (insertion_point != NULL && insertion_point->n > current->n)
        {
            insertion_point = insertion_point->prev;
        }

        if (insertion_point == NULL)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            current->next = *list;
            current->prev = NULL;
            (*list)->prev = current;
            *list = current;
        }
        else if (insertion_point != current->prev)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            current->next = insertion_point->next;
            current->prev = insertion_point;
            if (insertion_point->next != NULL)
                insertion_point->next->prev = current;
            insertion_point->next = current;
        }

        current = next_node;
        print_list(*list);
    }
}
