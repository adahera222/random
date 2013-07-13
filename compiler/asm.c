#include <stdio.h>

int a = 1;
int b = 4;

int fun(int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
    return e+f;
}

int fun2(int c, int d) {
    return c+d;
}

int main() {
    a = fun(2, b, 1, 1, 2, 3, 4, 5, 6, 7);
    b = fun2(1, 2);
    printf("%d\n", a);
    printf("%d\n", b);
}

