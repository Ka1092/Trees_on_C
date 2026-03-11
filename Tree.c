#include "Tree.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node *pLeft;
    struct Node *pRight;
};

int division_by_zero = 0;

Tree *create_node(char data) {
    Tree *node = (Tree *)malloc(sizeof(Tree));
    node->data = data;
    node->pLeft = NULL;
    node->pRight = NULL;
    return node;
}

Tree* create_tree(char* str, int* pos) {
    if (str[*pos] == '\0') {
        return NULL;
    }

    char c = str[*pos];
    (*pos)++;

    Tree* root = create_node(c);
    if (c=='+'||c=='-'||c=='*'||c=='/') {
        root->pLeft = create_tree(str, pos);
        root->pRight = create_tree(str, pos);
    }

    return root;
}

void print_tree_postorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    print_tree_postorder(root->pLeft);
    print_tree_postorder(root->pRight);
    printf("%c ", root->data);
}

void print_tree_preorder(Tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
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

int tree_peek_count(Tree *root, int level) {
    if (root == NULL) {
        return 0;
    }
    if (level == 0) {
        return 1;
    }
    return tree_peek_count(root->pLeft, level-1)+tree_peek_count(root->pRight, level-1);
}

int eval_forlmula_tree(Tree *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->data>='0' && root->data<='9') {
        return root->data - '0';
    }

    int left_value = eval_forlmula_tree(root->pLeft);
    int right_value = eval_forlmula_tree(root->pRight);

    switch (root->data) {
        case '+':
            return left_value + right_value;
        case '-':
            return left_value - right_value;
        case '*':
            return left_value * right_value;
        case '/':
            if (right_value == 0) {
                division_by_zero = 1;
                return 0;
            }
            return left_value / right_value;
            default:
            return 0;
    }
}