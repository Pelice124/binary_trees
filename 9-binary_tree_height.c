#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: points to the root node of the binary tree.
 * Return: the height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh;
	size_t rh;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	lh = binary_tree_height(tree->left);
	lh++;
	rh = binary_tree_height(tree->right);
	rh++;

	return (lh > rh ? lh : rh);
}
