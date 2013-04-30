#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void doWork(char *arg) {
    while (1) printf("%s\n", arg);
}

int main() {
    
}
