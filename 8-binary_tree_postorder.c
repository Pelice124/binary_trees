#include "binary_trees.h"
/**
 * binary_tree_postorder - function that uses postorder method
 * to traverse a node.
 * @tree: points to the root node of the binary tree.
 * @func: points to the function that calls each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
