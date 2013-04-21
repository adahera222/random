#include <stdio.h>
#include <stdlib.h>

#define ID(m,a,b) ((a)*(m)+(b))

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

    printMatrix(matrix1, n1, m1);
    printMatrix(matrix2, n2, m2);
    int *m12 = multiplyMatrix(matrix1, n1, m1, matrix2, n2, m2);
    printMatrix(m12, n1, m2);

    // m1 == n2

    return 0;
}
