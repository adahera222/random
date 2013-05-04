#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int a = 0;
int b = 0;

void doWork(pid_t pid) {
    if (pid == 0) a = 1;
    else b = 2;

    printf("%d %d\n", a, b);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        doWork(pid);
        exit(0);
    } else {
        doWork(pid);
        waitpid(pid, 0, 0);
    }
    return 0;
}
