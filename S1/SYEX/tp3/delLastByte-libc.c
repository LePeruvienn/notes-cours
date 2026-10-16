#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char** argv) {

	if (argc != 2) {

		fprintf(stderr, "%s: Erreur: Vous devez entrée 1 argument\n", argv[0]);
		return 1;
	}

	FILE* f = fopen(argv[1], "r");

	fseek(f, 0, SEEK_END);
	int f_size = ftell(f);

	printf("f_size = %d\n",f_size);

	char* buffer = malloc((f_size - 1) * sizeof(char));

	fseek(f, SEEK_SET, 0);

	fread(buffer, sizeof(*buffer), sizeof(char) * (f_size - 1), f);

	fclose(f);

	f = fopen(argv[1], "w+");

	fwrite(buffer, sizeof(*buffer), sizeof(char) * (f_size - 1), f);

	free(buffer);

	fclose(f);
}
