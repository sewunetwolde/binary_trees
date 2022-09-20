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


/**
  * binary_tree_size - function that measures the size
  * of a binary tree
  * @tree: is a pointer to the root node of the tree to
  * measure the size
  *
  * Return: Size, If tree is NULL, the function must return 0
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree == NULL)
		return (0);

	count = 1 + binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (count);
}

/**
  * _pow - Returns the value of base raised to the power of exponent
  * @base: the value to multiply
  * @exponent: the times to multiply the value
  *
  * Return: the value multiplied y times
  */
int _pow(int base, int exponent)
{
	int i = 0, value = base;

	for (; i < exponent; ++i)
		value *= base;

	return (value);
}

/**
  * binary_tree_is_perfect - Checks if a binary tree is perfect.
  * @tree: A pointer to the root node of the tree to check.
  *
  * Return: 1 if is perfect, otherwise 0.
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_size, tree_height = 0;

	if (tree == NULL)
		return (0);

	tree_height = binary_tree_height(tree);
	tree_size = binary_tree_size(tree);

	if (tree_size == _pow(2, tree_height) - 1)
		return (1);

	return (0);
}
