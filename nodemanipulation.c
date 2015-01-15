#include "nodemanipulation.h"

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {

  int cmpval = (*comparator)(root->data, newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      return assignchild(root->lchild, newnode, root->height);
    } else {
      return placenode(root->lchild, newnode, comparator);
    }
  }
  
  else if(cmpval > 0) {
    if(root->rchild == NULL) {
      return assignchild(root->rchild, newnode, root->height);
    } else {
      return placenode(root->rchild, newnode, comparator);
    }
  }

  /* Control never reaches this point. */
  return NULL;
}

struct Node *assignchild(struct Node *childpointer, struct Node *newnode,
                         int rootheight) {
    childpointer = newnode;
    newnode->height = rootheight + 1;

    return newnode;
}

struct Node *singlerotation() {
  return NULL;
}
