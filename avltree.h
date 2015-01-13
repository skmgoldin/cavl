#ifndef AVLTREE_H
#define AVLTREE_H

#include "avltree.h"

/* Data Structures */
struct Handle {
  struct Node *root;
  int (*comparator)(void *, void *); 
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};

/* Public Functions */
struct Handle *gettree(int (*comparator)(void *, void *), void *data);

struct Node *addnode(struct Handle *handle, void *data);

int killtree(struct Handle *tree);

/* Private Functions */
struct Node *placenode(struct Node *root, struct Node *newnode,
                       int (*comparator)(void *, void *));

struct Handle *allochandle();

struct Node *allocnode();

#endif /* AVLTREE_H */
