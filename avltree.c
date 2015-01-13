#include <stdlib.h>
#include "avltree.h"
#include <stdio.h>

/* 
 * Public Functions
 */

struct Handle *gettree(int (*comparator)(void *, void *), void *data) {
  struct Handle *handle = allochandle();
  handle->comparator = comparator;
  addnode(handle, data);
  return handle;
}

struct Node *addnode(struct Handle *handle, void *data) {
  struct Node *node = allocnode();
  node->data = data;

  if(handle->root == NULL) {
    printf("%s\n", "Making root.");
    handle->root = node;
    return handle->root;
  }

  return placenode(handle->root, node, handle->comparator);
}

/* This of course kills (deallocates) the tree for all handles. FYI. */
int killtree(struct Handle *tree) {
  deallocatenode(tree->root); 
  free(tree);
  return 1;
}

/*
 * Private Functions
 */

struct Handle *allochandle() {
  struct Handle *handle = malloc(sizeof(struct Handle));
  handle->comparator = NULL;
  handle->root = NULL;
  return handle;
}

struct Node *allocnode() {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = NULL;
  node->lchild = NULL;
  node->rchild = NULL;
  return node;
}

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {
  /* FAILURE IS AT COMPARATOR */
  printf("%s\n", "Getting cmpval...");
  int cmpval = (*comparator)(root->data, newnode->data);
  printf("%s\n", "compare successful");
  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      root->lchild = newnode;
      return newnode;
    } else {
      return placenode(root->lchild, newnode, comparator);
    }
  } else if(cmpval > 0) {
    if(root->rchild == NULL) {
      root->rchild = newnode;
      return newnode;
    } else {
      return placenode(root->rchild, newnode, comparator);
    }
  }

  return 0;
}

/* Recursive helper function for killtree */
int deallocatenode(struct Node *node) {

  /* Base case */
  if(node->lchild == NULL && node->rchild == NULL) {
    free(node->data);
    free(node);
    return 1;
  } 
 
  if(node->lchild != NULL) {
    deallocatenode(node->lchild);
  } if(node->rchild != NULL) { 
    deallocatenode(node->rchild);
  }

  return 1;
}


