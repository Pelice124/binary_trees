#include "binary_trees.h"
#include "limits.h"

size_t binary_tree_height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int min_val, int max_val);
int binary_tree_is_avl(const binary_tree_t *tree);
/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure
 * the height.
 * Return: If tree is NULL, the function returns 0, else the height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	return (1 + (l_height > r_height ? l_height : r_height));
}

/**
 * is_avl_helper - Checks if a binary tree is a valid AVL tree.
 * @tree:A pointer to the root node of the tree to check.
 * @min_val: The minimum allowed value for nodes in the tree.
 * @max_val: The maximum allowed value for nodes in the tree.
 * Return: If the tree is a valid AVL tree, returns 1, else returns 0
 */
int is_avl_helper(const binary_tree_t *tree, int min_val, int max_val)
{
	size_t l_height, r_height, height_diff;

	if (tree == NULL)
		return (1);

	if (tree->n <= min_val || tree->n >= max_val)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	height_diff = l_height > r_height ?
		l_height - r_height : r_height - l_height;

	if (height_diff > 1)
		return (0);

	return (is_avl_helper(tree->left, min_val, tree->n)
			&& is_avl_helper(tree->right, tree->n, max_val));
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is valid. Otherwise 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
