#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *                       ascending order using the insertion sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *sorted;

    sorted = *list;
    current = sorted->next;

    while (current != NULL)
    {
        listint_t *next_node = current->next;

        if (current->n < sorted->n)
        {
            sorted->prev = current;
            sorted->next = current->next;

            if (current->next != NULL)
                current->next->prev = sorted;

            current->next = sorted;
            current->prev = NULL;

            *list = current;
        }
        else
        {
            listint_t *tmp = sorted;

            while (tmp->next != NULL && tmp->next->n < current->n)
                tmp = tmp->next;

            current->prev = tmp;
            current->next = tmp->next;

            if (tmp->next != NULL)
                tmp->next->prev = current;

            tmp->next = current;
        }

        current = next_node;
        print_list(*list);
    }
}
