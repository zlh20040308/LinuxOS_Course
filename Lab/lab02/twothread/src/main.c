#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define RUN_TIMES 5

int value = 100;

void *hello(void *arg) {
  for (int i = 0; i < RUN_TIMES; ++i) {
    printf("hello(%d)\n", value++);
    sleep(1);
  }
}

void *world(void *arg) {
  for (int i = 0; i < RUN_TIMES; ++i) {
    printf("world(%d)\n", value++);
    sleep(1);
  }
}


int main() {
  srand(time(NULL));
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, hello, NULL);
  pthread_create(&tid2, NULL, world, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("In main thread\n");
  return 0;
}
