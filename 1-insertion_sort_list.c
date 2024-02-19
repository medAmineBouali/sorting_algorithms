
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 *
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	curr = (*list)->next;
	while (curr)
	{
		temp = curr->prev;
		while (temp && temp->n > curr->n)
		{
			temp->next = curr->next;
			if (curr->next)
				curr->next->prev = temp;
			curr->prev = temp->prev;
			if (temp->prev)
				temp->prev->next = curr;
			else
				*list = curr;
			curr->next = temp;
			temp->prev = curr;
			temp = curr->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
