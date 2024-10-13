#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void *threadFunc(void *arg) { printf("In New thread\n"); }

int main() {
  pthread_t tid;

  pthread_create(&tid,NULL,threadFunc,NULL);

  pthread_join(tid,NULL);
  printf("In main thread\n");
  return 0;
}
