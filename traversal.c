#include "traversal.h"
#include <stdio.h>

struct Node *getnode(struct Node *root, void *data,
                     int (*comparator)(void *, void *)) {

  int cmpval = comparator(root->data, data);

  if(cmpval == 0) {
    return root;
  }
      
  if(cmpval != 0 && root->lchild == NULL && root->rchild == NULL) {
    return NULL;
  }

  if(cmpval == -1) {
    return getnode(root->lchild, data, comparator);
  }

  if(cmpval == 1) {
    return getnode(root->rchild, data, comparator);
  }

  fprintf(stderr, "%s\n", "find() failed.");
  exit(1);
}
