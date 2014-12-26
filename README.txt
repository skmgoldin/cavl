This is a hotrod AVL tree. Zero guarantee that it is any more efficient in
space or time than any standard library implementation. It's probably a lot
worse. Hotrod here just means custom.

The tree's handle (struct Handle) takes a function pointer to serve as its 
comparator. This comparator takes void pointers for genericity, so it's the
responsibility of the data type in question to provide a comparator which can
dereference those (sorry).
