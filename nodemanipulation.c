#include "nodemanipulation.h"
#include "resourcecontrol.h"
#include <stdio.h> //test printing only

struct Handle *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->newnode = newnode;
  carriage->anchorheight = handle->anchorheight;

  carriage = placenode(handle->root, carriage, handle->comparator);

  if(carriage->rotationstatus == 1 && carriage->currheight == 2) {
    handle->root = carriage->currnode;
  } else if(carriage->rotationstatus == 2 && carriage->currheight == 2) {
    handle->root = carriage->newnode;
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
      if(carriage->currnodevia == 'r') {
        return carriage = doublerotation(carriage);
      } else if(carriage->currnodevia == 'l') {
        return carriage = singlerotation(carriage);
      }
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
      if(carriage->currnodevia == 'r') {
        return carriage = singlerotation(carriage);
      } else if(carriage->currnodevia == 'l') {
        return carriage = doublerotation(carriage);
      }
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
  
  printf("%s%c%s\n", "Single rotation from ", carriage->currnodevia, " side.");

  if(carriage->currnodevia == 'r') {
    carriage->currnode->rchild = carriage->newnode;
    carriage->currnode->lchild = carriage->parent;
    carriage->parent->rchild = NULL;
  } else if(carriage->currnodevia == 'l') {
    carriage->currnode->rchild = carriage->parent;
    carriage->currnode->lchild = carriage->newnode;
    carriage->parent->lchild = NULL;
  }

  if(carriage->currheight > 2) {
    if(carriage->parentvia == 'l') {
      carriage->grandparent->lchild = carriage->currnode;
    } else if(carriage->parentvia == 'r') {
      carriage->grandparent->rchild = carriage->currnode;
    }
  }

  carriage->anchorheight++;
  carriage->rotationstatus = 1;
  return carriage;
}

struct Carriage *doublerotation(struct Carriage *carriage) {

  printf("%s%c%s\n", "Double rotation from ", carriage->currnodevia, " side.");
  
  if(carriage->currnodevia == 'r') {
    carriage->newnode->rchild = carriage->currnode;
    carriage->newnode->lchild = carriage->parent;
    carriage->parent->rchild = NULL;
  } else if(carriage->currnodevia == 'l') {
    carriage->newnode->rchild = carriage->parent;
    carriage->newnode->lchild = carriage->currnode;
    carriage->parent->lchild = NULL;
  }

  if(carriage->currheight > 2) {
    if(carriage->parentvia == 'l') {
      carriage->grandparent->lchild = carriage->newnode;
    } else if(carriage->parentvia == 'r') {
      carriage->grandparent->rchild = carriage->newnode;
    }
  }

  carriage->anchorheight++;
  carriage->rotationstatus = 2;
  return carriage;
}

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode) {
 
  carriage->grandparent = carriage->parent;
  carriage->parent = carriage->currnode;
  carriage->currnode = currnode;

  carriage->grandparentvia = carriage->parentvia;
  carriage->parentvia = carriage->currnodevia;

  carriage->currheight++;
  
  return carriage;
}
