#include "nodemanipulation.h"

// Need a "Rotation Master" function above the node placement function with
// access to the handle's rootanchor to determine both whether a rotation is
// necessary and what type. We probably also need to return cmpval from
// placenode() so we know whether it should be inner or outer.

struct Node *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->node = newnode;
  carriage->anchorheight = handle->anchorheight;

  placenode(handle->root, node, handle->comparator);

  if(newnode->height > handle->anchorheight + 1) {
    ;//rotate and update anchorheight
  }

  free(carriage);
  return newnode;
}

struct Node *placenode(struct Node *root, struct Node *newnode, 
                       int (*comparator)(void *, void *)) {

  int cmpval = (*comparator)(root->data, newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      return assignchild(&root->lchild, newnode, root->height);
    } else {
      return placenode(root->lchild, newnode, comparator);
    }
  }
  
  else if(cmpval > 0) {
    if(root->rchild == NULL) {
      return assignchild(&root->rchild, newnode, root->height);
    } else {
      return placenode(root->rchild, newnode, comparator);
    }
  }

  /* Control never reaches this point. */
  return NULL;
}

struct Node *assignchild(struct Node **childpointer, struct Node *newnode,
                         int rootheight) {

    *childpointer = newnode;
    newnode->height = rootheight + 1;
    return newnode;
}

struct Node *singlerotation() {
  return NULL;
}
