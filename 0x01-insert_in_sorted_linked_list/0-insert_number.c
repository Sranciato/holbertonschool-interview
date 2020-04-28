#include "lists.h"

/**
 * insert_node - insert node in correct position
 * @head: head of linked list
 * @number: number to be added to list
 * Return: the address of the new node, or NULL if it failed
 */
 listint_t *insert_node(listint_t **head, int number)
 {
    listint_t *new, *search = *head;

	if (*head == NULL || search->n > number)
	{
		new = malloc(sizeof(listint_t));
		if (!new)
			return (NULL);
		new->n = number;
		new->next = *head;
		*head = new;
		return (new);
	}
	while (search)
	{
		if (!search->next || search->next->n > number)
		{
			new = malloc(sizeof(listint_t));
			if (!new)
				return (NULL);
			new->n = number;
			new->next = search->next;
			search->next = new;
			return (new);
		}
		search = search->next;
	}
	return (NULL);
 }