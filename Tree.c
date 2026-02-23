#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "Tree.h"

typedef struct Node {
    int data;
    struct Node *pLeft;
    struct Node *pRight;
} Tree;

Tree* createTree(void) {
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = INT_MAX;
    root->pLeft = NULL;
    root->pRight = NULL;
    return root;
}
void printTree(Tree *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    printTree(root->pLeft);
    printTree(root->pRight);
}
