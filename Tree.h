#ifndef TREES_TREE_H
#define TREES_TREE_H

typedef struct Node Tree;

Tree* insert(Tree* root, char* str);
void print_tree_postorder(Tree *root);
void print_tree_inorder(Tree *root);
void print_tree_preorder(Tree *root);
void free_tree(Tree *root);
int tree_depth(Tree *root);
int tree_leaves(Tree *root);
int tree_peek_count(Tree *root, int level);

#endif