#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define ID(m,a,b) ((a)*(m)+(b))

struct arg_struct {
    int n, n1, m1, n2, m2;
    int *buckets, *matrix1, *matrix2;
};

int multiplyLineColumn(int *matrix1, int *matrix2, int m1, int m2, int n, int m) {
    int result = 0;
    int k;
    for (k = 0; k < m1; k++) {
        result += matrix1[ID(m1,n,k)]*matrix2[ID(m2,k,m)];
    }
    return result;
}

void *forkn(void *arg) {
    struct arg_struct *in = (struct arg_struct*)arg;
    int i;
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

    pthread_t thr1, thr2;

    int n = atoi(argv[3]);
    pthread_t *threads = malloc(n*sizeof(pthread_t));
    for (i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, forkn, NULL);
    }

    free(matrix1);
    free(matrix2);
    return 0;
}
