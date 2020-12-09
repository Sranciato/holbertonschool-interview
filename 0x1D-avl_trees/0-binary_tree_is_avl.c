#include "binary_trees.h"

/**
 * get_height - gets height of tree
 * @tree: pointer to the root node
 * Return: height of tree
 */
size_t get_height(const binary_tree_t *tree)
{
	size_t right = 0, left = 0;

	if (tree)
	{
		if (tree->left)
			left += get_height(tree->left) + 1;
		if (tree->right)
			right += get_height(tree->right) + 1;
	}
	return (right < left ? left : right);
}

/**
 * rec_is_avl - recursively checks if tree is avl
 * @tree: pointer to root node
 * @max: max limit for int
 * @min: min limit for int
 * Return: 1 on success, 0 on failure
 */
size_t rec_is_avl(const binary_tree_t *tree, int max, int min)
{
	size_t l = get_height(tree->left), r = get_height(tree->right);

	if (!tree)
		return (0);
	l = l > r ? l - r : r - l;
	if (l > 0)
		return (0);
	l = 1;
	r = 1;
	if (tree->left && ((tree->left->n >= tree->n) || (tree->left->n <= min)))
		return (0);
	if (tree->right && ((tree->right->n <= tree->n) || (tree->right->n >= max)))
		return (0);
	if (tree->left)
		l = rec_is_avl(tree->left, tree->n, min);
	if (tree->right)
		r = rec_is_avl(tree->right, max, tree->n);
	return (l == 1 && r == 1);
}

/**
 * binary_tree_is_avl - checks if binary tree is valid
 * @tree: pointer to root node
 * Return: 1 on success, 0 on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	return (rec_is_avl(tree, INT_MAX, INT_MIN));
}
