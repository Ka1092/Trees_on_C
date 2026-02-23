#ifndef TREES_TREE_H
#define TREES_TREE_H

typedef struct Node Tree;

Tree* insert(Tree* root, int data);
void print_tree_postorder(Tree *root);
void print_tree_preorder(Tree *root);
void free_tree(Tree *root);
int tree_depth(Tree *root);
int tree_leaves(Tree *root);

#endif