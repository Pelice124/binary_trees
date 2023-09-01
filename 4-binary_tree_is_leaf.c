#include "binary_trees.h"
/**
 * binary_tree_is_leaf - a function that checks if a node is without child.
 * @node: pointer to the node to be examined.
 * Return: if node is without child 1, otherwise 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node != NULL && node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
