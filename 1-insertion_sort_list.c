#include "sort.h"

/**
 * swap_nodes - Swaps two nodes on a singly linked list
 * @first: First node to swap
 * @second: Second node to swap
 * @head: Head of the dbl lnkd list
 */

void swap_nodes(listint_t **head, listint_t *first, listint_t *second)
{
	if (!first || !second)
		return;
	if (*head == first)
		*head = second;
	if (first->prev)
		(first->prev)->next = first->next;
	if (second->next)
		(second->next)->prev = second->prev;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
}

/**
 * insertion_sort_list - Sorts a list through insertion sort algorithm
 * @list: List to sort represented on a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *previous_node, *next_node;

	if (!list || !(*list))
		return;
	current_node = *list;
	while (current_node)
	{
		previous_node = current_node->prev;
		next_node = current_node->next;
		while (previous_node)
		{
			if (current_node->n < previous_node->n)
			{
				swap_nodes(list, previous_node, current_node);
				print_list(*list);
				previous_node = current_node->prev;
			}
			else
				break;
		}
		current_node = next_node;
	}
}
