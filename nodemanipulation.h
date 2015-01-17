#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *addnodemanager(struct Handle *handle, struct Node *newnode);

struct Node *placenode(struct Node *root, struct Carriage *carriage,
                       int (*comparator)(void *, void *));

struct Node *assignchild(struct Node **childpointer, struct Node *newnode,
                         int rootheight);

struct Node *singlerotation(struct Carriage *carriage);

struct Node *doublerotation(struct Carriage *carriage);

#endif /* NODEMANIPULATION_H */
