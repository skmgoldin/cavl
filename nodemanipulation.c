#include "nodemanipulation.h"
#include "resourcecontrol.h"

struct Node *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->newnode = newnode;
  carriage->anchorheight = handle->anchorheight;

  placenode(handle->root, carriage, handle->comparator);

  handle->anchorheight = carriage->anchorheight;

  free(carriage);
  return newnode;
}

struct Node *placenode(struct Node *root, struct Carriage *carriage, 
                       int (*comparator)(void *, void *)) {

  carriage = updatecarriage(carriage, root);

  int cmpval = (*comparator)(root->data, carriage->newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      return assignchild(&root->lchild, carriage->newnode, root->height);
    } else {
      if(carriage->currheight == carriage->anchorheight + 1) {
        ;//double rotation
      }
      return placenode(root->lchild, carriage, comparator);
    }
  }
  
  else if(cmpval > 0) {
    if(root->rchild == NULL) {
      return assignchild(&root->rchild, carriage->newnode, root->height);
    } else {
      if(carriage->currheight == carriage->anchorheight + 1) {
        ;//single rotation
      }
      return placenode(root->rchild, carriage, comparator);
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

struct Node *singlerotation(struct Carriage *carriage) {
  carriage->anchorheight++;
  return NULL;
}

struct Node *doublerotation(struct Carriage *carriage) {
  carriage->anchorheight++;
  return NULL;
}

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode) {
 
  carriage->grandparent = carriage->parent;
  carriage->parent = carriage->currnode;
  carriage->currnode = currnode;

  carriage->currheight++;
  
  return carriage;
}
