#ifndef NODEMANIPULATION_H
#define NODEMANIPULATION_H

#include "datastructures.h"

struct Node *balance(struct Node *root);

double balancefactor(struct Node *root);

double height(struct Node *node);

#endif /* NODEMANIPULATION_H */
