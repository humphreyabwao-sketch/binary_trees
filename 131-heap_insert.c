#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: The height of the binary tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (tree == NULL)
        return 0;

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * heapify_up - Restore the Max Heap property by moving the node up.
 * @node: Pointer to the node to heapify up.
 *
 * Return: Pointer to the node that was moved up.
 */
heap_t *heapify_up(heap_t *node)
{
    heap_t *current = node;

    while (current->parent != NULL && current->n > current->parent->n)
    {
        int tmp = current->n;
        current->n = current->parent->n;
        current->parent->n = tmp;

        current = current->parent;
    }

    return current;
}

/**
 * heap_insert - Insert a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the binary heap.
 * @value: The value to be inserted.
 *
 * Return: A pointer to the created node or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (root == NULL)
        return NULL;

    heap_t *new_node = binary_tree_node(NULL, value);

    if (new_node == NULL)
        return NULL;

    if (*root == NULL)
    {
        *root = new_node;
        return new_node;
    }

    size_t tree_height = binary_tree_height(*root);

    for (int level = 1; level < (int)tree_height; level++)
    {
        heap_t *parent = *root;
        int pos = value;
        while (pos > 1)
        {
            if (pos % 2 == 0)
                parent = parent->left;
            else
                parent = parent->right;
            pos /= 2;
        }

        if (parent->left == NULL)
            parent->left = new_node;
        else
            parent->right = new_node;
        new_node->parent = parent;
    }

    return heapify_up(new_node);
}
