#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(char argc, char** argv) {
  int old;
  int now;
  struct timespec* old_time = malloc(sizeof(struct timespec));
  struct timespec* new_time = malloc(sizeof(struct timespec));

  clock_gettime(CLOCK_REALTIME, old_time);

  old = nice(0);
  while(1) {
    now = nice(0);
    if (old != now) {
      clock_gettime(CLOCK_REALTIME, new_time);
      printf("New nice: %d took nanoseconds: %d\n", now,
             new_time->tv_nsec - old_time->tv_nsec);
      old = now;
      old_time->tv_nsec = new_time->tv_nsec;
    }
  }

  free(old_time);
  free(new_time);
  return 0;
}
