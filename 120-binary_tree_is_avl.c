#include "binary_trees.h"

/**
 * recurse_bst - a function that ecursively checks for BST
 * @tree: pointer to the root node of the tree to be checked
 * @mini: current minimum
 * @maxi: current maximum
 * Return:  if BST, otherwise 0
 */
int recurse_bst(const binary_tree_t *tree, int mini, int maxi)
{
	/* base the case */
	if (tree == NULL)
		return (1);

	/* check if the tree is min or maxi */
	if ((tree->n < mini) || (tree->n > maxi))
		return (0);
	return (recurse_bst(tree->left, mini, tree->n - 1)
		&& recurse_bst(tree->right, tree->n + 1, maxi));
}

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * the balance factor
 * Return: 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int childL = 0, childR = 0;

	/* base the case */
	if (!tree)
		return (0);

	/* checks for balance factor in a node */
	if (!tree->left && !tree->right)
		return (0);

	/* calculate the left and right trees heights */
	childL = binary_tree_height(tree->left);
	childR = binary_tree_height(tree->right);

	/* calculate the balance factor */
	return (childL - childR);
}

/**
 * recurse_height - measure the height
 * @tree: tree to be measured height
 * Return: height
 */
size_t recurse_height(const binary_tree_t *tree)
{
	size_t heightRight, heightLeft;

	if (tree == NULL)
		return (0);

	heightLeft = recurse_height(tree->left);
	heightRight = recurse_height(tree->right);

	if (heightLeft > heightRight)
		return (heightLeft + 1);
	else
		return (heightRight + 1);
}

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (recurse_height(tree) - 1);
}

/**
 * binary_tree_is_avl - a function that checks if the binary tree is a
 * valid AVL tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is AVL valid, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);

	/* check if the tree is ordered */
	if (recurse_bst(tree, INT_MIN, INT_MAX) == 1)
	{
		/* check balance factor */
		balance = binary_tree_balance(tree);
		if (balance == 0)
			return (1);
	}
	return (0);
}
