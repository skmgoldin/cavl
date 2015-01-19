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

valgrind --leak-check=yes ./treetest 1 3 2 5 4 8 3 19 4 1 4 19 4191 4 1 4 23 2 1 3 13 4 1 4 184 8 8 8 32 1 3 1 9 


