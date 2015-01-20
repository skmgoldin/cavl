#include "balancecontrol.h"
#include <stdio.h>

struct Node *insert(struct Node *root, struct Node *newnode,
                    int (*comparator)(void *, void *)) {

  int cmpval = comparator(root->data, newnode->data);

  if(cmpval == 0 || cmpval == -1) {
    if(root->lchild == NULL) {
      root->lchild = newnode;
      return balance(root);
    } else if(root->lchild != NULL) {
      root->lchild = insert(root->lchild, newnode, comparator);
      return balance(root);
    }
  }

  if(cmpval == 1) {
    if(root->rchild == NULL) {
      root->rchild = newnode;
      return balance(root);
    } else if(root->rchild != NULL) {
      root->rchild = insert(root->rchild, newnode, comparator);
      return balance(root);
    }
  }

  fprintf(stderr, "%s\n", "Insertion failed.");
  exit(1);
}
