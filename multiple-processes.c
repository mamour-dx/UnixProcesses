#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Supposons le scénario suivant: 

int main(int argc, char* argv[]) {
    int id1 = fork(); // Nous avons deux process, un parent P et un enfant X
    int id2 = fork(); // Nous avons maintenant 4 process, chaqu'un des deux process précédent (P & X) donne naissance a un nouveau process. Nous les nommons respectivement Z et Y.

    if (id1 == 0) // Nous sommes dans le process X
    {
        if (id2 == 0) // Nous sommes dans le process Y
        {
            printf("Je suis le process Y | PID: %d | PPID: %d\n", getpid(), getppid());
        }
        else // Nous sommes dans le process X 
        {
            printf("Je suis le process X | PID: %d | PPID: %d\n", getpid(), getppid());   
        }

    }
    else // Nous sommes dans le process P
    {
        if (id2 == 0) // Nous sommes dans le process Z
        {
            printf("Je suis le process Z | PID: %d | PPID: %d\n", getpid(), getppid());
        }
        else {
            printf("We are the Parent Process P | PID: %d\n", getpid());
        }

    }
    return 0;
}




