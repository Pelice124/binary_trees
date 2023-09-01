#include "binary_trees.h"
/**
 * bst_search -  searches for a value in a Binary Search Tree.
 * @tree: points to the root node to be searched.
 * @value: value to search for in the tree.
 * Return: pointer to the node containing a value equals to value.
 * Otherwise NULL if tree is NULL or nothing is found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
	{
		return ((bst_t *)tree);
	}
	if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}
	else if (value > tree->n)
	{
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
