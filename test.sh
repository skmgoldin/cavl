#!/bin/sh

echo --------------------
echo Making 
echo --------------------

make all

echo --------------------
echo single rotation
echo --------------------

valgrind --leak-check=yes -q ./treetest 1 2 3
