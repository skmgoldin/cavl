#ifndef ROTATIONS_H
#define ROTATIONS_H

#include "datastructures.h"

/********************
 * Left-left rotation.
 * Returns the new root of its argument's subtree.
 ********************/
struct Node *llrotation(struct Node *root);

/********************
 * Left-right rotation.
 * No need to call left-left afterwards--this does it automatically and returns 
 * the new root of its argument's subtree.
 ********************/
struct Node *lrrotation(struct Node *root);

/********************
 * Right-right rotation.
 * Returns the new root of its argument's subtree.
 ********************/
struct Node *rrrotation(struct Node *root);

/********************
 * Right-left rotation.
 * No need to call right-right afterwards--this does it automatically
 * and returns the new root of its argument's subtree.
 ********************/
struct Node *rlrotation(struct Node *root);

#endif /* ROTATIONS_H */
