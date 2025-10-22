# SYSEX - TD2

### Comment executer un ficher shell ?

```shell
#!/bin/bash

echo -n "  " Hello
echo World
```

- **Méthode 1** : lancer le script avec bash -> `bash hello.sh`
- **Méthode 2** : rendre le script executable -> `chmod +x hello.sh` puis `./hello.sh`
- **Méthode 3** : passer le script en stdin ->`bash < hello.sh`

**Alternative : Syntaxe**

```shell
if cmd-cond ; then
    ...
else
    ...
fi

### OU

if cmd-cond
then
    ...
else
    ...
fi

### En fait on est obligé d'écrire le `;` si on met le then sur la meme ligne que le if
```


Quand le code de retour d'une **commande condition** est 0 alors c'est **true** sinon alors c'est **false**.

```shell
if cmd-cond ; then
    ...
else
    ...
fi
```

Exemple : Tester si le fichier contient main

```shell
if grep -q main file ; then
    echo main dans file
else
    echo pas de main dans file
fi
```

Pour écrire le message d'erreur dans le stderr :

Par exmple ici on envoie un texte random dans le stderr

```shell
echo "Erreur : vous avez une erreur" 1>&2 
```

Et ça jsp ce que ça fait

```shell
grep -q main file 2> /dev/null
```

**La fonction `test`** :

La fonction `test` permet de tester une commande condition.
- Elle retourn 0 si tout va bien eet autres chose si il ya une erreur

```shell
test a == 2
```

On peut l'utisé avec l'opérateur `&&` pour executer 

```shell
test a == 2
```

**Comment faire des switch case en shell** :

```shell
case mot in

    chien)
        echo "woauf"
        ;;
    chat)
        echo "miaow"
        ;;
    [0-9])
        echo "Vous avez entrez un chiffre de 0 à 9"
        ;;
```

C'est un siwtch case classqiue sauf qu'on peut aussi utilisé les expréssion réguilier pour filtrer la variable passer en paramêtre (comme je l'ai fait avec `[0-9]` ou je check si il ya un nombre entre 0 et 9).


Boule **while**

```shell
while cmd-cond ; do
    ...
    ...
done

### OU

while cmd-cond
do
    ...
    ...
done

# En fait on peut écrire les deux, on est juste obligé de mettre le `;` si on écrit le do sur la meme ligne.
```


Les boucles for :

```
for v in str-list ; do
    ....
done
```

### Ecrire des conditiosn

Par exemple sur des strings

- `-n str` check si str est vide
- `str == str2` check si str1 vaut str2 (ou `!=` pour dire pas égale)
- `str \< str2` str1 est infireur à str2

Autres opérateurs :

- `-e` : Le fichier existe.
- `-f` : Le fichier existe et est régulier.
- `-d` : Le fichier existe et est un répertoire.
- `-h` : Le fichier est un lien symbolique.
- `-r` : Le fichier existe et peut être lu.
- `-w` : Le fichier existe et peut être écrit.
- `-x` : Le fichier existe et peut être exécuté.

Opérateurs booléens :

- `expr -o` : '*ou*' (opérateur booléen).
- `expr -a` : '*et*' (opérateur booléen).


### Autres commandes

On les appelles les *built-in commands* c'est toutes les commandes déjà intégré à shell (cd, ls, export, ...).

La commande `exec` :  Replace l'unité d'execution du processus shell, par celle de l'executable, cmd, et es arguments
- En fait ça permet de remplacer le porcessus shel par la commande qu'on execute, en vrai c'est stylé.


La commande `exit` : Permet de quitter le shell avec un paramêtre (0 ou 1 pour préciser une code erreur ou si tout est OK).


La commande `read` : Permet de lire le contenue d'un stdin afin de de savaugarder sa valeurs dans une variable shell.
- Exemple : `read v1` : va ouvrir le stdin, puis va mettre la valeurs rentrée dans la variable v1. Si j'écris "*caca*" alors `echo $v1` affichera "*caca*".


### Arguments

Quand on lance un script shell on récupère les arguments entrée
- Exemple `./script arg1 arg2`.

**Mots clés lié au arguments dans un script shell : **
- `$#` : Le nombre d'arguments.
- `$0` : Nom de la commande.
- `$1` : Premier argument.
- `$2` : Deuxième argument.
- `$i` : i-ème argument.
- `$`* : Liste des arguments.
- `"$@"` : La liste des arguments séparée par un espace.

Tout ces mots clé sont utilisé dans les scripts afin d'utilsier les arguments entrée (en gros c'est utile de zinzin).


On peut utilisé aussi le mot clé `shift` pour supprmier un arguments de la liste :

```shell
s=0
while test $# -gt 0 ; do
    c=$[$s+$1]
    shift
done
```

Ici par exmeple pour chaque arugment on l'ajoute à s.
Ici bas besoi de parcours tout les arugment, on utise toujours le premier on le shift afin de le supprimer et de le passer au suivant (dsl j'ai trop mal expliqué 💀)


**La commande `set`** :

Permet de mettre des valeurs dans des arguments
- Par exemple ici on veut mettre 5 par défault à la valeurs du premier arugment (si il est vide)

```shell
test $# == 1 && set -- 5 "$1"
```

### Création de built-in commands

On peut créer des commandes avec l'arguments `function` :
- Elle sont seulemnt utilisable ou on les as définis (donc que dans ton script souvent)

```shell
function cmd()
{
    ...
}
```

### Debug

On peut lancer un script shell en mode debug !

```shell
bash -x cmd arg1 arg2
```

Il faut juste ajouter `-x` à la premirère ligne du script qu'on veut debug

```shell
#!/bin/bash -x
```

### Espace dans les expansions

```
p="bee\gnat"
if test -d $(dirname $p)
```
- **OK** : on fait `dirname de bee\gnat` tout marche bien

```
p="bee\gnat gnu"
if test -d $(dirname $p)
```
- **ERREUR** : on fait `dirname de bee\gnat gnu` la fonction prend que 1 arguments !! (ouais l'espace te casse les couilles)

```
p="bee\gnat gnu"
p="bee\gnat gnu"
if test -d $(dirname "$p")
```

- **OK** : on fait `dirname de "bee\gnat gnu"` tout est ok 😎
