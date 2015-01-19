#!/bin/sh

echo --------------------
echo Making 
echo --------------------

make all

echo --------------------
echo RS single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3

echo --------------------
echo LS single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 3 2 1 

echo --------------------
echo RS double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2

echo --------------------
echo LS double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 5 3 4

echo --------------------
echo RS single rotation, RS double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3 5 4

echo --------------------
echo RS double rotation, RS single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2 4 5

echo --------------------
echo RS single rotation, RS single rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 2 3 4 5

echo --------------------
echo RS double rotation, RS double rotation
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2 5 4 

echo --------------------
echo Random String
echo --------------------

valgrind --leak-check=yes ./treetest 1 3 2 5 4 8 3 19 4 1 4 19 41 91 4 1 4 23 2 1 3 13 4 1 4 18 8 8 8 32 1 3 1 9 3 2 9 18 4 1 9 1 3 41 3 1 2 3 2 3 4 5 6 7 2 3 84 48 27 2 1 3 48 59 3 1 94 1 10 49 58 3 3 1 1 34 5 58 3 23 4 2 42 21 31 31 4 21 1 2 3 2 1 2 2 1 2 2 22 2 3 4 24 34 95 54 2 84 96 82 42 3 4 


