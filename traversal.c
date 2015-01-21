struct Node *getnode(struct Node *root, struct Node *data,
                     int (*comparator)(void *, void *)) {

  int cmpval = comparator(root->data, newnode->data);

  if(cmpval == 0) {
    return root;
  }
      
  if(cmpval == -1) {
    return getnode(root->lchild, data, comparator);
  }

  if(cmpval == 1) {
    return getnode(root->rchild, data, comparator);
  }

}
