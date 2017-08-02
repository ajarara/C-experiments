#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int* x = NULL;
  /* ruh roh */
  printf("%d is not going to get here.", *x);
  return 2;
}
