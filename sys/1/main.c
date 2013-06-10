#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define ID(m,a,b) ((a)*(m)+(b))

int multiplyLineColumn(int *matrix1, int *matrix2, int m1, int m2, int n, int m) {
    int result = 0;
    int k;
    for (k = 0; k < m1; k++) {
        result += matrix1[ID(m1,n,k)]*matrix2[ID(m2,k,m)];
    }
    return result;
}

int* forkn(int n, int *buckets, int *matrix1, int n1, int m1, int *matrix2, int n2, int m2) {
    pid_t pid;
    int i, j, l;
    int current_line = 0;
    int k = 0;
    int *result_matrix = (int*)calloc(n1*m2, sizeof(int));
    for (i = 0; i < n; i++) {
        if ((pid = vfork()) < 0) {
            printf("vfork error");
        } else if (pid == 0) {
            printf("child ");
            int n_lines = buckets[k];
            for (j = 0; j < n_lines; j++) {
                for (l = 0; l < m2; l++) {
                    result_matrix[ID(m2,current_line,l)] = multiplyLineColumn(matrix1, matrix2, m1, m2, current_line, l);
                }
                current_line++;
            }
            k++;
            _exit(0);
        }
    }
    return result_matrix;
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
        int *buckets = calloc(n, sizeof(int));
        j = 0;
        for (i = 0; i < n1; i++) {
            buckets[j] += 1;
            j++;
            if (j >= n) j = 0;
        }
        int* matrix12 = (int*)calloc(n1*m2, sizeof(int));
        matrix12 = forkn(n, buckets, matrix1, n1, m1, matrix2, n2, m2);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec)/1000000000.0;
    printf("Elapsed threaded: %f\n", elapsed);

    clock_gettime(CLOCK_MONOTONIC, &start);
        int* matrix122 = (int*)calloc(n1*m2, sizeof(int));
        matrix122 = multiplyMatrix(matrix1, n1, m1, matrix2, n2, m2);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    elapsed = (finish.tv_sec - start.tv_sec);
    elapsed += (finish.tv_nsec - start.tv_nsec)/1000000000.0;
    printf("Elapsed normal: %f\n", elapsed);

    /* printMatrix(matrix12, n1, m2); */
    
    free(matrix1);
    free(matrix2);
    free(matrix12);
    free(matrix122);
    return 0;
}
