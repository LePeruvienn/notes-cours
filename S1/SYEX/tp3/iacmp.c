#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	setenv("IacmpDir", "/pub/FISE_OSSE11/shell/iacmp", 1);
	setenv("LD_LIBRARY_PATH", "/pub/FISE_OSSE11/shell/iacmp/lib", 1);

	int res = execv("/pub/FISE_OSSE11/shell/iacmp/iacmp", argv);

	if (res != 0) {

		fprintf(stderr, "%s: execv failed: %s\n",argv[0], "Je sais pas quoi mettre");
		return 1;
	}
	
	return 0;
}
