#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler() {

	printf("done :3\n");
	exit(0);
}

void mysleep(unsigned int nb)
{
	alarm(nb);
	pause();
}


int main(int argc, char* argv[])
{
	signal(SIGALRM, handler); // La fonction `sigpipe` gère les signaux SIGPIPE

	if (argc!=2) {
		fprintf(stderr, "usage: %s <int>\n", argv[0]);
		return 1;
	}

	printf("%s [%d]\n", argv[0], getpid());
	mysleep(strtoul(argv[1], NULL, 10));
	printf("done.\n");

	return 0;
}
