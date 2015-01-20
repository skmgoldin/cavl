#include "rotations.h"
#include <stdio.h>

struct Node *llrotation(struct Node *root) {

  printf("%s\n", "ll rotation");

  struct Node *newroot = root->lchild;

  root->lchild = root->lchild->rchild;  
  newroot->rchild = root;

  return newroot;
}

struct Node *lrrotation(struct Node *root) {

  printf("%s\n", "lr rotation");

  struct Node *temp = root->lchild;

  root->lchild = root->lchild->rchild;
  root->lchild->lchild = temp;
  root->lchild->lchild->rchild = NULL;

  return llrotation(root);
}

struct Node *rrrotation(struct Node *root) {

  printf("%s\n", "rr rotation");

  struct Node *newroot = root->rchild;

  root->rchild = root->rchild->lchild;  
  newroot->lchild = root;

  return newroot;
}

struct Node *rlrotation(struct Node *root) {

  printf("%s\n", "rl rotation");

  struct Node *temp = root->rchild;

  root->rchild = root->rchild->lchild;
  root->rchild->rchild = temp;
  root->rchild->rchild->lchild = NULL;

  return rrrotation(root);
}
