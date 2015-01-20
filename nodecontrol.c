#include "balancecontrol.h"
#include <stdio.h>

struct Node *insert(struct Node *root, struct Node *newnode,
                    int (*comparator)(void *, void *)) {

  int cmpval = comparator(root, newnode);

  if(cmpval == 0 || cmpval == -1) {
    if(root->lchild == NULL) {
      root->lchild = newnode;
      return balance(root);
    } else if(root->lchild != NULL) {
      insert(root->lchild, newnode, comparator);
      return balance(root);
    }
  }

  if(cmpval == 1) {
    if(root->rchild == NULL) {
      root->rchild = newnode;
      return balance(root);
    } else if(root->rchild != NULL) {
      insert(root->rchild, newnode, comparator);
      return balance(root);
    }
  }

  fprintf(stderr, "%s\n", "Insertion failed.");
  exit(1);
}
