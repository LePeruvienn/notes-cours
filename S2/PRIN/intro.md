---
title: INTRO
---


# PRIN

- Cunit
- Valgrind
- git

Tuto sur : dimtri.watel.free.fr

# 1. Gestion du code

## `.h` `.o` `.c` Chaine de compilation ...


```c
typedef int nombre;
nombre fact(nombre n);
```

Ici en fait on créer un nouveau type `nombre` qui fait référence au type `iny`
- En gros `nombre == int`


**Un fichier `.h`** est une interface (ou header) dans laquelle on indique:
- Des prototypes de fonctions
- des définitions de type

En gros ça permet d'importer aussi des fonction, variable, ... dans d'autres fichiers `.c`/

**Un fichier `.c`** c'est la qu'on définis les fonctions du fichier `.h` associé.

Afin de faire ça dans le fichier `.c` on fait :

```c
#include "factorielle.h"
int main(void) {
    printf("%d\n", fact(3));
}

```

Ici on importe toutes les fonction déclarer dans le fichier `factorielle.h`, afin de pouvoir les utiliser dans le `main.c`.


On peut précompiler les fichier `.h` afin d'otbtenir des fichier `.o` avec la commande

```bash
gcc -c fac.c
```

**Compilation séparer** :
On peut séparer le code en différents modules/bibliothèques :
- Comment ça on peut commencer à coder séparement en précompilants les header.

**Fichiers `.o`**
C'est un fichier *objet*. C'est la précompilation d'un fichier `.c` qui n'est pas executable.
- Le but est ensuite de les "linker"/lier entre eux afin de créer un programme complet executable.

```bash
gcc -Wall -Wextra -std=c99 fact.o main.o -o testmain
```

**Exemple de chaine de compilation** :

```bash
gcc -Wall -Wextra -std=c99 -c main.c -o main.o
gcc -Wall -Wextra -std=c99 -c fact.c -o fact.o
gcc -Wall -Wextra -std=c99 fact.o main.o -o testmain
```

## MakeFile

C'est un fichier qui permet de lancer des script de compilation (ou autres) de manière automatique.

Il peut être utiliser pour :
- Compiler,
- Faire des tests
- Néttoyer le projet

**Exemple** :

```MakeFile
CC = gcc -Wall -Wextra -std=c99

testmain: fact.o main.o
    $(CC) -c $< -o $@

fact.o: fact.c fact.h
    $(CC) -c $< -o $@

main.: main.c main.h
    $(CC) -c $< -o $@
```

- On peut créer des variable comme en bash avec et on peut ensuite les utiliser avec `$(VAR)`.
- Chaque nom suivie de `:` est appelé une **règle**.
- ce qui après et sur la même ligne sont les autres règle qui doivent être executer avant pour executer cette règle, ex: `fact.o: fact.c fact.h`.

**Varaibles spéciales** :

- `$@` : Le nom de la règle, *(cible)*
- `$<` : C'est le nom de la première dépendante, *(source1)*
- `$^` : Toutes les dépendances, *(source1, source2, ...)*

**Commandes** :

- `make -p` indique d'abord toutes es règles qu'il va executer
- `make -n` indique uniquement les commandes qui seront utiliser sans les executer
- `make -f file` utiliser `.file` comme Makefile

**Header guards

`fichier.h` :

```h
#ifndef FICHIER_H
#define FICHIER_H
int foo()
{
    ...
}
#endif
```
Ici les `#ifndef, # define, ...` sont ce qu'on appelle des "*macro*".
Ils sont utiliser ici en tant que gardient afin de faire en sorte que lorsqu'on importe un fichier `.h` dans plusieurs fichier `.c` différents, les variables et fonction ne sont pas définis plusieurs fois (ce qui cause alors une érreur de comile)

En fait le compilateur C est un peu "con". Quand tu fait un `#include fichier.h`, il copie l'entierté du fichier au dessus de ton fichier `.c`, donc si tu le fait sur plusieurs fichier `.c` alors tu va définir plusieurs fois les même variables (ce qui est pas cool et cause une érreur de compil).

Ajouter des *header guards* permet de assurer la définitions des varaibles/fonctions du fichier `.h` qu'une seule fois.

## Doxygen : Documenter du code

C'est un outils qui permet de génerer une documentation du code en page web ou pdf automatiquement à l'aide des commentaire de celui-ci.

- Il faut donc : Commenter le fichier `.h` et `.c` !!! (sinon bas Doxygen peut pas génerer la doc)

COMMENTER DES LE DEBUT !! (sinon valentin pas content 😠)

**Exemple de commentaires** :

```c
/**
 * \brief Clacule la factorielle de \a n
 * \param n Un entier positif
 * \return La fonctorielle de \a n
 */
void fact(int n);
```

**List de tout les attribut de fonctions** :

- `\brief`
- `\detail`
- `\param k` : définir le paramètre `k`
- `\return`
- `\a` : met le mot qui suite en italique
- `\b` : met le mot qui suit en gras
- `\attention`
- `\file` : **a mettre au début du fichier**, permet de décrire un fichier.


**Créer la documentation (sous UNIX)** :

1) Créer le fihcier de configuration

```bash
doxygen -g
```
Créer un fichier nommé `Doxyfile`

2) Configurer le fichier

Changer les paramêtre suivants :

- `PROJECT_NAME`
- `HAVE_DOT` : NO
- `INPUT` : Dossiers ou sont les sources commentées

3) Créeer la documentation

```bash
doxygen Doxyfile
```

Créer deux dossiers `html` et `latex` avec la doc dedans


**Architechure des fichiers du projets**

- `src` : les fichier `.c`
- `header` : les fichier `.h`
- `obj` : les fichier précompiler `.o` *(ON NE LE MET PAS SUR LE GIT)*
- `bin` : l'executable *(ON NE LE MET PAS SUR LE GIT)*
- `doc` : ou ya les fichiers du doyfile
- `test` ?

## Valgrind : repérer les fuites de mémoire (et autres érreurs)

Pour utiliser valgrind :

```bash
valgrind --leak-check=full --track-origins=yes file

# Il ya aussi pour faire du profiling mémoire, voire les métrique de la consommation de mémoire du programme
# ça génère un fichier massif.out, on peut le dire comme un .txt, ou sinon avec ms_print massif.out, pour avoir un debreif de profiling
valgrind --tool=massif file
```

Pas oublier de compiler avec `-g` !

Si t'es le goat tu as :

```
All heap blocks were freed - no leaks are possible
ERROR SUMMARY: 0 erors from 0 contexts (suppressed: 0 from 0)
```

Sinon ça veut dire t'as troll, et que t'as des leaks (tu n'as pas free tout tes ptr)
Force à toi 🫡


Avec Valgrind on peut aussi trouver d'autres erreurs comme :

- lecteurs/écriture invalide (typiquement pour un tableau)
- utilisateur de la mémoire non initialiser
- libérer un ptr plusieurs fois

## GDB : debogguer son code

Executer la commande avec le binaire compiler avec `-g`

```bash
gdb a.out
```

ça ouvre l'interface de commande de gdb, voici la liste des commandes

- `run` : lancer le programme
- `q` : quitter gdb

## CUNIT

Un bon test ne dépend pas des fichiers sources uniquements des interfaces.
- Il peut alors être rédiger en meme temps que la spécification du projet.
- Il doit être en accord avec la doc.

**Comment tester ?**

Exemple avec **CUnit** :

```c
#incldue "CUnit/CUnit.h"
#incldue "CUnit/Basic.h"
#incldue "factorielle.h"

void test_v1()
{
    CU_ASSERT(fact(3) == 6);
}

void test_v2()
{
    CU_ASSERT_EQUAL(fact(3), 6);
}
```

Pour compiler et lancer :

```bash
gcc test.c factorielle.o -o test -lcunit
./test
```

# 2. Gestion de projets

Flemme 😴

# 3. Consignes

- Tout le monde doit coder un minimum
