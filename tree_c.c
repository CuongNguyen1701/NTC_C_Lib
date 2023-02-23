#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree_c.h"
#define COUNT 10;
//change this based on the problem
//remember to change the elmType by changing data_t in data.h as well
int compareFunction(elmType a, elmType b)
{
  return strcmp(a, b); // can replace with other compare funtions
  // a < b, return < 0 number
  // a == b, return 0
  // a > b, return > 0 number
}
void makeNullTree(tree_t T) { T = NULL; }
int isEmptyTree(tree_t T) { return T == NULL; }

void freeTree(tree_t Tree)
{
  if (Tree == NULL)
    return;
  freeTree(LeftChild(Tree));
  freeTree(RightChild(Tree));
  free(Tree);
  return;
}

node_t *create_node(elmType NewData)
{
  node_t *N = (node_t *)malloc(sizeof(node_t));
  if (N != NULL)
  {
    N->left = NULL;
    N->right = NULL;
    N->element = NewData;
    N->count = 1;
  }
  return N;
}

void InsertNode(elmType x, tree_t *root)
{
  if (*root == NULL)
  { /* Create a new node for element x */
    // printf("insert %d\n", x);
    *root = create_node(x);
  }
  else if (compareFunction(x, (*root)->element) < 0)
    InsertNode(x, &((*root)->left));
  else if (compareFunction(x, (*root)->element) > 0)
    InsertNode(x, &((*root)->right));
}

void InsertandCount(elmType x, tree_t *root)
{
  if (*root == NULL)
  {
    *root = create_node(x);
  }
  else if (compareFunction(x, (*root)->element) < 0)
    InsertandCount(x, &((*root)->left));
  else if (compareFunction(x, (*root)->element) > 0)
    InsertandCount(x, &((*root)->right));
  else if (compareFunction(x, (*root)->element) == 0)
    ((*root)->count)++;
}

int countLeftChildren(tree_t Tree)
{
  if (isEmptyTree(Tree))
    return 0;
  int leftChildRight = countLeftChildren(RightChild(Tree));
  int leftChildLeft = isEmptyTree(LeftChild(Tree)) ? 0 : (1 + countLeftChildren(LeftChild(Tree)));
  // if(LeftChild(Tree) == NULL) return 0;
  return leftChildRight + leftChildLeft;
}

int countRightChildren(tree_t Tree)
{
  if (isEmptyTree(Tree))
    return 0;
  int rightChildRight = isEmptyTree(RightChild(Tree)) ? 0 : (1 + countRightChildren(RightChild(Tree)));
  int rightChildLeft = countRightChildren(LeftChild(Tree));
  // if(LeftChild(Tree) == NULL) return 0;
  return rightChildRight + rightChildLeft;
}

int countInternalNodes(tree_t Tree)
{
  if (Tree == NULL)
    return 0;
  int count = countNodes(Tree) - countLeaves(Tree) - 1;
  return ((count > 0) ? count : 0);
}

int countLeaves(tree_t Tree)
{
  if (Tree == NULL)
    return 0;
  if (IsLeaf(Tree))
    return 1;
  int leaves = countLeaves(LeftChild(Tree)) + countLeaves(RightChild(Tree));
  return leaves;
}

int treeHeight(tree_t Tree)
{
  if (Tree == NULL)
    return 0;
  int leftHeight = treeHeight(LeftChild(Tree));
  int rightHeight = treeHeight(RightChild(Tree));
  int childHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
  return (childHeight + 1);
}

tree_t LeftChild(tree_t n)
{
  if (n != NULL)
    return n->left;
  else
    return NULL;
}

tree_t RightChild(tree_t n)
{
  if (n != NULL)
    return n->right;
  else
    return NULL;
}

int IsLeaf(tree_t n)
{
  if (n != NULL)
    return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
  else
    return -1;
}

int countNodes(tree_t T)
{
  if (isEmptyTree(T))
    return 0;
  else
    return 1 + countNodes(LeftChild(T)) + countNodes(RightChild(T));
}

tree_t createfrom2(elmType v, tree_t l, tree_t r)
{
  node_t *N = (node_t *)malloc(sizeof(node_t));
  N->element = v;
  N->left = l;
  N->right = r;
  return N;
}

tree_t Add_Left(tree_t Tree, elmType NewData)
{
  node_t *NewNode = create_node(NewData);
  if (NewNode == NULL)
    return (NewNode);
  if (Tree == NULL)
    Tree = NewNode;
  else
  {
    node_t *Lnode = Tree;
    while (Lnode->left != NULL)
      Lnode = Lnode->left;
    Lnode->left = NewNode;
  }
  return (NewNode);
}

tree_t Add_Right(tree_t Tree, elmType NewData)
{
  node_t *NewNode = create_node(NewData);
  if (NewNode == NULL)
    return (NewNode);
  if (Tree == NULL)
    Tree = NewNode;
  else
  {
    node_t *Rnode = Tree;
    while (Rnode->right != NULL)
      Rnode = Rnode->right;
    Rnode->right = NewNode;
  }
  return (NewNode);
}

elmType deleteMin(tree_t *root)
{
  if ((*root)->left == NULL)
  {
    elmType k = (*root)->element;
    (*root) = (*root)->right;
    return k;
  }
  else
    return deleteMin(&(*root)->left);
}

void deleteNode(elmType x, tree_t *root)
{
  if (*root != NULL)
    if (strcmp(x, (*root)->element) < 0)
      deleteNode(x, &(*root)->left);
    else if (strcmp(x, (*root)->element) > 0)
      deleteNode(x, &(*root)->right);
    else if (((*root)->left == NULL) && ((*root)->right == NULL))
      *root = NULL;
    else if ((*root)->left == NULL)
      *root = (*root)->right;
    else if ((*root)->right == NULL)
      *root = (*root)->left;
    else
      (*root)->element = deleteMin(&(*root)->right);
}

// BST functions
tree_t search(elmType x, tree_t root)
{
  if (root == NULL)
    return NULL;                          // not found
  else if (strcmp(x, root->element) == 0) /* found x */
    return root;
  else if (strcmp(x, root->element) > 0)
    // continue searching in the right sub tree
    return search(x, root->right);
  else
  {
    // continue searching in the left sub tree
    return search(x, root->left);
  }
}

// Tree printing
Trunk *makeTrunk(Trunk *prev, char str[])
{
  Trunk *newTrunk = (Trunk *)malloc(sizeof(Trunk));
  if (newTrunk == NULL)
    return NULL;
  newTrunk->prev = prev;
  strcpy(newTrunk->str, str);
  return newTrunk;
}
void showTrunks(Trunk *p)
{
  if (p == NULL)
    return;
  showTrunks(p->prev);
  printf("%s", p->str);
}
void printTreeWrap(tree_t root) { printTree(root, NULL, NULL); }

void printTree(tree_t root, Trunk *prev, int isLeft)
{
  if (root == NULL)
    return;

  char prev_str[10] = "    ";
  char verticalSlash[20] = "    \263";
  //\304 horizontal slash
  //\332 single down and right
  //\300 single up and right
  Trunk *trunk = makeTrunk(prev, prev_str);

  printTree(root->right, trunk, 1);
  if (!prev)
  {
    strcpy(trunk->str, "\304\304\304");
  }
  else if (isLeft)
  {
    strcpy(trunk->str, "\332\304\304\304");
    strcpy(prev_str, verticalSlash);
  }
  else
  {
    strcpy(trunk->str, "\300\304\304\304");
    strcpy(prev->str, prev_str);
  }

  showTrunks(trunk);
  printf(" %s\n", root->element);

  if (prev)
  {
    strcpy(prev->str, prev_str);
  }
  strcpy(trunk->str, verticalSlash);

  printTree(root->left, trunk, 0);
}
