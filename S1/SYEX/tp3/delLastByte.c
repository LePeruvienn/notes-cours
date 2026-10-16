#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {

	if (argc != 2) {

		fprintf(stderr, "%s: Erreur: Vous devez entrée 1 argument\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);

	int f_size = lseek(fd, 0, SEEK_END);

	char* buffer = malloc((f_size - 1) * sizeof(char));

	lseek(fd, SEEK_SET, 0);

	read(fd, buffer, f_size - 1);

	close(fd);

	fd = open(argv[1], O_WRONLY | O_TRUNC);

	write(fd, buffer, f_size - 1);

	free(buffer);

	close(fd);
}
