#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

int state_change = 0;
int current_round = 0;
int *states;
int *rank;
int *forks_use;
int n_eating = 0;
pthread_cond_t *forks;
pthread_cond_t n_eat;
pthread_mutex_t can_eat;
pthread_mutex_t get_fork;
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

int max(int *array, int size) {
    int m = 0;
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] > m) m = array[i];
    }
    return m;
}

// 1 = thinking, 2 = hungry, 3 = eating
void *beAPhilosopher(void *arg) {
    int s = *(int*)arg;
    while (1) {
        states[s] = 1;
        state_change = 1;
        rank[s]++;
        sleep(rand() % 1 + 1);
        states[s] = 2;
        state_change = 1;
        sleep(rand() % 1 + 1);

        if (rank[s] == max(rank, n)) {
            pthread_mutex_lock(&can_eat);
            while (n_eating > (int)n/2) pthread_cond_wait(&n_eat, &can_eat);
            if (!forks_use[s]) pthread_cond_wait(&forks[s], &can_eat);
            else forks_use[s] = 0;
            if (!forks_use[(s+1)%n]) pthread_cond_wait(&forks[(s+1)%n], &can_eat);
            else forks_use[(s+1)%n] = 0;
            pthread_mutex_unlock(&can_eat);

            n_eating++;
            states[s] = 3;
            state_change = 1;
            rank[s] = 0;
            sleep(rand() % 1 + 1);
            current_round++;
            states[s] = 1;
            state_change = 1;
            forks_use[s] = 1;
            forks_use[(s+1)%n] = 1;
            n_eating--;
            pthread_cond_signal(&forks[s]);
            pthread_cond_signal(&forks[(s+1)%n]);
            pthread_cond_signal(&n_eat);
        }
    }
}

int main(int argc, char **argv) {
    n = atoi(argv[1]);
    pthread_t *philosophers = malloc(n*sizeof(pthread_t));
    pthread_t state;
    forks = malloc(n*sizeof(pthread_cond_t));
    forks_use = calloc(n, sizeof(int));
    int *fi = calloc(n, sizeof(int));
    states = calloc(n, sizeof(int));
    rank = calloc(n, sizeof(int));

    int i;
    pthread_mutex_init(&can_eat, NULL);
    pthread_cond_init(&n_eat, NULL);
    for (i = 0; i < n; i++) forks_use[i] = 1;
    for (i = 0; i < n; i++) pthread_cond_init(&forks[i], NULL);
    for (i = 0; i < n; i++) fi[i] = i;
    for (i = 0; i < n; i++) pthread_create(&philosophers[i], NULL, beAPhilosopher, &fi[i]);
    pthread_create(&state, NULL, stateProcess, NULL);
    for (i = 0; i < n; i++) pthread_join(philosophers[i], NULL);
    pthread_join(state, NULL);
}
