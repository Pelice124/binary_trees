#include "binary_trees.h"
/**
 * binary_tree_preorder -function that goes through a binary
 * tree using pre-order traversal
 * @tree:points to the root node of the binary tree.
 * @func: function that calls each node as they are
 * traversed.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree != NULL && func != NULL)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
