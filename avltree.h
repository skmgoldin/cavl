struct Handle {
  struct Node *root;
};

struct Node {
  void *data;
  struct Node *lchild;
  struct Node *rchild;
};
