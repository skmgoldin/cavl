#include <stdlib.h>
#include "avltree.h"

struct Handle *gettree(int (*comparator)(void *, void *), void *data) {
  struct Handle *handle = malloc(sizeof(struct Handle));
  handle->comparator = comparator;
  handle->root->data = data;
  return handle;
}

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {
  int cmpval = comparator(root->data, newnode->data);
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

struct Node *addnode(struct Handle *handle, void *data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  return placenode(handle->root, node, handle->comparator);
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

/* This of course kills (deallocates) the tree for all handles. FYI. */
int killtree(struct Handle *tree) {
  deallocatenode(tree->root); 
  free(tree);
  return 1;
}


