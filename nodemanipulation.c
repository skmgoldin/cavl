#include "nodemanipulation.h"

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {

  int cmpval = (*comparator)(root->data, newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      root->lchild = newnode;
      newnode->height = root->height + 1;
      return newnode;
    } else {
      return placenode(root->lchild, newnode, comparator);
    }
  }
  
  else if(cmpval > 0) {
    if(root->rchild == NULL) {
      root->rchild = newnode;
      return newnode;
    } else {
      return placenode(root->rchild, newnode, comparator);
    }
  }

  /* Control never reaches this point. */
  return NULL;
}
