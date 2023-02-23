#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "traversal.h"

void inorderprint (tree_t tree) {
    if (tree!=NULL) {
        inorderprint (tree->left);
        printf("%s: %d\n",tree->element,tree->count);
        inorderprint (tree->right);
    }
}

void postorderprint (tree_t tree) {
    if (tree!=NULL) {
        postorderprint (tree->left);
        postorderprint (tree->right);
        printf("%s: %d\n",tree->element,tree->count);
    }
}

void preorderprint (tree_t tree) {
    if (tree!=NULL) {
        printf("%s: %d\n",tree->element,tree->count);
        preorderprint (tree->left);
        preorderprint (tree->right);
    }
}

void f_inorderprint (tree_t tree, FILE *fp) {
    if (tree!=NULL) {
        f_inorderprint(tree->left, fp);
        fprintf (fp,"%s %d\n",tree->element,tree->count);
        f_inorderprint(tree->right,fp);
    }
}

void makeNullPostorder(tree_t tree) {
    if (tree!=NULL) {
        makeNullPostorder(tree->left);
        makeNullPostorder(tree->right);
        free(tree);
    }
}