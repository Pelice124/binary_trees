#include "binary_trees.h"
/**
 * *bst_insert - insert a value in a binary search tree.
 * @tree:  a double pointer to the root node of the BST
 * to insert the value
 * @value: value to store in the node to be inserted
 * Return: NULL upon failure. Otherwise, a pointer to the node
 * created.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *old;

	if (*tree == NULL)
	{
		*tree = (bst_t *)binary_tree_node(NULL, value);
		return (*tree);
	}
	new = *tree;
	while (new != NULL)
	{
		old = new;
		if (value < new->n)
			new = new->left;
		else if (value > new->n)
			new = new->right;
		else
			return (NULL);
	}
	new = (bst_t *)binary_tree_node(old, value);
	if (new == NULL)
		return (NULL);
	if (value < old->n)
		old->left = new;
	else
		old->right = new;
	return (new);
}
