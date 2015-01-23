cavl is a generic and time-efficient AVL tree in C. It supports a maximally space efficient mode called lightcavl appropriate in memory-constrained contexts with lots of compute horsepower.

--Genericity--
The tree's handle (struct Handle) takes a function pointer to serve as its comparator. This comparator takes void pointers for genericity, so it's the responsibility of the data type in question to provide a comparator which can dereference those.

--Space Efficiency--
Standard cavl nodes contain three pointers--data, lchild, rchild--and an integer variable for height. lightcavl loses the height variable; the resulting space savings are system-dependent, but should be in the neighborhood of 16%-25%. 

--Time Efficiency--
Non-insertion/deletion queries on both standard and lightcavl are log-n efficient. Insertion and deletion operations in standard cavl are also log-n efficient. In lightcavl, insertions and deletions are log-n * log-n efficient.

To-Do:
- Deletions
- Library output
- Better tests
- More traversals
- Improved searching
