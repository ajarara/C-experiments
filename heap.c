#include <stdio.h>

/* Suppose you've got a program that interacts with some_struct: */

typedef struct {
  int x;
  int y;
} some;

/* what's so bad about keeping it on the stack? */
some *make(int x, int y) { 
  some thing;
  thing.x = 5;
  thing.y = 6;
  return &thing;
}


int main(void) {
  /* Here "make" allocates a stack frame, but when it returns, the
  frame holding make is popped. Can I still access the contents of the struct? */
  some *thing = make(5,4);
  /* Aha! We get a seg fault. */
  /* printf("(Out of frame) Contents of thing->x: %d\n", thing->x); */
  /* Is it because we're attempting to access memory that is out of our stack? */
  some *other;
  other->x = 5;
  other->y = 6;
  /* so this works... Which means that this is indeed the case. */
  printf("(In frame) Contents of other->x: %d\n", other->x);

  return 0;
}



