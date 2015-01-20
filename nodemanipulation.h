#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Handle *addnodemanager(struct Handle *handle, struct Node *newnode);

struct Carriage *placenode(struct Node *root, struct Carriage *carriage,
                       int (*comparator)(void *, void *));

int rotationnecessary(struct Carriage *carriage, struct Node *childptr);

struct Carriage *rotationhandler(struct Carriage *carriage);

struct Carriage *singlerotation(struct Carriage *carriage);

struct Carriage *doublerotation(struct Carriage *carriage);

struct Carriage *updatecarriage(struct Carriage *carriage,
                                struct Node *currnode);

#endif /* NODEMANIPULATION_H */
