#include "binary_trees.h"
/**
 * array_to_bst - builds a binary search tree from an array.
 * @array: points to the array to be transformed to a BST.
 * @size: element counts of the array.
 * Return: pointer to the root node of the created
 * BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tree = NULL;

	if (array == NULL || size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
