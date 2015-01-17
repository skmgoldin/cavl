#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *addnodemanager(struct Handle *handle, struct Node *newnode);

struct Carriage *placenode(struct Node *root, struct Carriage *carriage,
                       int (*comparator)(void *, void *));

//struct Carriage *assignchild(struct Node **childpointer,
//                             struct Carriage *carriage);

struct Node *assignchild(struct Node **childpointer,
                             struct Node *node);

struct Carriage *singlerotation(struct Carriage *carriage);

struct Carriage *doublerotation(struct Carriage *carriage);

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode);

#endif /* NODEMANIPULATION_H */
