#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define TICKETAGENT_NUM 9

int ticketAmount = 7;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *ticketAgent(void *arg) {

  pthread_mutex_lock(&lock);
  int t = ticketAmount;
  if (t > 0) {
    printf("One ticket sold!\n");
    --t;
  } else {
    printf("Ticket sold out!!\n");
  }
  ticketAmount = t;
  pthread_mutex_unlock(&lock);
  
  pthread_exit(0);
}

int main() {
  pthread_t ticketAgent_tid[TICKETAGENT_NUM];

  for (int i = 0; i < TICKETAGENT_NUM; ++i) {
    pthread_create(ticketAgent_tid + i, NULL, ticketAgent, NULL);
  }

  for (int i = 0; i < TICKETAGENT_NUM; ++i) {
    pthread_join(ticketAgent_tid[i], NULL);
  }

  printf("The left ticket is %d", ticketAmount);

  return 0;
}
