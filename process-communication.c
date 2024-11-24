#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int fd[2];
    // fd[0] -> read end
    // fd[1] -> write end
    if (pipe(fd) == -1) {
        printf("An error occured with opening the pipe\n");
        return 0;
    }
    
    int id = fork();
    if (id == 0) { 
        close(fd[0]); // Close the read end (because we only need to write)
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int)); // write(write end, adress to read, size of what we are reading)
        close(fd[1]); // Close the write end because we're done
    }
    else {
        int x;
        close(fd[1]); 
        read(fd[0], &x, sizeof(int));
        printf("The number from child process is: %d\n", x);
        close(fd[0]);
    }
} 