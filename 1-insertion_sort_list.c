#include "sort.h"

/**
 * swap_nodes - swaps two nodes on a singly linked list
 * @first_node: First node to swap
 * @second_node: Second node to swap
 */

void swap_nodes(listint_t **head, listint_t *first_node, listint_t *second_node)
{
	if (!first_node || !second_node)
		return;
	if (*head == first_node)
		*head = second_node;
	if (first_node->prev)
		(first_node->prev)->next = first_node->next;
	if (second_node->next)
		(second_node->next)->prev = second_node->prev;
	first_node->next = second_node->next;
	second_node->next = first_node;
	second_node->prev = first_node->prev;
	first_node->prev = second_node;
}

/**
 * insertion_sort_list - Sorts a list through insertion sort algorithm
 * @list: List to sort represented on a doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *previous_node, *next_node;

	if (list && *list)
	{
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
}
