#!/bin/sh

echo --------------------
echo Making 
echo --------------------

make all

echo --------------------
echo single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3

echo --------------------
echo double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2

echo --------------------
echo single rotation, double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3 5 4

echo --------------------
echo double rotation, single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2 4 5

echo --------------------
echo single rotation, single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3 4 5

echo --------------------
echo double rotation, double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2 5 4 



