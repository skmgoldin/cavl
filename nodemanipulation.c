#include "nodemanipulation.h"
#include "resourcecontrol.h"
#include <stdio.h> //only for test printers.

struct Handle *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->newnode = newnode;
  carriage->anchorheight = handle->anchorheight;

  carriage = placenode(handle->root, carriage, handle->comparator);

  if(carriage->rotationstatus == 1 && carriage->currheight == 2) {
    printf("%s\n", "Reassigning handle");
    handle->root = carriage->currnode;
  }

  handle->anchorheight = carriage->anchorheight;

  free(carriage);
  return handle;
}

struct Carriage *placenode(struct Node *root, struct Carriage *carriage, 
                       int (*comparator)(void *, void *)) {

  carriage = updatecarriage(carriage, root);

  int cmpval = (*comparator)(root->data, carriage->newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(carriage->currheight == carriage->anchorheight + 1) {
      return carriage; // = doublerotation(carriage);
    } else {
      if(root->lchild == NULL) {
        carriage->currnode->lchild = carriage->newnode;
        return carriage;
      } 
      carriage->currnodevia = 'l';
      return carriage = placenode(root->lchild, carriage, comparator);
    }
  }

  else if(cmpval > 0) {
    if(carriage->currheight == carriage->anchorheight + 1) {
      return carriage = singlerotation(carriage);
    } else {
      if(root->rchild == NULL) {
        carriage->currnode->rchild = carriage->newnode;
        return carriage;
      } 
      carriage->currnodevia = 'r';
      return carriage = placenode(root->rchild, carriage, comparator);
    }
  }

  /* Control never reaches this point. */
  return NULL;
}

struct Carriage *singlerotation(struct Carriage *carriage) {
  
  printf("%s\n", "single rotation.");
//  carriage = updatecarriage(carriage, carriage->currnode); // WRONG, need to feed it a better input (??)

  carriage->currnode->rchild = carriage->newnode;
  carriage->currnode->lchild = carriage->parent;

  carriage->parent->rchild = NULL;

  printf("%s\n", "hi.");
  if(carriage->currheight > 2) {
    if(carriage->parentvia == 'l') {
      carriage->grandparent->lchild = carriage->currnode;
    } else if(carriage->parentvia == 'r') {
      carriage->grandparent->rchild = carriage->currnode;
    }
  }

  printf("%s\n", "hey.");
  carriage->anchorheight++;
  carriage->rotationstatus = 1;
  return carriage;
}

struct Carriage *doublerotation(struct Carriage *carriage) {
  carriage->anchorheight++;
  return carriage;
}

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode) {
  printf("%s\n", "update carriage");
 
  carriage->grandparent = carriage->parent;
  carriage->parent = carriage->currnode;
  carriage->currnode = currnode;

  carriage->grandparentvia = carriage->parentvia;
  carriage->parentvia = carriage->currnodevia;

  carriage->currheight++;
  
  return carriage;
}
