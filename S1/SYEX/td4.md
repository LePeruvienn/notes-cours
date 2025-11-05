# Communication Inter-Processus

## Signaux

**C'est quoi ?**
- Un signal est un évement asynchrone qui est envoyer à un processus.

**A quoi servents les signaux système ?**
- Par exemple à vérouiller des resources (mutex)
- ...


**Il y a 4 traitement possible à un signal** :

1) Ignorer le signal
2) Se terminer
3) Se suspendre
4) Traitement spécifique

**Ensembles des signaux** (j'ai pas tout écris mais tkt) :

- `SIGPIPE` : Signal qui gère les pipes (`|`)
- `SIGHUP` : Quand on ferme une fenetre
- `SIGINT` : Interrupt from keyboard (`Ctrl-C`)
- `SIGQUIT` : Quit from keyboard (`Ctrl-Z`)
- `SIGKILL` : Tuer le processus (on force le processus à se fermer)
- `SIGCHILD` : Processus enfant est terminé (le but de ce signal est d'informer le parent de la terminaison du processus enfant)

**Les siganux `SIGKILL` et `SIGSTOP` ne peuvent pas être traiter ou ignorer !**



**Les signaux sont traiter que quand le programme passe en mode système**


**Envoyer un signal `int kill(pid_t pid, int sig)`** :
- Envoie le signal `sig` au processus `pid`.
- `0` en cas de succes `-1` si il y a un problème

**Fixer les gestionnaire d'un signal** 
```c
typedef void (*sighandler_t)(int);
sighandler_t signal(int sig, sighandler_t handler);
```

- Met le gestionnaire du signal sig à handler.


**Pause**
```c
int pause(void);
unsigned int alarm(unsigned int duree);
...
```

## Communication Inter-Processus

**FIFO** == First In First Out (file d'attente à un guichet) :

- **Canal de communication** : il as un taille maximal et 2 états
- **Producteurs/Ecrivains** : ceux qui écrive dans le FIFO
- **Consommateur/Lecteurs** : ceux qui lise dans le FIFO
- **Canal de synchronisation** :
  - Consommateur est bloqué si la FIFO est vide
  - Un producteur est bloqué si la FIFO est pleine

**Les différentes FIFO**
- `tty` : meme machine, flux d'octets
- `pipe` : meme machine, flux d'octets
- `pipe nommé` : meme machine, flux d'octets


### Accès aux flux des pipes

**Création d'un pipe** : `int pipe(int fd[2]);
- `fd[0]` => Sortie de la FIFO, lecture
- `fd[1]` => Entrée de la FIFO, écriture

**Création d'un pipe nommé** : `int pipe(int fd[2]);

- `mkfifo path`
- `mknod path p`

**Spécificité ouverture**
- Ouverture `RO` :est bloquante si il n'y pas d'écrivains
- Ouverture `WO` :est bloquante si il n'y pas d'lecteurs

**Spécificité de lecture** : `read(pipefd, buf, n)`
- Peut retourner une valeurs positive (`> 0`) et infernieur à `n` sans que l'ont soit en fin de flux
- est bloquant si le pipe est vide et qu'il y a des écrivains potentiel.
- renvoie `0` si le pipe est vide et qu'il n'y a pas d'écrivains.

### Accès aux flux des pipes `||`

**Spécificité d'écriture** : Une écriture avec une pipe génère un signal `SIGPIPE`


### Explication

Tout ce qu'on as vu au dessus avec les lecteurs et écrivains soit lié aux flux !
-> Par exemple si il y a un read et qu'il y a un potentiel écrivains alors on bloque jusqu'a qu'il écrive quelque chose.


## SEM : Sémaphore d'exclusion mutuelle

Un sémaphore simple, est une entité ayant un état binaire (LIBRE / BLOQUE), une file de processus de 2 fonctions.

`P()`:
- SI l'était est BLOQUE, enfiler le processus et le susprendre
- Si l'état est LIBRE, mettre l'état à boqué
- Si l'état est LIBRE, erreur
- Si l'état est BLOQUE et la file vide, mettre l'état à libre
- Si l'état est BLOQUE et la file non vide, mettre l'état à bloqué

`V()` (Permet de faire l'inverse ne gros) *dsl g pas eu le temps de noté*

**Exemple** ;
```
P(mutex) // Vérouiller le mutex
*p += 1; // Faire l'opération
V(mutex) // Libérer le mutex
```
