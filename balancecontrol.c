#include "balancecontrol.h"
#include "resourcecontrol.h"
#include "rotations.h"
#include <math.h>
#include <stdio.h> //test printing only

struct Node *balance(struct Node *root) {

  double bf = balancefactor(root);
  printf("%s%s%s%0.f\n", "Balance Factor of node ", root->data, " is ", bf);

  /* Tree is balanced. */
  if(bf == 0 || bf == 1 || bf == -1) {
    return root;
  }

  /* Tree is left-heavy. */
  else if(bf == 2) {
    double lbf = balancefactor(root->lchild);
    if(lbf == 1) {return llrotation(root);}
    else if(lbf == -1) {return lrrotation(root);}
  }

  /* Tree is right-heavy. */
  else if(bf == -2) {
    double rbf = balancefactor(root->rchild);
    if(rbf == 1) {return rlrotation(root);}
    else if(rbf == -1) {return rrrotation(root);}
  }

  fprintf(stderr, "%s\n", "Tree is impossibly imbalanced.");
  exit(1);
}

double balancefactor(struct Node *root) {

  if(root == NULL) {return 0;}

  return height(root->lchild) - height(root->rchild);
}

double height(struct Node *node) {


  if(node == NULL) {
    return -1;
  }

  printf("%s%s%s%0.f\n", "Height of node ", node->data, " is ", fmax(height(node->lchild), height(node->rchild)) + 1);

  return fmax(height(node->lchild), height(node->rchild)) + 1;
}


