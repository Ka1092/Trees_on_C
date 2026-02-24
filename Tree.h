#ifndef TREES_TREE_H
#define TREES_TREE_H

typedef struct Node Tree;

extern int division_by_zero;

Tree* create_node(char data);
Tree* create_tree(char* str, int* pos);
void print_tree_postorder(Tree *root);
void print_tree_preorder(Tree *root);
void free_tree(Tree *root);
int tree_depth(Tree *root);
int tree_leaves(Tree *root);
int tree_peek_count(Tree *root, int level);
int eval_forlmula_tree(Tree *root);

#endif