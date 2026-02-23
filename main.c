#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tree.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tree* root = NULL;

    int data;
    while (scanf("%d", &data) == 1) {
        root = insert(root, data);
    }
    print_tree_preorder(root);
    printf("\n");
    print_tree_postorder(root);
    printf("\n");

    free_tree(root);
    return 0;
}
