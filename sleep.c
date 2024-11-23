#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// What happens when the perent process terminates before the child process

int main(int argc, char* argv[]) {
    int id = fork();
    if (id == 0) {
        sleep(1);
    }
    printf("Current ID: %d | Parent ID: %d\n", getpid(), getppid());
    if (id != 0) {
        wait(NULL);
    }
    return 0;
}

// When running this program, we notice that the child ID gets a new parent, the assignment criteria can chnage over different UNIX based OS.