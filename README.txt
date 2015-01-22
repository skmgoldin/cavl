cavl is an AVL tree in C. It is generic and maximally efficient in space--less 
so in time. In a memory-constrained context with lots of compute horsepower, 
this is an excellent data structure.

--Genericity--
The tree's handle (struct Handle) takes a function pointer to serve as its 
comparator. This comparator takes void pointers for genericity, so it's the
responsibility of the data type in question to provide a comparator which can
dereference those.

--Space Efficiency--
The tree's nodes store only three pointers: data, lchild and rchild.

--Time Efficiency--
Without storing a height value in the nodes, the balance functions have to 
recurse through the entire tree after every insertion and deletion. Other 
queries remain log-n efficient, however.

To-Do:
- Deletions
- CPU-efficient version
- Library output
- Better tests
- More traversals
- Improved searching?
