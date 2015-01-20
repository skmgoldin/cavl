#include "datastructures.h"

struct Node *insert(struct Node *root, struct Node *newnode,
                    int (*comparator)(void *, void *));
