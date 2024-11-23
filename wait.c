#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char *argv[]) {
    pid_t id = fork();
    int n;
    if (id == 0) {
        for (int i = 1; i < 6; i++) {
            printf("%d\n", i);
        }
    }
    else {
        wait(NULL);
        for (int i = 6; i <= 10; i++) {
            printf("%d\n", i);
        }
    }
}

// The goal is to make a program that will print from 1 to 5 from the child process and 6 through 10 from the parent process
// Usage of wait function here demonstrate perfectly it's purpose. It makes the parent process wait for ANY child to finish its execution.
/*
If the parent process has multiple children, the wait() call will cause the parent to wait until any child process terminates.
If a child process terminates, wait() returns the PID of the terminated child.
If multiple child processes terminate, wait() will reap any one of them arbitrarily and return its PID.
If no children exist, wait() immediately returns -1.
*/