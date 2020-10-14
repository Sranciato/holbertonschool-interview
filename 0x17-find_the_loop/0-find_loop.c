#include "lists.h"

/**
 * find_listint_loop = find if a linked list loops
 * @head: first node in a linked list
 * Return: the address of the node where the loop starts
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

    while (fast && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return (slow);
    }
    return (NULL);
}