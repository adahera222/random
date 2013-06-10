#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define	N 1
#define	TRUE 1

int	buffer[N];
sem_t vazio, cheio, mutex;

void *produtor(void *arg) {
   int in=0;

   while(TRUE) {
      sem_wait(&vazio);
      sem_wait(&mutex);
      buffer[in] = rand();
      printf("Produzindo %d\n", buffer[in]);
      in= (in+1) % N;
      sem_post(&mutex);
      sem_post(&cheio);
   }
}

void *consumidor(void *arg) {
   int item, out=0;

   while(TRUE) {
      sem_wait(&cheio);
      sem_wait(&mutex);
      item = buffer[out];
      printf("Consumindo %d\n", item);
      out = (out+1) % N;
      sem_post(&mutex);
      sem_post(&vazio);
   }
}

int main(int argc, char *argv[ ]) {
    pthread_t cons, prod;

    sem_init(&mutex, 0, 1);
    sem_init(&vazio, 0, N);
    sem_init(&cheio, 0, 0);

    pthread_create(&prod, NULL, produtor, NULL);
    pthread_create(&cons, NULL, consumidor, NULL);
	
	//...
    
	pthread_join(prod, NULL);
    pthread_join(cons, NULL);
}
