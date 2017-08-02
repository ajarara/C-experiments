#include <stdio.h>
#include <stdlib.h>

/* can we look at our own stack? */

/* we want the ability to have one thread spin endlessly, but we'd like some sigil to know we're looking at a stack of another thread. */

int main(void) {
  int x = 5;
  printf("%p\n", &x);
  return 0;
}
