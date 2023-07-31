#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    binary_tree_t **queue = NULL;
    size_t front = 0, rear = 0;

    if (tree == NULL || func == NULL)
        return;

    queue = malloc(sizeof(binary_tree_t *) * 1024);
    if (queue == NULL)
        return;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *current = queue[front++];

        func(current->n);

        if (current->left)
            queue[rear++] = current->left;

        if (current->right)
            queue[rear++] = current->right;
    }

    free(queue);
}
