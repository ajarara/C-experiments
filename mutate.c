#include <stdlib.h>
#include <stdio.h>

/* this section simply asserts there is no need to return anything from functions that mutate values */
typedef struct {
  int count;
} foo;

foo* make_foo(int count) {
  foo* out = malloc(sizeof(foo));
  out->count = count;
  return out;
}

void bump_foo(foo* x) {
  x->count += 1;
}

int main(void) {
  foo* x = make_foo(5);
  bump_foo(x);
  printf("Foo's value is %d\n", x->count);
  free(x);
  return 0;
}
