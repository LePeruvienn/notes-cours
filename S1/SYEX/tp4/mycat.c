#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <assert.h>

void sigpipe(int sig) {
	// Vérifie si le signal est bien SIGPIPE
	assert(sig == SIGPIPE);
	// Affiche un message
	fprintf(stderr, "SIGPIPE received... aborting in 5 seconds\n");
	// Attend 5 secondes
	sleep(5);
	// Ferme le programme avec succès
	exit(0);
}

int main(int argc, char* argv[]) {
	if (argc != 1) {
		fprintf(stderr, "usaage: %s\n", argv[0]);
		exit(1);
	}

	fprintf(stderr, "%s: started\n", argv[0]);
	signal(SIGPIPE, sigpipe); // La fonction `sigpipe` gère les signaux SIGPIPE
	
	while (1) {
		char c;
		// Lit dans le stdin un caractère
		int statut = read(0, &c, 1);
		// Si ça marche pas erreur
		if (statut == -1) {
			perror("[read]");
			exit(2);
		// Si ça marche on écrit un `.` dans le stderr
		} else if (statut == 0) {
			write(2, ".", 1);
			// On attend 0.1 secondes
			usleep(100000); /* 0.1s */

		// Si le status est 1 on écrit rien dans le stdout
		// (En fait je crois le but c'est de bloqué le truc)
		} else { /* statut == 1 */
			write(1, &c, 1);
		}
	}

	return 0;
}
