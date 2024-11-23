#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int id = fork();
    printf("Current ID: %d | Parent ID: %d\n", getpid(), getppid());
    return 0;
}


// getpid() returns the PID of the current running ID.
// getppid() returns the PID of the Parent Process