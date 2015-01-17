#include "resourcecontrol.h"

struct Handle *allochandle() {
  struct Handle *handle = malloc(sizeof(struct Handle));
  handle->comparator = NULL;
  handle->root = NULL;
  handle->datasize = 0;
  handle->anchorheight = 0;
  return handle;
}

struct Carriage *alloccarriage() {
  struct Carriage *carriage = malloc(sizeof(struct Carriage));
  carriage->newnode = NULL;
  carriage->currnode = NULL;
  carriage->currnodevia = 'x';
  carriage->parent = NULL;
  carriage->parentvia = 'x';
  carriage->grandparent = NULL;
  carriage->grandparentvia = 'x';
  carriage->anchorheight = 0;
  carriage->currheight = 0;

  return carriage;
}

struct Node *allocnode() {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = NULL;
  node->lchild = NULL;
  node->rchild = NULL;
  return node;
}

int deallocnode(struct Node *node) {
   
  if(node->lchild != NULL) {
    deallocnode(node->lchild);
    node->lchild = NULL;
  } if(node->rchild != NULL) { 
    deallocnode(node->rchild);
    node->rchild = NULL;
  }
  
  /* Base case */
  if(node->lchild == NULL && node->rchild == NULL) {
    free(node);
    return 1;
  }

  return 1;
}



