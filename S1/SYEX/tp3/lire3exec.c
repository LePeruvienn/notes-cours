#include <stdio.h>
#include <unistd.h>
#include "/pub/FISE_OSSE11/syscall/lire.h"

int main() {

	fprintf(stderr, "Je suis le programme lire.\n");
	lire();
	lire();
	lire();
	execl("lire", "lire", NULL);
	return 0;
}
