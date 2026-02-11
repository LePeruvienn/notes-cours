#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fork_sleep_print(int n)
{
    sleep(n);
    // on écrit le nombre 
    printf("%d\n", n);
}

int main(int argc, char *argv[])
{
    // si on a moins de deux arguments, il n'y a aucun nombre
    if (argc < 2) 
    {
        printf("usage: %s <n1> <n2> ... <n>\n", argv[0]);
        return EXIT_FAILURE;
    }


    int i = 0;

    while (++i < argc)
    {   
        // strtol permet de convertir depuis string -> long int
        int n = strtol(argv[i], (char **)NULL, 10);
        // on a une variable pid pour pouvoir comparer
        int pid;
        if ((pid = fork()) == 0) {
            // on est dans le fils car pid == 0, donc on lance la fonction
            fork_sleep_print(n);
            // on oublie pas de sortir
            exit(0);
        }
    }
    // on attend chaque processus
    while (i-->0)
    {
        int status;
        wait(&status);
    }
    return EXIT_SUCCESS;
}


