#include "binary_trees.h"

/**
 * recurse_levelorder - a function that recursively traverse
 *  through the level of the tree
 * @tree: pointer to the root node of the tree to be traversed
 * @func: function to traverse
 * @lev: tree level
 */
void recurse_levelorder(const binary_tree_t *tree,
	void (*func)(int), size_t lev)
{
	if (!tree)
		return;

	if (lev == 0)
		func(tree->n);

	recurse_levelorder(tree->left, func, lev - 1);
	recurse_levelorder(tree->right, func, lev - 1);
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
 * binary_tree_levelorder - a function that goes through a binary tree
 * using a level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t hei, lev = 0;

	/* base the case */
	if (tree == NULL || func == NULL)
		return;

	/* retrieve the height of the tree */
	hei = binary_tree_height(tree);

	while (lev <= hei)
	{
		recurse_levelorder(tree, func, lev);
		lev++;
	}
}
