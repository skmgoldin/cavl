#ifndef AVLTREE_H
#define AVLTREE_H

#include "datastructures.h"

/********************
 * Get a handle to an empty tree.
 * Allocates and returns a handle for the tree.
 * Arg 1: Declared struct Handle *
 * Arg 2: Comparator for the datetype to be used in the tree.
 * Arg 3: sizeof(<datatype) for datatype to be used in the tree.
 ********************/
struct Handle *gettree(struct Handle *handle,
                       int (*comparator)(void *, void *), size_t datasize);

/********************
 * Add a node to the tree. 
 * Allocates a node, assigns its data pointer to *data and inserts it into the
 * tree. Returns the tree handle.
 ********************/
struct Handle *addnode(struct Handle *handle, void *data);

void *find(struct Handle *handle, void *data) {

/********************
 * Deallocate the tree and all of its nodes and data.
 ********************/
int killtree(struct Handle *handle);



#endif /* AVLTREE_H */
