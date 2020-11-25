#include "list.h"

/**
 * add_node_end - add a node at end of list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: pointer to the new node
 */
List *add_node_end(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);
	new->str = str;

	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
		*list = new;
	}
	else if ((*list)->prev == *list)
	{
		new->prev = *list;
		new->next = *list;
		(*list)->next = new;
		(*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = *list;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}

	return (new);
}

/**
 * add_node_begin - add a node at beginning of list
 * @list: list to modify
 * @str: string to copy into the new node
 * Return: pointer to the new node
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = malloc(sizeof(List));
	if (!new)
		return (NULL);

	new->str = str;
	if (*list == NULL)
	{
		new->prev = new;
		new->next = new;
	}
	else if ((*list)->prev == *list)
	{
		new->prev = *list;
		new->next = *list;
		(*list)->next = new;
		(*list)->prev = new;
	}
	else
	{
		new->prev = (*list)->prev;
		new->next = *list;
		(*list)->prev->next = new;
		(*list)->prev = new;
	}

	(*list) = new;

	return (new);
}
