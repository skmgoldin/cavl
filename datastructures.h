#ifndef DATASTRUCTURES_H
#define DATASTRUCTURES_H

#include <stdlib.h>

struct Handle {
  struct Node *root;
  int (*comparator)(void *, void *); 
  size_t datasize;
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};

#endif /* DATASTRUCTURES_H */
