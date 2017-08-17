#include <stdio.h>


int main(int argc, char **argv ) {
  int rng = 5;
  int nums[rng];
  for (int i=0; i < rng; i++) {
    
    printf("Contents of %p: %d\n", nums + i, *(nums + i));
  }
  return 0;
}
