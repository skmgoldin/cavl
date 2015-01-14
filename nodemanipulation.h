#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *placenode(struct Node *root, struct Node *newnode,
                       int (*comparator)(void *, void *));

#endif /* NODEMANIPULATION_H */
