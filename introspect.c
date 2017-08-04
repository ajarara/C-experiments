#include <stdio.h>

/* including stdlib just for atoi lol */
#include <stdlib.h>

/* can we look at our own stack? */

/* we want the ability to have one thread spin endlessly, but we'd like some sigil to know we're looking at a stack of another thread. */

/* a couple ideas I've had since yesterday when I was discussing this with others:

I could allocate something on the stack and point references to it. This means that there is no way to tell what's going on in main reliably without descending as far as I can go without segfaulting */

/* Alternatively, interface with either gdb or valgrind. These all allow me to step through functions.. but the problem here is that now I have to learn about their API's */

/* allocate an int on the stack, then iterate backwards until you find the function pointer. Once you have that, print out its location in memory. */

void subr(long fake_ptr, int depth) {
  /* initialize some junk on the stack */
  long x = 0;
  long *x_ptr_up = &x;
  long *x_ptr_down = &x;
  
  /* move down the stack until a reference to it is found */
  while (*x_ptr_up != fake_ptr) {
    ++x_ptr_up;
  }
  while (*x_ptr_down != fake_ptr) {
    --x_ptr_down;
  }
  /* They're always 16*5 bits apart!  */
  /* And this makes sense conceptually: long is 32 bits, the two pointers are 16 bits each. The pointer to return execution to is 16 bits. But why is the top and bottom of the frame wrapped around main pointers? */
  printf("Stack: up from depth:      %d, %p\n", depth, x_ptr_up);
  if (depth > 0) {
    subr(x, depth - 1);
  }
  printf("Stack: down from main:     %d, %p\n", depth, x_ptr_down);
}

/* Wait.. can I get a pointer to where main is in address space? */
/* SWEET I can! */

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
    %s [NUM]", argv[0]);
    return 1;
  }
    
  int (*recurse)() = &main;
  /* Text refers to the code, and is static. Or is it? */
  printf("Text: main: %p\n", recurse);
  subr((long) recurse, depth);
  return 0;
}

/* Hm... stack frames. Are there dedicated registers for keeping track of stack? */


