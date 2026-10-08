#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

const char* signal_itoa(int signum);
int         signal_atoi(const char* define);
void        signal_print();


// Affiche le pid et le signal recu
void callback(int signum) {
	printf("callback:pid=%3d: got signal %s (%d).\n",
		getpid(), signal_itoa(signum), signum);
}


int main() {
	int i;
	//signal_print();

	for (i=1 ; i<=22 ; i+=1) {
		// Pour tout les singaux attache le fonction callback
		if (signal(i,callback) == SIG_ERR) {
			// Affiche un message d'erreur pour les signaux qui n'ont pas pu etre attacher
			fprintf(stderr, "call to signal failed (%s=%d): %s\n",
				signal_itoa(i), i, strerror(errno));
		}
	}

	printf("pid=%d\n", getpid());

	// affiche l'alphabet en boucle
	// Vide le buffer (donc force l'affichage
	// Attend un signal
	for (i='a'; ; i=i<'z'?i+1:'a') {
		printf("%c",i); fflush(stdout);
		pause();
	}

	return 0;
}

const char* signal_itoa(int signum) {
	switch (signum) {
		case SIGHUP : return "SIGHUP ";
		case SIGINT : return "SIGINT ";
		case SIGQUIT: return "SIGQUIT";
		case SIGILL : return "SIGILL ";
		case SIGABRT: return "SIGABRT";
		case SIGFPE : return "SIGFPE ";
		case SIGKILL: return "SIGKILL";
		case SIGSEGV: return "SIGSEGV";
		case SIGPIPE: return "SIGPIPE";
		case SIGALRM: return "SIGALRM";
		case SIGTERM: return "SIGTERM";
		case SIGUSR1: return "SIGUSR1";
		case SIGUSR2: return "SIGUSR2";
		case SIGCHLD: return "SIGCHLD";
		case SIGCONT: return "SIGCONT";
		case SIGSTOP: return "SIGSTOP";
		case SIGTSTP: return "SIGTSTP";
		case SIGTTIN: return "SIGTTIN";
		case SIGTTOU: return "SIGTTOU";
		default	 : return "???????";
	}
}

int signal_atoi(const char* define) {
	char sigstr[100], *p;
	strcpy(sigstr, define);
	for (p=sigstr ; *p ; p++) 
		if ('a'<=*p && *p<='z') *p += 'A' - 'a';

	if (strstr("HUP", sigstr) != 0) return SIGHUP ;
	if (strstr("INT", sigstr) != 0) return SIGINT ;
	if (strstr("QUIT",sigstr) != 0) return SIGQUIT;
	if (strstr("ILL", sigstr) != 0) return SIGILL ;
	if (strstr("ABRT",sigstr) != 0) return SIGABRT;
	if (strstr("FPE", sigstr) != 0) return SIGFPE ;
	if (strstr("KILL",sigstr) != 0) return SIGKILL;
	if (strstr("SEGV",sigstr) != 0) return SIGSEGV;
	if (strstr("PIPE",sigstr) != 0) return SIGPIPE;
	if (strstr("ALRM",sigstr) != 0) return SIGALRM;
	if (strstr("TERM",sigstr) != 0) return SIGTERM;
	if (strstr("USR1",sigstr) != 0) return SIGUSR1;
	if (strstr("USR2",sigstr) != 0) return SIGUSR2;
	if (strstr("CHLD",sigstr) != 0) return SIGCHLD;
	if (strstr("CONT",sigstr) != 0) return SIGCONT;
	if (strstr("STOP",sigstr) != 0) return SIGSTOP;
	if (strstr("TSTP",sigstr) != 0) return SIGTSTP;
	if (strstr("TTIN",sigstr) != 0) return SIGTTIN;
	if (strstr("TTOU",sigstr) != 0) return SIGTTOU;
	fprintf(stderr, "unknown signal %s\n", define);
	exit(1);
}

void signal_print() {
	printf("signal SIGHUP = %d\n",SIGHUP  );
	printf("signal SIGINT = %d\n",SIGINT  );
	printf("signal SIGQUIT= %d\n",SIGQUIT );
	printf("signal SIGILL = %d\n",SIGILL  );
	printf("signal SIGABRT= %d\n",SIGABRT );
	printf("signal SIGFPE = %d\n",SIGFPE  );
	printf("signal SIGKILL= %d\n",SIGKILL );
	printf("signal SIGSEGV= %d\n",SIGSEGV );
	printf("signal SIGPIPE= %d\n",SIGPIPE );
	printf("signal SIGALRM= %d\n",SIGALRM );
	printf("signal SIGTERM= %d\n",SIGTERM );
	printf("signal SIGUSR1= %d\n",SIGUSR1 );
	printf("signal SIGUSR2= %d\n",SIGUSR2 );
	printf("signal SIGCHLD= %d\n",SIGCHLD );
	printf("signal SIGCONT= %d\n",SIGCONT );
	printf("signal SIGSTOP= %d\n",SIGSTOP );
	printf("signal SIGTSTP= %d\n",SIGTSTP );
	printf("signal SIGTTIN= %d\n",SIGTTIN );
	printf("signal SIGTTOU= %d\n",SIGTTOU );
}
