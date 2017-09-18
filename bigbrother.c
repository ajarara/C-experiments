#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


/* this holds the pointer that we'll be using to tell the child
   thread where the stack is */
long *mutate;

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void *child() {
  pthread_mutex_lock(&mut);
  for (int i = 0; i < 100; i++) {
    mutate = mutate - 1 + i;
    *mutate = 404;
  }
  /* mutate = mutate + 1; */
  /* *mutate = 500; */
  pthread_cond_signal(&cond);
  pthread_mutex_unlock(&mut);
}

/* void *child() { */
/*   pthread_mutex_lock(&mut); */
/*   printf("Original value of mutate:\t%ld\n", *mutate); */
/*   *mutate = *mutate + 1; */
/*   printf("New value of mutate:\t%ld\n", *mutate); */
/*   pthread_cond_signal(&cond); */
/*   pthread_mutex_unlock(&mut); */
/* } */

int main(void) {
  long orig = 0;
  long val = orig;
  pthread_t *child_thread;
  
  mutate = &val;
  
  printf("Pointer of mutate: %p\n", mutate);

    
  pthread_mutex_lock(&mut);
  printf("Starting child.\n");
  pthread_create(child_thread, NULL, &child, NULL);
  pthread_cond_wait(&cond, &mut);

  printf("Orig: %ld\n Val: %ld\n", orig, val);
  
}
