This is an AVL tree in C. It is generic and very efficient in space and time.

The tree's handle (struct Handle) takes a function pointer to serve as its 
comparator. This comparator takes void pointers for genericity, so it's the
responsibility of the data type in question to provide a comparator which can
dereference those (sorry).
