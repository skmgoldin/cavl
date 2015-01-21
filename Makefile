CC = clang
objects = test.o interface.o resourcecontrol.o balancecontrol.o rotations.o insert-delete.o
program = treetest

$(program): $(objects)
	$(CC) -o $(program) $(objects) -lm

test.o: interface.h
avltree.o: resourcecontrol.h 
resourcecontrol.o: interface.h
balancecontrol.o: rotations.h
rotations.o:
insert-delete.o:

PHONY: clean
clean:
	rm -f *.o

PHONY: all
all: clean
	make
