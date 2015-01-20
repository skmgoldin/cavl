#include <stdlib.h>
#include "avltree.h"
#include "resourcecontrol.h"
#include "nodemanipulation.h"
#include <stdio.h>

/* FYI: This works because taking arguments into the program lets the OS manage
 * that memory automatically. I need to update the struct Handle with a field
 * the user can specify at construction which notes for the destructor whether
 * the tree's node->data pointers need to be deallocated or not.
 */

struct Handle gettree(struct Handle handle,
                      int (*comparator)(void *, void *), size_t datasize) {
  handle = allochandle(handle);
  handle.comparator = comparator;
  handle.datasize = datasize;
  return handle;
}

struct Node *addnode(struct Handle *handle, void *data) {
  struct Node *newnode = allocnode();
  newnode->data = data;

  if(handle->root == NULL) {
    handle->root = newnode;
    return newnode;
  }

  handle = addnodemanager(handle, newnode);

  return newnode;
}

/* This of course deallocates the tree for all handles. FYI. */
int killtree(struct Handle *handle) {
  if(handle->root != NULL) {
    deallocnode(handle->root); 
  }
  free(handle);
  return 1;
}

