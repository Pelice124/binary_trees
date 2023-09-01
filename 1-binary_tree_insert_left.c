#include "binary_trees.h"
/**
 * binary_tree_insert_left - function that inserts a node
 * as the left-child of another node
 * @parent: root node of the binary tree.
 * @value: value assigned to node.
 * Return: a new node at the left side of parent node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child;

	if (parent == NULL)
		return (NULL);

	left_child = malloc(sizeof(binary_tree_t));

	left_child->n = value;
	left_child->parent = parent;
	left_child->right = NULL;
	left_child->left = NULL;

	if (left_child == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		left_child->left = parent->left;
		parent->left->parent = left_child;
	}
	parent->left = left_child;

	return (left_child);
}
