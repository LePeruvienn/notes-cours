#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int pid[2] = { -1, -1 };
  int status[2];
  
  // premier fils : on le stocke dans pid[0]
  // le (pid[0] = fork()) exécute la commande dedans
  if ((pid[0] = fork()) == 0) {
    sleep(2);
    // j'ai utilisé write ici, sinon les éléments n'arrivaient pas dans le bon ordre
    // write(fd, buffer, size)
    // donc on demande à write d'écrire dans le buffer 1 (qui est stdout sur linux),
    // on lui donne "\n" et on demande d'écrire 1 octet
    write(1, "\n", 1);
    exit(1);
  }

  if ((pid[1] = fork()) == 0) {
    sleep(1);
    write(1, " world", 6);
    exit(1);
  }

  write(1, "hello", 5);

  // on attend deux fois, parce qu'il y a deux processus
  wait(&status[0]);
  wait(&status[1]);

  return EXIT_SUCCESS;
}
