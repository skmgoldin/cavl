#ifndef RESOURCECONTROL_H
#define RESOURCECONTROL_H

#include "datastructures.h"

struct Handle *allochandle(struct Handle *handle);

struct Carriage *alloccarriage();

struct Node *allocnode();

int deallocnode(struct Node *node);

#endif /* RESOURCECONTROL_H */

