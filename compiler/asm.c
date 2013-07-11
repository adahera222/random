#include <stdio.h>

int a = 1;
int b = 4;
int main() {
    while (b > 0) {
        a++;
        b--;
    }
    printf("%d\n", a);
}

