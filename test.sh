#!/bin/sh

VALGRIND="valgrind --leak-check=yes --log-file=results.txt"
TESTPROG="./treetest"
PRINTING="grep -A 20 \"HEAP SUMMARY\" results.txt"
CLEANUP="rm results.txt"

echo --------------------
echo Making 
echo --------------------

make all

echo --------------------
echo RS single rotation
echo --------------------

$VALGRIND $TESTPROG 1 2 3
eval $PRINTING
$CLEANUP

echo --------------------
echo LS single rotation
echo --------------------

$VALGRIND $TESTPROG 3 2 1
eval $PRINTING
$CLEANUP

echo --------------------
echo RS double rotation
echo --------------------

$VALGRIND $TESTPROG 1 3 2
eval $PRINTING
$CLEANUP

echo --------------------
echo LS double rotation
echo --------------------

$VALGRIND $TESTPROG 5 3 4
eval $PRINTING
$CLEANUP

echo --------------------
echo RS single rotation, RS double rotation
echo --------------------

$VALGRIND $TESTPROG 1 2 3 5 4
eval $PRINTING
$CLEANUP

echo --------------------
echo RS double rotation, RS single rotation
echo --------------------

$VALGRIND $TESTPROG 1 3 2 4 5 
eval $PRINTING
$CLEANUP

echo --------------------
echo RS single rotation, RS single rotation
echo --------------------

$VALGRIND $TESTPROG 1 2 3 4 5
eval $PRINTING
$CLEANUP

echo --------------------
echo RS double rotation, RS double rotation
echo --------------------

$VALGRIND $TESTPROG 1 3 2 5 4 
eval $PRINTING
$CLEANUP

echo --------------------
echo No Rotations
echo --------------------

$VALGRIND $TESTPROG 2 1 3 1 2 3 5  
eval $PRINTING
$CLEANUP

echo --------------------
echo Random String
echo --------------------

$VALGRIND $TESTPROG 1 2 3 1 3 2 5 4 8 3 9 4 1 4 1 1 9 4 1 4 3 2 1 3 3 4 1 4 1 8 8 8 3 1 3 1 9 3 2 9 8 4 1 9 1 3 4 3 1 2 3 2 3 4 5 6 7 2 3 4 8 7 2 1 3 4 5 3 1 9 1 1 4 5 3 3 1 1 4 5 8 3 3 4 2 2 1 3 1 4 2 1 2 3 2 1 2 2 1 2 2 2 2 3 4 2 3 9 5 2 4 6 2 4 3 4 9 4 7 1 7 7 2 3 8 6 4 3 4 2 1 9 4 2 8 1 2 3 8 9 4 5 3 2 2 1 8 4 9 9 1 3 4 2 1 2 3 2 1 3 9 9 8 7 5 8 6 9 3 2 1 9 5 6 9
eval $PRINTING
$CLEANUP


