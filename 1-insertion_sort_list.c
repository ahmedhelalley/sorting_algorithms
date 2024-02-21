#include "sort.h"

/**
 * insertion_sort_list - algorithm of insertion sorting
 * @list: the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node, *prev_node;

	if (!list || !(*list) || is_small_list(list))
		return;

	for (curr_node = (*list)->next; curr_node; curr_node = curr_node->next)
	{
		int data = curr_node->n;

		prev_node = curr_node->prev;

		while (prev_node && prev_node->n > data)
		{
			swap_nodes(list, curr_node, prev_node);
			print_list(*list);
			prev_node = curr_node->prev;
		}
	}
}

/**
 * is_small_list - checking if list have less than two elements or not
 * @list: the list to be sorted
 * Return: true if it has less than 2 elements, otherwise false
 */
bool is_small_list(listint_t **list)
{
	if (!(*list)->next)
		return (true);

	return (false);
}

/**
 * swap_nodes - exchanges two nodes in a linked list
 * @list: the list to be sorted
 * @curr_node: the current node
 * @prev_node: the previous node
 */
void swap_nodes(listint_t **list, listint_t *curr_node, listint_t *prev_node)
{
	prev_node->next = curr_node->next;
	if (curr_node->next)
		curr_node->next->prev = prev_node;

	curr_node->next = prev_node;
	curr_node->prev = prev_node->prev;
	prev_node->prev = curr_node;
	if (curr_node->prev)
		curr_node->prev->next = curr_node;
	else
		*list = curr_node;
}
