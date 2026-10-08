#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/*
 * Récupère la taille d'un fichier donné en paramètre
 */
int get_file_size(FILE *stream) 
{
  // on met la position du curseur à la toute fin du fichier
  fseek(stream, 0L, SEEK_END);

  // on récupère la position du curseur, en bit, et la stocke (ce qui donne la taille en bit)
  int file_size = ftell(stream);

  // on remet le curseur au début
  rewind(stream);
  return file_size;
}

/*
 * Lit une partie de fichier à partir de pos et pendant size bits
 */
int read_part(int write_pipe, FILE *stream, int pos, int size)
{
  int pid;
  // on met le stream à la bonne position
  fseek(stream, pos, SEEK_CUR);
  if ((pid = fork()) == 0) 
  {
    int ln = 0;
    char curr_char;
    // on lit caractère par caractère, en stockant dans curr_char
    for (int i = 0; i < size; i++) 
    {
      // fread() permet de stocker dans son premier argument,
      // des élements de taille deuxième argument (ici, sizeof(char))
      // au nombre du troisième argument (ici, un seul élément)
      // depuis le stream donné en quatrième argument
      // donc ici on met dans curr_char un char lu depuis stream
      fread(&curr_char, sizeof(char), 1, stream);
      if (curr_char == '\n') 
      {
        ln++;
      }
    }
    write(write_pipe, &ln, sizeof(int));
    exit(EXIT_SUCCESS);
  }

  return pid;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("usage: %s <path> <job>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int JOBS = strtol(argv[2], (char**)NULL, 10);

  // stockage de l'entrée & sortie du pipe
  int fd[2];
  // on ouvre le pipe
  int status = pipe(fd);

  if (status == -1) 
  {
    return EXIT_FAILURE;
  }

  // on alloue la mémoire pour stocker une liste de JOBS éléments
  FILE** flist = malloc(sizeof(FILE*) * JOBS);
  for (int i = 0; i < JOBS; i++) 
  {
    flist[i] = fopen(argv[1], "r");
  }

  int fz = get_file_size(flist[0]);

  // on divise la taille du fichier en JOBS parts égales
  int part_size = fz / JOBS;

  // on ouvre tous les processus fils, qui vont lire leur partie
  read_part(fd[1], flist[0], 0, part_size);
  for (int i = 1; i < JOBS - 1; i++) 
  {
    read_part(fd[1], flist[i], i*part_size, part_size);
  }
  read_part(fd[1], flist[JOBS-1], (JOBS-1)*part_size, 
      // au cas où que le nombre de bit ne soit pas divisible par 4, on ajoute ceux en trop
      // dans la dernière partie
      (fz % JOBS != 0) ? part_size + fz % JOBS : part_size);

  int total_ln = 0;
  for (int i = 0; i < JOBS; i++) 
  {
    int status;
    wait(&status);
    int proc_ln;
    // un processus s'est stoppé, donc on peut lire le pipe
    // on lit la taille d'un int (qui est la valeur passée) et on le met dans proc_ln
    read(fd[0], &proc_ln, sizeof(int));
    total_ln += proc_ln;
    // on oublie pas de fermer le fichier
    fclose(flist[i]);
  }

  // on affiche tout
  printf("%d %s\n", total_ln, argv[1]);


  // on libère la liste des fichiers
  free(flist);
  return EXIT_SUCCESS;
}
