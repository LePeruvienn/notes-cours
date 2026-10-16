#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int in = 0;
int out = 1;

int readpassword(char* pass) {

	system("/bin/stty raw -echo");

	// char star = '*';
	int n = 0;
	char c;

	while (n < 16 && c != '\0' && c != '\n' && c != '\r') {

		read(in, &c, 1);
		pass[n] = c;
		n++;
		write(out, "*", 1);
	}

	system("/bin/stty -raw echo");

	pass[n] = '\0';

	return n;
}

int main() {

	char* pass = malloc(sizeof(char) * 16);
	int n = readpassword(pass);
	printf("\n Password of \'%d\' chars : \"%s\"\n ", n, pass);
}
