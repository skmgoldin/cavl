CC = clang
objects = test.o avltree.o resourcecontrol.o nodemanipulation.o rotations.o
program = treetest

$(program): $(objects)
	$(CC) -o $(program) $(objects) -lm

test.o: avltree.h
avltree.o: resourcecontrol.h 
resourcecontrol.o: avltree.h
nodemanipulation.o: rotations.h
rotations.o:

PHONY: clean
clean:
	rm -f *.o

PHONY: all
all: clean
	make
