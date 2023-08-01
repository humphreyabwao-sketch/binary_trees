#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (*tree == NULL)
    {
        *tree = binary_tree_node(NULL, value);
        return *tree;
    }

    if (value < (*tree)->n)
    {
        (*tree)->left = avl_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        (*tree)->right = avl_insert(&((*tree)->right), value);
    }
    else
    {
        /* Value already exists, do not insert duplicates */
        return NULL;
    }

    /* Update the height of the current node */
    (*tree)->height = 1 + max(avl_height((*tree)->left), avl_height((*tree)->right));

    /* Get the balance factor of the current node */
    int balance = avl_balance(*tree);

    /* Check if the node is unbalanced (balance factor outside the range [-1, 1])
     * Four cases: Left Left, Left Right, Right Right, Right Left */
    if (balance > 1)
    {
        if (value < (*tree)->left->n)
        {
            /* Left Left Case */
            return binary_tree_rotate_right(*tree);
        }
        else
        {
            /* Left Right Case */
            (*tree)->left = binary_tree_rotate_left((*tree)->left);
            return binary_tree_rotate_right(*tree);
        }
    }

    if (balance < -1)
    {
        if (value > (*tree)->right->n)
        {
            /* Right Right Case */
            return binary_tree_rotate_left(*tree);
        }
        else
        {
            /* Right Left Case */
            (*tree)->right = binary_tree_rotate_right((*tree)->right);
            return binary_tree_rotate_left(*tree);
        }
    }

    return *tree;
}

/**
 * max - Returns the maximum of two integers
 *
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum of a and b
 */
int max(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * avl_height - Calculates the height of an AVL tree
 *
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Height of the AVL tree
 */
int avl_height(const avl_t *tree)
{
    if (tree == NULL)
        return -1;

    return tree->height;
}

/**
 * avl_balance - Calculates the balance factor of an AVL tree
 *
 * @tree: Pointer to the root node of the AVL tree
 *
 * Return: Balance factor of the AVL tree
 */
int avl_balance(const avl_t *tree)
{
    if (tree == NULL)
        return 0;

    return avl_height(tree->left) - avl_height(tree->right);
}

