#include "balancecontrol.h"
#include "resourcecontrol.h"
#include "rotations.h"
#include <math.h>
#include <stdio.h> //test printing only

struct Node *balance(struct Node *root) {

  int bf = balancefactor(root);

  /* Tree is balanced. */
  if(bf == 0 || bf == 1 || bf == -1) {
    return root;
  }

  /* Tree is left-heavy. */
  else if(bf == 2) {
    int lbf = balancefactor(root->lchild);
    if(lbf == 1) {return llrotation(root);}
    else if(lbf == -1) {return lrrotation(root);}
  }

  /* Tree is right-heavy. */
  else if(bf == -2) {
    int rbf = balancefactor(root->rchild);
    if(rbf == 1) {return rlrotation(root);}
    else if(rbf == -1) {return rrrotation(root);}
  }

  fprintf(stderr, "%s\n", "Tree is impossibly imbalanced.");
  exit(1);
}

int balancefactor(struct Node *root) {

  if(root == NULL) {return 0;}

  return height(root->lchild) - height(root->rchild);
}

int height(struct Node *node) {

  if(node == NULL) {
    return 0;
  }

  return fmax(height(node->lchild), height(node->rchild)) + 1;
}


