CC = clang
objects = test.o avltree.o resourcecontrol.o
program = treetest

$(program): $(objects)
	$(CC) -o $(program) $(objects)

test.o: test.c avltree.h
	$(CC) -c test.c

avltree.o: avltree.c avltree.h
	$(CC) -c avltree.c

resourcecontrol.o: resourcecontrol.c resourcecontrol.h avltree.h
	$(CC) -c resourcecontrol.c

PHONY: clean
clean:
	rm -f *.o

PHONY: all
all: clean
	make
