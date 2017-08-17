#include <signal.h>
#include <stdio.h>

int loops = 0;
long *x;
long *there;


void ignore() {
  printf("encountered segfault! Main loops: %d\n", loops);
  x = there;
}

int main(void) {
  long here;
  there = &here;
  x = &here;
  signal(SIGSEGV, ignore);
  while(1) {
    loops++;
    printf("Pointer: %p\t", x);
    printf("Data: %d\n", *x);
    x--;
  }
  
}


