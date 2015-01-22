#include <stdlib.h>
#include "interface.h"
#include "resourcecontrol.h"
#include "balancecontrol.h"
#include "insertdelete.h"
#include "traversal.h"
#include <stdio.h>

/********************
 * Get a handle to an empty tree.
 * Allocates and returns a handle for the tree.
 * Arg 1: Declared struct Handle *
 * Arg 2: Comparator for the datetype to be used in the tree.
 * Arg 3: sizeof(<datatype>) for the datatype to be used in the tree.
 ********************/
struct Handle *gettree(struct Handle *handle,
                       int (*comparator)(void *, void *), size_t datasize) {
  handle = allochandle(handle);
  handle->comparator = comparator;
  handle->datasize = datasize;
  return handle;
}

/********************
 * Add a node to the tree. 
 * Allocates a node, assigns its data pointer to *data and inserts it into the
 * tree. Returns the tree handle.
 ********************/
struct Handle *addnode(struct Handle *handle, void *data) {
  struct Node *newnode = allocnode(newnode);
  newnode->data = data;

  //printf("%s%d\n", "Adding node ", *(int *) newnode->data);

  if(handle->root == NULL) {
    handle->root = newnode;
    handle->root = balance(handle->root);
    return handle;
  }

  handle->root = insert(handle->root, newnode, handle->comparator);

  return handle;
}

void *find(struct Handle *handle, void *data) {

  struct Node *result = getnode(handle->root, data, handle->comparator);

  return result->data;
}

/********************
 * Deallocate the tree and all of its nodes and data.
 ********************/
int killtree(struct Handle *handle) {
  if(handle->root != NULL) {
    deallocnode(handle->root); 
  }
  free(handle);
  return 1;
}

