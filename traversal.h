#ifndef __TRAVERSAL_H__
#define __TRAVERSAL_H__
#include "tree_c.h"

void inorderprint (tree_t tree);
void postorderprint (tree_t tree);
void preorderprint (tree_t tree);
void breadth_first (tree_t tree);

void f_inorderprint (tree_t tree, FILE *fp);
void makeNullPostorder (tree_t tree);

#endif