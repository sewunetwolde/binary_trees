#include "binary_trees.h"

/**
  * binary_tree_height - function that measures the height of a binary tree
  * @tree: a pointer to the root node of the tree to measure the height.
  *
  * Return: If tree is NULL, function must return 0
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t right_side, left_side;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_side = binary_tree_height(tree->left);
	right_side = binary_tree_height(tree->right);

	if (left_side > right_side)
		return (left_side + 1);
	return (right_side + 1);
}
