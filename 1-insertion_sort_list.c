#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 * using the Insertion Sort algorithm.
 * @list: Pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			prev = current->prev;

			if (current->next != NULL)
				current->next->prev = prev;
			prev->next = current->next;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);
		}

		current = next;
	}
}
