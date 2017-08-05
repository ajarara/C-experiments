#include <stdio.h>
/* polluting our namespace just for atoi lol */
#include <stdlib.h>

void subr(long contents, int curr_depth, int depth) {          
  /* initialize some junk on the stack */
  /* I'm not sure how to put this on one line */
  long x = 0;
  long *x_ptr = &x;
  
  while (*x_ptr != contents) {
    x_ptr--;
  }
  printf("Stack: down from depth:\t%d,\t%p\n", curr_depth, x_ptr);
  
  if (curr_depth < depth) {
    subr((long) &subr, curr_depth + 1, depth);
  }
}

int main(int argc, char **argv) {
  int depth;
  switch(argc) {
  case 1:
    depth = 1;
    break;
  case 2:
    depth = atoi(argv[1]);
    break;
  default:
    printf("Usage:\n\
    %s [NUM]\n", argv[0]);
    return 1;
  }
  int (*recurse)() = &main;
  printf("Text: main: %p\n", recurse);

  /* inlining this is ugly but necessary */
  long x = 0;
  long *x_ptr = &x;
  
  while(*x_ptr != (long) recurse) {
    x_ptr++;
  }
  printf("Stack: main func pointer:\t%p\n", x_ptr);
  
  subr((long) recurse, 0, depth);
  return 0;
}


