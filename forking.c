#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
    int id = fork();
    printf("ID: %d || PID: %d\n", id, getpid());
}

// The fork function split the execution to two processes: the parent and the child
// fork() returns 0 for the child process and return the PID of the child process in the parent process