#include "binary_trees.h"

/**
  * binary_tree_insert_left - Inserts a node as the left-child
  * of another node.
  * @parent: A pointer to the node to insert the left-child in.
  * @value: The value to store in the new node.
  *
  * Return: A pointer to the created node, or NULL on failure or
  * if parent is NULL.
  */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left_node = NULL;

	if (parent == NULL)
		return (NULL);

	new_left_node = malloc(sizeof(binary_tree_t));
	if (new_left_node == NULL)
		return (NULL);

	new_left_node->parent = parent;
	new_left_node->n = value;

	if (parent->left)
	{
		new_left_node->left = parent->left;
		new_left_node->left->parent = new_left_node;
	}
	else
		new_left_node->left = NULL;

	new_left_node->right = NULL;
	parent->left = new_left_node;

	return (new_left_node);
}
