#include "binary_trees.h"
#include <limits.h>
/**
 * validate_bst - confirms if a binary tree is a valid binary search
 * tree.
 * @tree: points to the root node to be validated.
 * @low_lim: node with the least value visited.
 * @up_lim: node with the hifhest value visited.
 * Return: 1 if valid. Otherwise 0.
 */
int validate_bst(const binary_tree_t *tree, int low_lim, int up_lim)
{
	if (tree == NULL)
		return (1);

	if ((low_lim != INT_MIN && tree->n <= low_lim) ||
			(up_lim != INT_MAX && tree->n >= up_lim))
		return (0);

	return (validate_bst(tree->left, low_lim, tree->n) &&
			validate_bst(tree->right, tree->n, up_lim));
}

/**
 * binary_tree_is_bst - perform checks for the validity of the binary tree
 * @tree: points to the root node to be checked.
 * Return: 1 if node is a valid BST.  Otherwise 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (validate_bst(tree->left, INT_MIN, tree->n) &&
				validate_bst(tree->right, tree->n, INT_MAX))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
			{
				return (1);
			}
		}
	}
	return (0);
}
