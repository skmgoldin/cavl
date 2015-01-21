#include "rotations.h"
#include <stdio.h>

/********************
 * Left-left rotation.
 * Returns the new root of its argument's subtree.
 ********************/
struct Node *llrotation(struct Node *root) {

  //printf("%s\n", "ll rotation");

  struct Node *newroot = root->lchild;

  root->lchild = root->lchild->rchild;  
  newroot->rchild = root;

  return newroot;
}

/********************
 * Left-right rotation.
 * No need to call left-left afterwards--this does it automatically and returns 
 * the new root of its argument's subtree.
 ********************/
struct Node *lrrotation(struct Node *root) {

  //printf("%s\n", "lr rotation");

  struct Node *temp = root->lchild;

  root->lchild = root->lchild->rchild;
  temp->rchild = root->lchild->lchild;
  root->lchild->lchild = temp;

  return llrotation(root);
}

/********************
 * Right-right rotation.
 * Returns the new root of its argument's subtree.
 ********************/
struct Node *rrrotation(struct Node *root) {

  //printf("%s\n", "rr rotation");

  struct Node *newroot = root->rchild;

  root->rchild = root->rchild->lchild;  
  newroot->lchild = root;

  return newroot;
}

/********************
 * Right-left rotation.
 * No need to call right-right afterwards--this does it automatically
 * and returns the new root of its argument's subtree.
 ********************/
struct Node *rlrotation(struct Node *root) {

  //printf("%s\n", "rl rotation");

  struct Node *temp = root->rchild;

  root->rchild = root->rchild->lchild;
  temp->lchild = root->rchild->rchild;
  root->rchild->rchild = temp;

  return rrrotation(root);
}
