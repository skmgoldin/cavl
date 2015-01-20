#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *balance(struct Node *node);

int balancefactor(struct Node *node);

int height(struct Node *node);

#endif /* NODEMANIPULATION_H */
