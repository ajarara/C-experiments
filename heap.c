#include <stdio.h>

/* Suppose you've got a program that interacts with some_struct: */

typedef struct {
  long x;
  long y;
} some;

/* what's so bad about keeping it on the stack? */
some *make(long x, long y) { 
  some thing;
  thing.x = x;
  thing.y = y;
  some *that = &thing;
  return that;
}

void cleanse_stack(long junk) {
  if (junk > 0) {
    cleanse_stack(junk - 1);
  };
}


int main(void) {
  /* Here "make" allocates a stack frame, but when it returns, the
  frame holding make is popped. Can I still access the contents of the struct? */
  some *thing = make(5,4);
  /* Aha! We get a seg fault. */
  /* printf("(Out of frame) Contents of thing->x: %d\n", thing->x); */
  /* Is it because we're attempting to access memory that is out of our stack? */
  /* so this works... Which means that this is indeed the case. */
  printf("Contents of thing->x: %d\n", thing->x);
  printf("Contents of thing->y: %d\n", thing->y);

  cleanse_stack(90);

  printf("(Cleansed) Contents of thing->x: %d\n", thing->x);
  printf("(Cleansed) Contents of thing->y: %d\n", thing->y);

  return 0;
}



