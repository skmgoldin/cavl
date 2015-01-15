#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *placenode(struct Node *root, struct Node *newnode,
                       int (*comparator)(void *, void *));

struct Node *assignchild(struct Node **childpointer, struct Node *newnode,
                         int rootheight);

struct Node *singlerotation();

struct Node *doublerotation();


#endif /* NODEMANIPULATION_H */
