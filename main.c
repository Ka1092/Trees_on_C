#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Tree.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tree *root = NULL;

    int data;
    int k;
    scanf("%d", &k);
    while (scanf("%d", &data) == 1) {
        root = insert(root, data);
    }
    printf("%d", tree_peek_count(root, k));

    free_tree(root);
    return 0;
}
