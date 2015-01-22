#include "resourcecontrol.h"
#include <stdio.h> //for test printing

struct Handle *allochandle(struct Handle *handle) {
  handle = malloc(sizeof(struct Handle));

  handle->root = NULL;

  handle->comparator = NULL;
  handle->datasize = 0;

  return handle;
}

struct Node *allocnode(struct Node *node) {
  node = malloc(sizeof(struct Node));

  node->data = NULL;

  node->height = -1;

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
    //printf("%s\n", (char *) node->data); 
    free(node->data); 
    free(node);
    return 1;
  }

  return 1;
}



