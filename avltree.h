#ifndef AVLTREE_H
#define AVLTREE_H

#include "datastructures.h"

/* Public Functions */
struct Handle gettree(struct Handle handle,
                      int (*comparator)(void *, void *), size_t datasize);

struct Node *addnode(struct Handle *handle, void *data);

int killtree(struct Handle *handle);



#endif /* AVLTREE_H */
