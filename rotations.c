#include "rotations.h"

struct Node *llrotation(struct Node *root) {

  struct Node *newroot = root->lchild;

  root->lchild->rchild = root;  
  root->lchild = NULL;

  return newroot;
}

struct Node *lrrotation(struct Node *root) {

  root->lchild->rchild->lchild = root->lchild;  
  root->lchild = root->lchild->rchild;
  root->lchild->lchild->rchild = NULL;

  return llrotation(root);
}

struct Node *rrrotation(struct Node *root) {

  struct Node *newroot = root->rchild;

  root->rchild->lchild = root;  
  root->rchild = NULL;

  return newroot;
}

struct Node *rlrotation(struct Node *root) {

  root->rchild->lchild->rchild = root->rchild;  
  root->rchild = root->rchild->lchild;
  root->rchild->rchild->lchild = NULL;

  return rrrotation(root);
}
