#include "avltree.h"

struct Handle *gettree(void *data) {
  struct Handle *handle = malloc(sizeof(struct Handle));
  return handle;
}

struct Node *addnode(struct Handle *handle, void *data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  placenode(handle->root, node);
}

struct Node *placenode(struct Node *oldtimer, struct Node *newcomer) {
  int cmpval = *(handle->comparator)(oldtimer->data, newcomer->data);
  if(cmpval < 0 || cmpval == 0) {
    if(oldtimer->lchild == NULL) {
      oldtimer->lchild = newcomer;
    } else {
      placenode(oldtimer->lchild, newcomer);
    }
  } else if(cmpval > 0) {
    if(oldtimer->rchild == NULL) {
      oldtimer->rchild = newcomer;
    } else {
      placenode(oldtimer->rchild, newcomer);
    }
  }
}

/* This of course kills (deallocates) the tree for all handles. FYI. */
int killtree(struct Handle *tree) {
  deallocatenode(tree->root); 
  free(tree);
  return 1;
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
