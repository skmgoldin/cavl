#include "nodemanipulation.h"
#include "resourcecontrol.h"
#include <stdio.h> //only for test printers.

struct Node *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->newnode = newnode;
  carriage->anchorheight = handle->anchorheight;

  placenode(handle->root, carriage, handle->comparator);

  handle->anchorheight = carriage->anchorheight;

  free(carriage);
  return newnode;
}

struct Carriage *placenode(struct Node *root, struct Carriage *carriage, 
                       int (*comparator)(void *, void *)) {

  carriage = updatecarriage(carriage, root);

  int cmpval = (*comparator)(root->data, carriage->newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      assignchild(&root->lchild, carriage->newnode);
      return carriage;
    } else {
      if(carriage->currheight == carriage->anchorheight + 1) {
        ;//double rotation
      }
      carriage->currnodevia = 'l';
      return placenode(root->lchild, carriage, comparator);
    }
  }
  
  else if(cmpval > 0) {
    if(root->rchild == NULL) {
      assignchild(&root->rchild, carriage->newnode);
      return carriage;
    } else {
      if(carriage->currheight == carriage->anchorheight + 1) {
        return singlerotation(carriage);
      }
      carriage->currnodevia = 'r';
      return placenode(root->rchild, carriage, comparator);
    }
  }

  /* Control never reaches this point. */
  return NULL;
}

//struct Carriage *assignchild(struct Node **childpointer,
//                             struct Carriage *carriage) {
//
//    *childpointer = carriage->newnode;
//    return carriage;
//}

struct Node *assignchild(struct Node **childpointer,
                             struct Node *node) {

    *childpointer = node;
    return node;
}

struct Carriage *singlerotation(struct Carriage *carriage) {
  
  printf("%s\n", "single rotation.");

  assignchild(&carriage->currnode->rchild, carriage->newnode);
  assignchild(&carriage->currnode->lchild, carriage->parent);
  //carriage->currnode->rchild = carriage->newnode;
  //carriage->currnode->lchild = carriage->parent;

  if(carriage->parentvia == 'l') {
    assignchild(&carriage->grandparent->lchild, carriage->currnode);
   // carriage->grandparent->lchild = carriage->currnode;
  } else if(carriage->parentvia == 'r') {
    assignchild(&carriage->currnode->rchild, carriage->currnode);
    //carriage->grandparent->rchild = carriage->currnode;
  }

  carriage->anchorheight++;
  return carriage;
}

struct Carriage *doublerotation(struct Carriage *carriage) {
  carriage->anchorheight++;
  return carriage;
}

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode) {
 
  carriage->grandparent = carriage->parent;
  carriage->grandparentvia = carriage->parentvia;
  carriage->parent = carriage->currnode;
  carriage->parentvia = carriage->currnodevia;
  carriage->currnode = currnode;

  carriage->currheight++;
  
  return carriage;
}
