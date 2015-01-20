#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *balance(struct Node *root);

int balancefactor(struct Node *root);

int height(struct Node *node);

#endif /* NODEMANIPULATION_H */
