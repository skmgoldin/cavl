#ifndef AVLTREE_H
#define AVLTREE_H

struct Handle {
  struct Node *root;
  int *comparator (void *, void *); 
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};

struct Handle *gettree(int (*comparator)(void *, void *), void *data);

struct Node *addnode(struct Handle *handle, void *data);

int killtree(struct Handle *tree);

#endif /* AVLTREE_H */
