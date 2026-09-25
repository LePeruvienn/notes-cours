#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main() {

	int fd[2];
	
	if (pipe(fd) == -1) {
		
		perror("pipe creation failed");
		return 1;
	}

	fcntl(fd[1], F_SETFL, O_NONBLOCK);

	int count = 0;
	char c = 'a';

	while(1) {
	
		int w =write(fd[1], &c, sizeof(char));

		if (w == -1) {
			
			fprintf(stderr, "Erreur, %d => %s\n", errno, strerror(errno));
			printf("Erreur lors de la lecture, on sort de la boucle ...\n");
			break;
		}

		count++;
	}

	printf("Nombre d'octets écrit dans le pipe: %d\n", count);
}
