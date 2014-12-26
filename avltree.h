struct Handle {
  struct Node *root;
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};

struct Handle *gettree(void *data);

struct Node *addnode(void *data);

int killtree(struct Handle *tree);
