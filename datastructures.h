#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdlib.h>

struct Handle {
  struct Node *root;
  int (*comparator)(void *, void *); 
  size_t datasize;
  /* Rotate any node that comes back 2 greater than anchor height, update anchor
   * height after the rotation.
   */
  int anchorheight;
};

struct Node {
  void *data;
  int height;
  int needsrotations;
  struct Node *lchild;
  struct Node *rchild;
};

#endif /* DATASTRUCTURES_H */
