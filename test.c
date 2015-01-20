#include "avltree.h"
#include <assert.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int intcomparator(void *rootvalue, void *newvalue) {
  int rootintvalue = *(int *) rootvalue;
  int newintvalue = *(int *) newvalue;

  if(newintvalue == rootintvalue) {return 0;}
  if(newintvalue < rootintvalue) {return -1;}
  if(newintvalue > rootintvalue) {return 1;}

  return 1; // Never happens
}

int main(int argc, char **argv) {
  
  printf("%s\n", "Building tree");
  struct Handle *handle = gettree(handle, &intcomparator, sizeof(int));

  srand(time(NULL));
  int quantity = atoi(*(argv + 1));

  for(int x = 0; x < quantity; x++) {
    int *node = malloc(sizeof(int));
    *node = rand();
    handle = addnode(handle, (void *) node); 
  }

  printf("%s\n", "Tree built.");

  printf("%s\n", "Deallocating tree.");
  killtree(handle);
  printf("%s\n", "Tree deallocated.");

  return 1;
}
