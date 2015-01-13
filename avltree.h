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
struct Handle *gettree(int (*comparator)(void *, void *));

struct Node *addleaf(struct Handle *handle, void *data);

int killtree(struct Handle *tree);

/* Private Functions */
struct Node *placenode(struct Node *root, struct Node *newnode,
                       int (*comparator)(void *, void *));

struct Handle *allochandle();

struct Node *allocnode();

int deallocnode(struct Node *node);

#endif /* AVLTREE_H */
