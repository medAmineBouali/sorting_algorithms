#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *curr = (*list)->next, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (curr != NULL)
    {
        temp = curr->prev;
        while (temp != NULL && temp->n > curr->n)
        {
            temp = temp->prev;
        }

        if (temp == NULL)
        {
            (*list)->prev = curr;
            (*list)->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = *list;
            curr->next = *list;
            curr->prev = NULL;
            *list = curr;
        }
        else
        {
            temp->next->prev = curr;
            if (curr->next != NULL)
                curr->next->prev = temp;
            curr->prev = temp;
            curr->next = temp->next;
            temp->next = curr;
        }

        print_list(*list);
        curr = curr->next;
    }
}
