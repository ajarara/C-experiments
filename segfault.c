#include <stdlib.h>
#include <stdio.h>

/* yes, this code segfaults. Don't run it unless you like collecting core dumps. */
void check(void *x) {
  printf("%d\n", (int) x);
  x--;
  check(x);
}


int main () {
  void *x = 0x20a9010;
  check(x);
}
