#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

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

void read_part(FILE *stream, int pos, int size)
{
  int pid;
  fseek(stream, pos, SEEK_CUR);
  if ((pid = fork()) == 0) 
  {
    int ln = 0;
    char curr_char;
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

    printf("range %d:%d = %d\n", pos, pos+size, ln);
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("usage: %s <path>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // liste des stream, il en faut un par processus fils, donc 4 ici
  FILE* flist[4];
  for (int i = 0; i < 4; i++) 
  {
    flist[i] = fopen(argv[1], "r");
  }

  int fz = get_file_size(flist[0]);
  int part_size = fz / 4;

  for (int i = 0; i < 4 - 1; i++)
  {
    read_part(flist[i], i*part_size, part_size);
  }
  // on fait la dernière partie à part, pour pouvoir lire les derniers bits
  // dans le cas où la taille de fichier n'est pas divisible par 4
  read_part(flist[3], 3*part_size, 
      (fz % 4 != 0) ? part_size + fz % 4 : part_size);

  for (int i = 0; i < 4; i++) {
    int status;
    wait(&status);
    // on oublie pas de fermer le fichier
    fclose(flist[i]);
  }

  return EXIT_SUCCESS;
}
