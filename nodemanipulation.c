#include "nodemanipulation.h"
#include "resourcecontrol.h"
#include "rotations.h"
#include <math.h>
#include <stdio.h> //test printing only

struct Node *balance(struct Node *node) {

  int bf = balancefactor(node);

  /* Tree is balanced. */
  if(bf == 0 || bf == 1 || bf == -1) {
    return node;
  }

  /* Tree is left-heavy. */
  else if(bf == 2) {
    int lbf = balancefactor(node->lchild);
    if(lbf == 1) {return llrotation(node);}
    else if(lbf == -1) {return lrrotation(node);}
  }

  /* Tree is right-heavy. */
  else if(bf == -2) {
    int lbf = balancefactor(node->lchild);
    if(lbf == 1) {return rlrotation(node);}
    else if(lbf == -1) {return rrrotation(node);}
  }

  fprintf(stderr, "%s\n", "Tree is impossibly imbalanced.");
  exit(1);
  return node;
}

int balancefactor(struct Node *node) {

  return height(node->lchild) - height(node->rchild);
}

int height(struct Node *node) {

  if(node == NULL) {
    return 0;
  }

  return fmax(height(node->lchild), height(node->rchild)) + 1;
}


