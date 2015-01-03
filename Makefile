objects = test.o avltree.o
program = treetest

$(program): $(objects)
	clang -o $(program) $(objects)

test.o: test.c avltree.h
	clang -c test.c

avltree.o: avltree.c avltree.h
	clang -c avltree.c


