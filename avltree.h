struct Handle {
  struct Node *root;
  int *comparator (void *, void *); 
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};

struct Handle *gettree(void *data);

struct Node *addnode(struct Handle *handle, void *data);

int killtree(struct Handle *tree);
