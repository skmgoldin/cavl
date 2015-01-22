#ifndef INSERTDELETE_H
#define INSERTDELETE_H

#include "datastructures.h"

/********************
 * Insert a node.
 * Recursive insertion method adds *newnode to the subtree *root and returns
 * the tree's new root after rebalancing.
 ********************/
struct Node *insert(struct Node *root, struct Node *newnode,
                    int (*comparator)(void *, void *));


#endif /* INSERT-DELETE_H */
