#include "insertdelete.h"
#include "balancecontrol.h"
#include <math.h>
#include <stdio.h>

/********************
 * Insert a node.
 * Recursive insertion method adds *newnode to the subtree *root and returns
 * the tree's new root after rebalancing.
 ********************/
struct Node *insert(struct Node *root, struct Node *newnode,
                    int (*comparator)(void *, void *)) {

  int cmpval = comparator(root->data, newnode->data);

  if(cmpval == 0 || cmpval == -1) {
    if(root->lchild == NULL) {
      newnode->height++;
      root->lchild = newnode;
      return root;
    } else if(root->lchild != NULL) {
      root->lchild = insert(root->lchild, newnode, comparator);
      root->height = fmax(height(root->lchild), height(root->rchild)); 
      return balance(root);
    }
  }

  if(cmpval == 1) {
    if(root->rchild == NULL) {
      newnode->height++;
      root->rchild = newnode;
      return root;
    } else if(root->rchild != NULL) {
      root->rchild = insert(root->rchild, newnode, comparator);
      root->height = fmax(height(root->lchild), height(root->rchild)); 
      return balance(root);
    }
  }

  fprintf(stderr, "%s\n", "Insertion failed.");
  exit(1);
}
