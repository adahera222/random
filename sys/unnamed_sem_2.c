#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

sem_t can_eat;
int current_round = 0;
int state_change = 0;
int* states;
sem_t* forks;
int n = 0;

char *stringAppend(char *src, int src_size, char *to_append, int to_append_size) {
    char *result = calloc((src_size+to_append_size), sizeof(char));
    strcat(result, src);
    strcat(result, to_append);
    result[src_size+to_append_size] = '\0';
    return result;
}

void *stateProcess(void *arg) {
    while (1) {
        if (state_change == 1) {
            char *result = "";
            int i;
            for (i = 0; i < n; i++) {
                if (states[i] == 1) {
                    char *s = "T ";
                    result = stringAppend(result, strlen(result), s, strlen(s)); 
                } else if (states[i] == 2) {
                    char *s = "H ";
                    result = stringAppend(result, strlen(result), s, strlen(s)); 
                } else if (states[i] == 3) {
                    char *s = "E ";
                    result = stringAppend(result, strlen(result), s, strlen(s)); 
                }
            }
            state_change = 0;
            printf("%s\n", result);
        }
    }
}

// 1 = thinking, 2 = hungry, 3 = eating
void *beAPhilosopher(void *arg) {
    int s = *(int*)arg;
    while (1) {
        states[s] = 1;
        state_change = 1;
        sleep(rand() % 1 + 1);
        states[s] = 2;
        state_change = 1;
        sleep(rand() % 1 + 1);
        sem_wait(&can_eat);
        sem_wait(&forks[s]);
        sem_wait(&forks[(s+1)%n]);
        states[s] = 3;
        state_change = 1;
        sleep(rand() % 1 + 1);
        current_round++;
        states[s] = 1;
        state_change = 1;
        sem_post(&forks[s]);
        sem_post(&forks[(s+1)%n]);
        sem_post(&can_eat);
    }
}

int main(int argc, char **argv) {
    n = atoi(argv[1]);

    pthread_t *philosophers = malloc(n*sizeof(pthread_t));
    pthread_t state;
    forks = malloc(n*sizeof(sem_t));
    int *fi = calloc(n, sizeof(int));
    states = calloc(n, sizeof(int));

    int i; 
    sem_init(&can_eat, 0, (int)n/2);
    for (i = 0; i < n; i++) sem_init(&forks[i], 0, 1);
    for (i = 0; i < n; i++) fi[i] = i;
    for (i = 0; i < n; i++) pthread_create(&philosophers[i], NULL, beAPhilosopher, &fi[i]);
    pthread_create(&state, NULL, stateProcess, NULL);
    for (i = 0; i < n; i++) pthread_join(philosophers[i], NULL);
    pthread_join(state, NULL);
}
