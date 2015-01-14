#include <stdlib.h>
#include "avltree.h"
#include "resourcecontrol.h"
#include <stdio.h>

/* FYI: This works because taking arguments into the program lets the OS manage
 * that memory automatically. I need to update the struct Handle with a field
 * the user can specify at construction which notes for the destructor whether
 * the tree's node->data pointers need to be deallocated or not.
 */

/* 
 * Public Functions
 */

struct Handle *gettree(int (*comparator)(void *, void *), size_t datasize) {
  struct Handle *handle = allochandle();
  handle->comparator = comparator;
  handle->datasize = datasize;
  return handle;
}

struct Node *addleaf(struct Handle *handle, void *data) {
  struct Node *node = allocnode();
  node->data = data;

  if(handle->root == NULL) {
    handle->root = node;
    return handle->root;
  }

  return placenode(handle->root, node, handle->comparator);
}

/* This of course deallocates the tree for all handles. FYI. */
int killtree(struct Handle *handle) {
  if(handle->root != NULL) {
    deallocnode(handle->root); 
  }
  free(handle);
  return 1;
}

/*
 * Private Functions
 */

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {
  int cmpval = (*comparator)(root->data, newnode->data);
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




