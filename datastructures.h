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

struct Carriage {
  struct Node *newnode;
  struct Node *currnode;
  char currnodevia;
  struct Node *parent;
  char parentvia;
  struct Node *grandparent;
  char grandparentvia;
  struct Node *greatgrandparent;
  char greatgrandparentvia;
  int anchorheight;
  int currheight;
  int rotationstatus;
  int cmpval;
};

#endif /* DATASTRUCTURES_H */
