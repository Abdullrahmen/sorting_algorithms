#include "sort.h"

/**
* swap_adjacent - swap adjacent nodes of a doubly linked list
* @head: head
* @node: the node
* @is_ahead: is swap with the ahead node
*/
void swap_adjacent(listint_t **head, listint_t *node, char is_ahead)
{
	listint_t *tmp = NULL;

	if (!head || !*head || !node)
		return;

	if (is_ahead && node->next)
	{
		tmp = node->next;
		if (*head == node)
			*head = tmp;

		if (tmp->next)
			tmp->next->prev = node;
		if (node->prev)
			node->prev->next = tmp;
		tmp->prev = node->prev;
		node->next = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	else if (!is_ahead && node->prev)
	{
		tmp = node->prev;
		if (*head == tmp)
			*head = node;

		if (tmp->prev)
			tmp->prev->next = node;
		if (node->next)
			node->next->prev = tmp;
		tmp->next = node->next;
		node->prev = tmp->prev;
		tmp->prev = node;
		node->next = tmp;
	}
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *iter = NULL;
	char swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	iter = *list;
	while (swapped)
	{
		swapped = 0;

		for (; iter->next && iter->n < iter->next->n; iter = iter->next)
			;
		while (iter->next && iter->n > iter->next->n)
		{
			swap_adjacent(list, iter, 1);
			swapped = 1;
			print_list(*list);
		}

		for (; iter->prev && iter->n > iter->prev->n; iter = iter->prev)
			;
		while (iter->prev && iter->n < iter->prev->n)
		{
			swap_adjacent(list, iter, 0);
			swapped = 1;
			print_list(*list);
		}
	}
}
