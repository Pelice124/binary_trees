#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs right rotation on a binary tree.
 * @tree: points to the tree to be right-rotated.
 * Return: node roated to the right.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rot_r;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	rot_r = tree->left;
	tree->left = rot_r->right;

	if (rot_r->right != NULL)
		rot_r->right->parent = tree;

	rot_r->parent = tree->parent;

	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = rot_r;
		else
			tree->parent->right = rot_r;
	}
	rot_r->right = tree;
	tree->parent = rot_r;

	return (rot_r);
}
