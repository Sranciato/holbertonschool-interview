#include "binary_trees.h"
/**
 * get_size - gets number of nodes
 * @tree: root node of tree
 * Return: number of nodes
 */
size_t get_size(const binary_tree_t *tree)
{
    if (!tree)
    {
        return (0);
    }
    return (get_size(tree->left) + get_size(tree->right) + 1);
}
/**
 * is_complete - checks if tree is complete
 * @tree: root node of tree
 * @i: index
 * @size: size of tree
 * Return: true if complete
 */
int is_complete(const binary_tree_t *tree, int i, int size)
{
    if (!tree)
        return (1);
    if (i >= size)
        return (0);
    return (is_complete(tree->left, (2 * i) + 1, size) &&
        is_complete(tree->right, (2 * i) + 2, size));
}
/**
 * complete - get size and calls is_complete
 * @tree: root node of tree
 * Return: returns true if complete
 */
int complete(const binary_tree_t *tree)
{
    size_t tree_size;

    if (!tree)
        return (0);
    tree_size = get_size(tree);
    return(is_complete(tree, 0, tree_size));
}
/**
 * heap_insert - inserts a value into a max binary heap
 * @root: double pointer to the root node
 * @value: value to be inserted
 * Return: returns a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new;

    if (!root)
        return (NULL);
    new = binary_tree_node(NULL, value);
    if (!new)
        return (NULL);
    if (!(*root))
    {
        *root = new;
        return (new);
    }
    if (complete(*root))
    {
        if ((*root)->left)
        {
            return (heap_insert(&((*root)->left), value));
        }
        else
        {
            return((*root)->left = binary_tree_node(*root, value));
        }
        
    }
    if (!complete((*root)->left))
    {
        if ((*root)->left)
        {
            return (heap_insert(&((*root)->left), value));
        }
        else
        {
            return((*root)->left = binary_tree_node(*root, value));
        }
    }
    if ((*root)->right)
    {
        return(heap_insert(&((*root)->right), value));
    }
    else
    {
        return ((*root)->right = binary_tree_node(*root, value));
    }
    return (NULL);

}