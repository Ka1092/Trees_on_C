#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Tree* root = NULL;

    char input[1001];
    scanf("%s", input);

    int pos = 0;
    root = create_tree(input, &pos);

    int result = eval_forlmula_tree(root);

    if (division_by_zero) {
        printf("NO");
    }
    else {
        printf("%d", result);
    }

    free_tree(root);
}
