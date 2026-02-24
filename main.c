#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tree.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tree *root = NULL;

    char* input = malloc(sizeof(char)*100);
    char str[100];
    int j = 0;

    while (scanf("%s", input) != EOF) {
        for (int i = 0; i < strlen(input); i++, j++) {
            str[j] = input[i];
        }
        str[j] = ' ';
        j++;
    }
    j--;
    while (j >= 0) {
        if (str[j] != ' ') {
            root = insert(root, str[j--]);
            continue;
        }
        j--;
    }
    print_tree_preorder(root);

    free_tree(root);
    return 0;
}
