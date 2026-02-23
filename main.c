#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tree.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tree *root = NULL;

    char string[101];
    int k;
    scanf("%d", &k);
    while (scanf("%s", string) == 1) {
        root = insert(root, string);
    }
    print_tree_inorder(root);

    free_tree(root);
    return 0;
}
