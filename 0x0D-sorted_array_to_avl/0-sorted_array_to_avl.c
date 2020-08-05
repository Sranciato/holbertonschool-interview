#include <stdlib.h>
#include "binary_trees.h"

/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *new = NULL;
	size_t middle;

	if (!size || !array)
		return (NULL);

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);

	middle = (size - 1) / 2;
	new->n = array[middle];
	new->parent = NULL;

	if (middle > 0)
		new = sorted_array_to_avl(array, middle);
	else
		new->left = NULL;

	if ((middle + 1) < size)
		new = sorted_array_to_avl(&array[middle + 1], size - (middle + 1));
	else
		new->right = NULL;
	return (new);
}
