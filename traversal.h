#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "datastructures.h"

struct Node *getnode(struct Node *root, void *data,
                     int (*comparator)(void *, void *));

#endif /* TRAVERSAL_H */
