#include "binary_trees.h"
/**
 * binary_tree_insert_right - function that inserts a node
 * as the right-child of another node
 * @parent: root node of the binary tree.
 * @value: data assigned to node
 * Return: new node at the left side of parent node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (parent == NULL)
		return (NULL);

	right_child = malloc(sizeof(binary_tree_t));

	right_child->n = value;
	right_child->parent = parent;
	right_child->left = NULL;
	right_child->right = NULL;

	if (right_child == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		right_child->right = parent->right;
		parent->right->parent = right_child;
	}
	parent->right = right_child;

	return (right_child);
}
