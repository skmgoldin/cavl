#ifndef AVLTREE_H
#define AVLTREE_H

#include "datastructures.h"

/* Public Functions */
struct Handle *gettree(int (*comparator)(void *, void *), size_t datasize);

struct Node *addleaf(struct Handle *handle, void *data);

int killtree(struct Handle *handle);

/* Private Functions */
struct Node *placenode(struct Node *root, struct Node *newnode,
                       int (*comparator)(void *, void *));


#endif /* AVLTREE_H */
