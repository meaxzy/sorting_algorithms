#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: Node to swap with its next node
 * @right: Node to swap with its previous node
 */

void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;

	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;

	left->prev = right;
	right->next = left;

	if (!right->prev)
		*list = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list 
 * using Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */

void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		end = start;
		while (start->prev != NULL)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			else
			{
				start = start->prev;
			}
		}
		start = start->next;
	}
}
