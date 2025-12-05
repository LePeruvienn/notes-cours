# Processus Unix

### Processus légé vs lourds

- **Processus léger** : ne fait pas allouer un nouvelle espace mémoire
- **Processus lourd** : fait allouer un nouvelle espace mémoire

## `fork` : Syntaxe

```
pid_t fork(void);
```

**Fonctionnement** :
Créer un clone du processus courant. Ce clone est un fils du processus courant. Quand on l'appel ou duplique l'espace mémoire pour le fils. Néanmoins les signaux réçu ne sont pas conserver.

**Retour** :
En cas de succès 0 dans le fils, et PID du fils dans le père. En cas d'échec -1 et errno est mis à jour (dans le père seulement)

**Exemple** :

```c
...

// Le père tourne
int pid = fork();

// Code du fils
if (pid == 0) {

    ...
}

// Si le le père continue ici
if (pid < 0) {

    ...
}
```

En fait si le pid vaux 0, alors c'est à dire qu'on est dans le **processus fils**.
Après l'executiond de celui ci on check si il ya une erreur.


## Apparté : Segments

**Mémoire virtuelle** :

- T1: Text
- D1: Données
- H1: Tas (HEAP)
- S1: Pile (STACK)
- Sys: Système

**Quand on fait un nouveau fils, on duplique tout dans la mémoire phyisque sauf** :

- T1: Text
- Sys: Système

**Quand on fait un thread on partage tout sauf la pile**

## Processus léger : Syntaxe

**Arguments**
- Pid, Flags, pile

```c
sys_clone_asm(pid, CLONE_VM|CLONE_FILE|CLONE_SIGAHND, (uchar*) malloc(SZ ...));
//                                                       ^^^^^^^^^^^^^
//                                               c'est le pointeur vers la pile qu'on lui attribut

// Code du fils
if (pid == 0) {

    ...
}

// Si le le père continue ici
if (pid < 0) {

    ...
}
```

Même fonctionnement que pour les processus lourds

## Attente

```c
// Permet d'attendre le changement de statu d'un fils et le met dans l'entier pointer.
pid_t wait(int* status)

// Permet d'attendre un PID spécifique en ajoutant un tag
pid_t wait_pid(-1, int* status, WUNTRACED|WCONTINUED)
```

**Fonction** : Attend une éveement sur un procesus fils. Et met sont statut dans l'entier pointer.


On peut décoder les valeurs du status grâce à des macro :

```c
WIFEEXITED(status)
WIFESIGNALED(status)
WTERMSIGN(status)

// On les met dans des if( ... ) pour les utiliser.
```

## Processus zombie

Les diférentes façons, pour un père de *manager** la terminaison d'un fils sont :

- Positionner le gestionnaire du signal SIGCHILD
- Faire un wait ou waitpid qui renvoie le ID du fils.


**Si le processus père meurt avant le processus fils**
-> Alors le processus enfant deviens *adopter* par le processus père du père 

(*le processus de base c'est le pid == 1 qui se nomme le porcessus init*)

## Exemple

```c
int main (int arc, char* arv) {

    int stauts pid;

    pid=fork();

    if (pid==0) {

        write(1, "hel", 3);
        exit(O);
    }

    wait(&status);
    write(1,"lo\n",3);

    return 0;
}
```


