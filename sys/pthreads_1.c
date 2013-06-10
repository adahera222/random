#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define ID(m,a,b) ((a)*(m)+(b))

struct arg_struct {
    int n, line, n1, m1, n2, m2;
    int *matrix1, *matrix2;
};

int multiplyLineColumn(int *matrix1, int *matrix2, int m1, int m2, int n, int m) {
    int result = 0;
    int k;
    for (k = 0; k < m1; k++) {
        result += matrix1[ID(m1,n,k)]*matrix2[ID(m2,k,m)];
    }
    return result;
}

void *threadedMultiplyLineColumn(void *arg) {
    struct arg_struct *in = (struct arg_struct*)arg;
    int *result = (int*)calloc(2*in->m2*in->n, sizeof(int));
    int i, j;
    for (i = 0; i < in->n; i++) {
        for (j = 0; j < in->m2; j++) {
            result[ID(in->m2,i,j)*2] = multiplyLineColumn(in->matrix1, in->matrix2, in->m1, in->m2, in->line, j);
            result[ID(in->m2,i,j)*2+1] = in->line;
        }
        in->line++;
    }
    pthread_exit(result);
}

void printMatrix(int *matrix, int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", matrix[ID(m,i,j)]);
        }
        printf("\n");
    }
}

int* multiplyMatrix(int *matrix1, int n1, int m1, int *matrix2, int n2, int m2) {
    int *result = (int*)calloc(n1*m2, sizeof(int));
    if (m1 == n2) {
        int i, j, k;
        for (i = 0; i < n1; i++) {
            for (j = 0; j < m2; j++) {
                for (k = 0; k < m1; k++) {
                    result[ID(m2,i,j)] += matrix1[ID(m1,i,k)]*matrix2[ID(m2,k,j)];
                }
            }
        }
    } else {
        printf("Wrong dimensions.\n");
        free(result);
        return NULL;
    }
    return result;
}

int* copyArray(int *array, int size) {
    int *result = (int*)calloc(size, sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        result[i] = array[i];
    }
    return result;
}

int main(int argc, const char *argv[]) {
    // Assumes: 
    // files 1 and 2 exist;
    // number of rows and columns (m, n, x) < INT_MAX.

    FILE *f1, *f2;
    int i, j;
    char s1[10], s2[10];

    f1 = fopen(argv[1], "r");
    int n1, m1;
    fscanf(f1, "%s %s %d", s1, s2, &n1);
    fscanf(f1, "%s %s %d", s1, s2, &m1);
    int* matrix1 = (int*)calloc(n1*m1, sizeof(int));

    for (i = 0; i < n1; i++) {
        for (j = 0; j < m1; j++) {
            fscanf(f1, "%d", &matrix1[ID(m1,i,j)]);
        }
    }

    f2 = fopen(argv[2], "r");
    int n2, m2;
    fscanf(f2, "%s %s %d", s1, s2, &n2);
    fscanf(f2, "%s %s %d", s1, s2, &m2);
    int* matrix2 = (int*)calloc(n2*m2, sizeof(int));

    for (i = 0; i < n2; i++) {
        for (j = 0; j < m2; j++) {
            fscanf(f2, "%d", &matrix2[ID(m2,i,j)]);
        }
    }

    /* printMatrix(matrix1, n1, m1); */
    /* printMatrix(matrix2, n2, m2); */

    int n = atoi(argv[3]);

    struct timespec start, finish;
    double elapsed;
    clock_gettime(CLOCK_MONOTONIC, &start);
        pthread_t *threads = malloc(n*sizeof(pthread_t));
        int *buckets = calloc(n, sizeof(int));
        j = 0;
        for (i = 0; i < n1; i++) {
            buckets[j] += 1;
            j++;
            if (j >= n) j = 0;
        }
        struct arg_struct *args = malloc(n*sizeof(struct arg_struct));
        int **results = calloc(n, sizeof(int*));
        int current_line = 0;
        for (i = 0; i < n; i++) {
            args[i].n1 = n1; args[i].m1 = m1; args[i].n2 = n2; args[i].m2 = m2;
            args[i].matrix1 = copyArray(matrix1, n1*m1);
            args[i].matrix2 = copyArray(matrix2, n2*m2);
            args[i].n = buckets[i];
            results[i] = calloc(2*m2*buckets[i], sizeof(int));
            args[i].line = current_line;
            current_line += args[i].n;
            pthread_create(&threads[i], NULL, threadedMultiplyLineColumn, (void*)&args[i]);
        }
        current_line = 0;
        int *matrix12 = (int*)calloc(n1*m2, sizeof(int));
        int k = 0;
        for (i = 0; i < n; i++) {
            pthread_join(threads[i], (void**)&results[i]);
            for (j = 0; j < 2*m2*buckets[i]; j+=2) {
                matrix12[ID(m2,results[i][j+1],k)] = results[i][j];
                k++;
                if (k >= m2) k = 0;
            }
        }
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec)/1000000000.0;
    printf("Elapsed threaded: %f\n", elapsed);

    clock_gettime(CLOCK_MONOTONIC, &start);
        int *matrix122 = (int*)calloc(n1*m2, sizeof(int));
        matrix122 = multiplyMatrix(matrix1, n1, m1, matrix2, n2, m2);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec)/1000000000.0;
    printf("Elapsed normal: %f\n", elapsed);

    free(matrix1);
    free(matrix2);
    free(matrix12);
    return 0;
}
