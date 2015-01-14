#ifndef RESOURCECONTROL_H
#define RESOURCECONTROL_H

#include "datastructures.h"

struct Handle *allochandle();

struct Node *allocnode();

int deallocnode(struct Node *node);

#endif /* RESOURCECONTROL_H */

