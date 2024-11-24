#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int arr[] = {1, 2, 3, 4, 1, 2};
    int arrSize = sizeof(arr) / sizeof(int); // Very important to get array size in C!
    int start , end;
    // The ultime goal of this program is to wrtie a program that will sum the numbers of this array by two different process. The first half of the array should be calculated by the array should be calculated by one array and the other half by another array.
    int fd[2];
    // fd[0] - read
    // fd[1] - write
     
    if (pipe(fd) == -1) {
        perror("Error when calling pipe function!");
        return 1;
    }

    int id = fork();
    if (id == -1) {
        perror("Error when forking the parent process");
        return 2;
    }

    if (id == 0) {
        int tot1 = 0;
        start = 0;
        end = arrSize / 2;
        for (int i = start; i < end; i++) {
            tot1 += arr[i];
        }
        close(fd[0]);
        write(fd[1], &tot1, sizeof(int));
        close(fd[1]);
    }

    else {
        int tot2 = 0;
        int tot1;
        start = arrSize / 2;
        end = arrSize;
        for (int i = start; i < end; i++) {
            tot2 += arr[i];
        }
        close(fd[1]);
        read(fd[0], &tot1, sizeof(int));
        close(fd[0]);
        printf("tot1 = %d\ntot2 = %d\nTotal = %d\n", tot1, tot2, tot1 + tot2);
    }








    return 0;
}