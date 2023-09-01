#include "binary_trees.h"
/**
 * binary_tree_node - a function that creates new node
 * @parent: root note of the binary tree
 * @value: value of the new node to be created
 * Return: NULL if memory allocation fails or address
 * of new node if successful.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = new_node->right = NULL;

	return (new_node);
}
