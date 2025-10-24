# SYSEX - TD3

### Couches principales

**Différents composant d'un système d'exploitation** :
Hard ware -> Kernel -> System (libs, base commands) -> Applications

- Material
- Moniteur
- Noyeau
- Système
- Appliations

### Appel système et libc

**La libc**
- Permet d'appeler des fonctions depuis l'espace utilisateur.
- Elle possède deux type de fonctions :
  - Fonctions standart, qui comporte "*modules standalone*" et *modules d'interfaces*. (Ex: `fread`, `fopen`, ...)
  - Fonctions dites "*wrapper*", elles permettent de faire des appel système en passant par la libc (Ex: `open`, `read`, ..)

**Appel système**
- Elle permet directement d'appeler des fonctions qui se situe dans l'espace noyeau (Ex: `SYSCALL`, ...)

### Espaces Virtuels

Il ya plusieurs type de registres

- **CPU** : Quelques registres.
- **PC** : Program Countr, adresse de l'instruction à exectué.
- **SP** : Stack Pointer, adresse du haut de la pile d'execution.
- **Espace virtuel** : La mémoire que voit le processeur.

**Chaque processus possède un espace virtuel dédié à lui, il comporte** :
- T1 : Segmeent text
- D1 : Segment de données
- S1 : Segment de pile

### MMU : Meomory Management Unit

**Chaque processus à son propres MMU**

- Il permet de gérer la mémoire de haque processus
- On peut auss avec elle gérer des espaces mémoire partager avec d'autres processus

## Appels Systèm

**Type de retour**
- **-1** ==  erreur
- **>0** == OK

Quand on fait des appels système il faut alors **toujours vérifier si cette appel vaut -1, notamment en C**.

L'exemple dans le diapo : TODO
```c
int main 
```

### Alogirthmes

**Lecture** :
1) Ouvrir en lecture
2) Lire le ficher et sauvegarder ce qu'on as lu dans un tampon, si il ya une erreur aller à fin
3) Quand on as fini on ferme le fichier

**Ecriture** :
1) Ouvrir en écriture
2) Ecrire ce qu'on as dans un tampon dans le fichier, si il ya une erreur aller à fin
3) Fermer le fichier

**Positionnement** : 
1) Ouvrir le fichier en mode lecture


## Les flux noyeau

**Les flux noyeau on des descripteur qui sont des ENTIERS** :

- Flux **stdin** : 0
- Flux **stdout** : 1
- Flux **stderr** : 2

**Les autres flux (fichier par exemple)** :
- `open("f1", O_RDONLY)` : recherche le 1er flux libre => par exemple 2
- `open("f2", O_RDONLY)` : recherche le 1er flux libre => par exemple 4
- `close(2)` : déssaloue le descripteur 2.

### Lecture

**Fonction** : `size_t read(int fd, void *buf, size_t count);`

- Lit `count` octets du flux `fd` et le met dans l'adresse pointer par `buf`.
- `nbl(3, t, 10)` : On essaye de lire le flux 3, dedan on lit 10 octet et on peut dans le pointeur t.
- `nbl(3, t + 10, 10 )` : Avec le plus 10, du coup on lit 10 octets, 10 octets plus loin que la dernière fois.

**Attention cette fonction aussi déplace le curseur du flux !**
- Si on lit 10 octets, alors le curseurs se déplace de 10 octets

### Ecriture

**Fonction** : `size_t write(int fd, void* buf, size_t count);`

- Essaye d'écrire `count` octets du contenu de l'adresse de `buf` dans le flux `fd`.

**Attention cette fonction aussi déplace le curseur du flux !**
- Si on écrit 10 octets, alors le curseurs se déplace de 10 octets

### Positionnement

**Fonction** : `int lseek(int fd, off_t offset, int whence);`

- Positionne le curseur du flux fd à offset octes de la position whence (en gros on se téléporte à l'ocet passer en paramêtre).
- Retourne la nouvelle position de curseurs en cas de cussès, sinon -1.

**Oui il faut faire gaffe à la position du curseur car c'est ça qui va faire ce ou est ce qu'on lit/écrit dans le fichier.**

**Constantes lié à la fonction**
- `SEEK_SET` : Position du début du fichier.
- `SEEK_END` : Position de la fin du fichier.

### Dupliquer des flux

**Fontion** : `int dup(int fd);`

- Permet de dupliquer un flux existant, et le renvoie.
- `dup(3)` : Rechercher le 1er fd libre => 2. Maitnenat le flux 3 et 2 accède au meme flux.


## Les flux libc

### Ouverture

**Fonctions** :
- `FILE* fopen(const char* fn, const char* flag);` : Ouvre un flux que le système choisi du fichier `fn` avec le flag `flag`.
- `FILE* fdopen(int fd, const char* flag);` : Ouvre le flux `fd` avec le flag `flag`.

**FLags** :
- `r` : mode lecture
- `w` : mode écriture-
- ... 


### Fermuture

**Fonction** : `int fclose(FILE* f)`
- Ferme le fichier pointer par `f`

## Lecture et écriture

**Fonctions** : 
- `size_t fread(void* buf, size_t sze, size_t nbe, FILE *f)` : Esasaye de lire les `nbe` premiers élément de taille `sze` du fichier pointer par `f` et le met dans le tampon pointer par `buf.
- `size_t fwrite(void* buf, size_t sze, size_t nbe, FILE *f)` : Essaye d'écrire les `nbe` premiers élément de taille `sze` du contenue pointer par le tampon `buf` dans le fichier pointer par `f`.
