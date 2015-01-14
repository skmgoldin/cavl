CC = clang
objects = test.o avltree.o
program = treetest

$(program): $(objects)
	$(CC) -o $(program) $(objects)

test.o: test.c avltree.h
	$(CC) -c test.c

avltree.o: avltree.c avltree.h
	$(CC) -c avltree.c

PHONY: clean
clean:
	rm -f *.o

PHONY: all
all: clean
	make
