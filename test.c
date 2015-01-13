#include "avltree.h"
#include <assert.h>
#include <stdio.h>

int intcomparator(void *a, void *b) {
  printf("%s\n", "Comparing...");
  int inta = *((int *) a);
  int intb = *((int *) b);

  if(inta == intb) {return 0;}

  return 1;
}

int main(int argc, char **argv) {
  
  printf("%s\n", "Building tree");
  struct Handle *tree = gettree(&intcomparator);

  for(int x = 1; x < argc; x++) {
    addleaf(tree, argv + x); 
  }
  printf("%s\n", "Tree built.");

  printf("%s\n", "Deallocating tree.");
  killtree(tree);
  printf("%s\n", "Tree deallocated.");

  return 1;
}
