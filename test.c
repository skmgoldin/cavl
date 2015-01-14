#include "avltree.h"
#include <assert.h>
#include <stdio.h>

int intcomparator(void *rootvalue, void *newvalue) {
  int rootintvalue = atoi((char *) rootvalue);
  int newintvalue = atoi((char *) newvalue);

  if(newintvalue == rootintvalue) {return 0;}
  if(newintvalue < rootintvalue) {return -1;}
  if(newintvalue > rootintvalue) {return 1;}

  return 1; // Never happens
}

int main(int argc, char **argv) {
  
  printf("%s\n", "Building tree");
  struct Handle *tree = gettree(&intcomparator, sizeof(int));

  for(int x = 1; x < argc; x++) {
    addnode(tree, (void *) *(argv + x)); 
  }
  printf("%s\n", "Tree built.");

  printf("%s\n", "Deallocating tree.");
  killtree(tree);
  printf("%s\n", "Tree deallocated.");

  return 1;
}
