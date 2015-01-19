#include "nodemanipulation.h"
#include "resourcecontrol.h"
#include <stdio.h> //only for test printers.

struct Handle *addnodemanager(struct Handle *handle, struct Node *newnode) {
  struct Carriage *carriage = alloccarriage();
  carriage->newnode = newnode;
  carriage->anchorheight = handle->anchorheight;

  placenode(handle->root, carriage, handle->comparator);

  if(carriage->rotationstatus == 1) {
    printf("%s\n", "Reassigning handle");
    handle->root = carriage->currnode;
  }

  handle->anchorheight = carriage->anchorheight;
  printf("%s%p\n", "Handle trace: ", handle);

  free(carriage);
  return handle;
}

struct Carriage *placenode(struct Node *root, struct Carriage *carriage, 
                       int (*comparator)(void *, void *)) {

  carriage = updatecarriage(carriage, root);

  int cmpval = (*comparator)(root->data, carriage->newnode->data);

  if(cmpval < 0 || cmpval == 0) {
    if(root->lchild == NULL) {
      root->lchild = carriage->newnode;
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
      printf("%s%p\n", "Child pointer trace: ", root->rchild);
      root->rchild = carriage->newnode;
      printf("%s%p\n", "Child pointer trace: ", root->rchild);
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

struct Carriage *singlerotation(struct Carriage *carriage) {
  
  printf("%s\n", "single rotation.");
  carriage = updatecarriage(carriage, carriage->currnode); // WRONG, need to feed it a better input

  carriage->currnode->rchild = carriage->newnode;
  carriage->currnode->lchild = carriage->parent;

  if(carriage->parentvia == 'l') {
    carriage->grandparent->lchild = carriage->currnode;
  } else if(carriage->parentvia == 'r') {
    carriage->grandparent->rchild = carriage->currnode;
  }

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
 
  carriage->grandparent = carriage->parent;
  carriage->grandparentvia = carriage->parentvia;
  carriage->parent = carriage->currnode;
  carriage->parentvia = carriage->currnodevia;
  carriage->currnode = currnode;

  carriage->currheight++;
  
  return carriage;
}
