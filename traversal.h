#include "datastructures.h"

struct Node *getnode(struct Node *root, void *data,
                     int (*comparator)(void *, void *));

