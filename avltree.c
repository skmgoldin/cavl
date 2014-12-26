#include "avltree.h"

struct Handle *gettree(void *data) {
  struct Handle handle = malloc(sizeof(struct Handle));
  return handle;
}

struct Node *addnode(void *data) {

}

/* This of course kills (deallocates) the tree for all handles. FYI. */
int killtree(struct Handle *tree) {
   
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
