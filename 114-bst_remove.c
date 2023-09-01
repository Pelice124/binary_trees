#include "binary_trees.h"
/**
 * bst_remove - Remove a node from a binary search tree.
 * @root: A pointer to the root node of the binary search tree
 * @value: The value of the node to be removed
 * Return: A pointer to the root node of the updated
 * binary search tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
	{
		return (NULL);
	}
	if (value < root->n)
	{
		root->left = bst_remove(root->left, value);
	}
	else if (value > root->n)
	{
		root->right = bst_remove(root->right, value);
	}
	else
	{
		root = remove_node(root);
	}
	return (root);
}

/**
 * find_min - Finds the minimum node in a binary search tree.
 * node: Pointer to the root node of the binary search tree
 * to search from.
 * Return: Pointer to the minimum node found.
 */
bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return (node);
}

/**
 * remove_node - Removes a node from a binary search tree.
 * root: Pointer to the root node of the binary search tree.
 * Return: he updated root node after removing the specified node.
 */

bst_t *remove_node(bst_t *root)
{
	bst_t *right_child;
	bst_t *left_child;
	bst_t *min_node;

	if (root->left == NULL)
	{
		right_child = root->right;
		free(root);
		return (right_child);
	}
	else if (root->right == NULL)
	{
		left_child = root->left;
		free(root);
		return (left_child);
	}
	min_node = find_min(root->right);
	root->n = min_node->n;
	root->right = bst_remove(root->right, min_node->n);
	return (root);
}
