#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "/pub/FISE_OSSE11/syscall/lire.h"

int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "%s: Erreur veuillez 2 arguments.\n", argv[0]);
		return 1;
	}

	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd1 == -1) {
		fprintf(stderr, "%s: Erreur ouverture du fichier 1.\n", argv[0]);
		return 2;
	}

	if (fd2 == -1) {
		fprintf(stderr, "%s: Erreur ouverture fichier 2.\n", argv[0]);
		return 3;
	}

	int d1 = dup2(fd1, 0);
	int d2 = dup2(fd2, 1);

	if (d1 == -1) {
		fprintf(stderr, "%s: Erreur dup2 sur le flux 0.\n", argv[0]);
		return 2;
	}

	if (d2 == -1) {
		fprintf(stderr, "%s: Erreur dup2 sur le flux 1.\n", argv[0]);
		return 3;
	}

	lire();
	lire();
	lire();

	execl("lire", "lire", NULL);

	return 0;
}
