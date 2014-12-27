This is an AVL tree in C. It's probably less efficient in space and time than a
standard library implementation.

The tree's handle (struct Handle) takes a function pointer to serve as its 
comparator. This comparator takes void pointers for genericity, so it's the
responsibility of the data type in question to provide a comparator which can
dereference those (sorry).
