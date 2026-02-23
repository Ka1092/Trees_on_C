#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

struct Node {
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};

Tree *insert(Tree *root, int data) {
    if (root == NULL) {
        Tree *node = malloc(sizeof(Tree));
        node->data = data;
        node->pLeft = NULL;
        node->pRight = NULL;
        return node;
    }

    if (data < root->data) {
        root->pLeft = insert(root->pLeft, data);
    } else if (data > root->data) {
        root->pRight = insert(root->pRight, data);
    }

    return root;
}

void print_tree_postorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    print_tree_postorder(root->pLeft);
    print_tree_postorder(root->pRight);
    printf("%d ", root->data);
}

void print_tree_preorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    print_tree_preorder(root->pLeft);
    print_tree_preorder(root->pRight);
}

void free_tree(Tree *tree) {
    if (tree == NULL)
        return;
    free_tree(tree->pLeft);
    free_tree(tree->pRight);
    free(tree);
}

int tree_depth(Tree *tree) {
    if (tree == NULL) {
        return -1;
    }

    int left_depth = tree_depth(tree->pLeft);
    int right_depth = tree_depth(tree->pRight);
    if (left_depth > right_depth) {
        return 1 + left_depth;
    } else {
        return 1 + right_depth;
    }
}

int tree_leaves(Tree *tree) {
    if (tree == NULL) {
        return 0;
    }
    if (!tree->pLeft && !tree->pRight) {
        return 1;
    }
    return tree_leaves(tree->pLeft) + tree_leaves(tree->pRight);
}