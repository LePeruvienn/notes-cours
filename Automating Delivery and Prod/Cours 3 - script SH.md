
## Shell

Shell = command interpreter

Ecris en ASCII

**SHELL IS A INTERPRETED LANGUAGE**

### Shells type
- sh : original unix shell
- bash : GNU Shell taht include shell
- csh : C shell
- tcsh : TENEX C SHell
- ksh : Korn SHell


```sh
cat /etc/passwd | grep agata
```

Affiche lles informations leurs l'utilisateur agata, affiche aussi le terminal uitlisé par défault !


### Bash config files
- /etc/profile
- ~/.bash_profile
- ~/.bashrc

### Variables

**Global variables**

```sh
printenv
```

This comand show all the global variable of the current terminal

We can have the global variables
- PATH = ....
	- Path show the array of the path where all the program of the commands is saved

**Local Variables**

Local are only avaible in current shell


**Type of variables**
- Strings
- Integers
- Constants
- Arrays


### How to use variables

```sh
> first_name="Harry"
> echo first_name
first_name
> echo $first_name
Harry
```

Never put `spaces` between `=` !!!

Space are meaningfull in Shelll

On utilise `$` devant des mot pour dire qu'on veut récupérer la valeurs d'une variables et non pas quand on veut lui mettre une valeur !!!


### Quoting

- `\` remove special meaning
- `'` preserve litteral value
- `"` oreseve litteral value except for `$`, backquote and `\` 

exemple caractère spéciaux

```sh
> date=2015
> echo $date
2015
> echo \$date
$date
> echo `$date`
$date
> echo "$date"
2015
```

```sh
> whoami
agata
> echo "Je suis `whoami` "
Je suis agata
> echo "Je suis \" `whoami` \" "
Je suis "agata"
```

### Expansion

Brance expansion
```sh
> echo sp{el,il,al}l
spell spill spall
```

```
cd ~
```

This command make you cd to your /home

**Arithmetic expansion**

```sh
> echo $((3*4))
12
> echo $[3*4]
12
```


**Command subsitution

```sh
> echo "Je suis $(whoami)"
Je suis agata
```



## Bash script !

Bash script is ASCII files with command inside

On doit rendre les fichier .sh executable
```sh
chmod +X
```

The first line of every bash files

```sh
#!/bn/bash
```

C'est le lien du programm qui va lancer le fichier

To run a executable :
```sh
./monexecutable
```


**Exemple d'un script**

```sh
#!/bin/bash

who # Affiche la commande who
VALUE="9" # Met la constante VALUE à 9
echo "THis is a number: $VALUE" # Affiche une phrase avec la constante
```

```sh
chmod u+x ./script.sh
```
Donne le droit d'executation que à moi ! *si je met pas de u il le donne à tout le monde*


**IL YA DES VARIABLES DEJA ASSIGNER SPECIAL**

- `$0` = script name
- `$1, $2` = valeur mit au début de l'execution pour les mettre dans le scrupt
- `$#` = nombre de paramètres

### Comment commenter son script

ex:

```sh
#!/bin/bash
# Parameters:
# $1 = name of user
# $2 = ....
# ....

...
```

Toujours mettre les paramètre au début du script


### Conditional statement


```sh
if TEST-COMMANDS
then CONSQUENCES
fi
```

On peut aussi le faire sur une ligne mais il faut précisé la fin avec `;`
```sh
IF TEST; then CONSEQUENCES; fi
```

Comment faire des elif
```sh
if TEST
then CONS
elif MORE-TEST
then MORE CONS
else ALTERNATIVE
fi
```


Exemple switch cases
```sh
#!/bin/sh

FRUIT="kiwi"

case "$FRUIT" in
   "apple") echo "Apple pie is quite tasty." 
   ;;
   "banana") echo "I like banana nut bread." 
   ;;
   "kiwi") echo "New Zealand is famous for kiwi." 
   ;;
esac
```


### Test commands


**VOIR LE DIAPO POUR TOUT VOIR !!**

 - [ -e FILE ] : True if file exist
 - [-f FILE ] : True if it exist and is a regular file
 - [ -d FILE ] : True if file exist and directory
 - [ -h FILE ] : True if exist and is a sympolic link
 - [ STR1 == STR2 ] : True if equals
 -  .... (VOIR DIAPO 3 PAGE 16) ...

Toujours mettre les condiations dans des `[]` !!
Il est imortante de mettres des `spaces` entre les variable et les corchet !!!! *sinon ça marche pas quoi*


Conditions example
```sh
if [ $num -gt 150]
then echo "Your number is too big"
fi
```

```sh
if [ $[$year%400] -eq 0]
then echo "This is a leap year"
else echo "This is not a leap year"
fi
```

### Loops

```sh
for NAME in LIST
do COMMANDS
done
```

```sh
while CONTROL-COMMAND
do COMMANDS
done
```

```sh
until COMMANDS
do ...
done
```

**EXEMPLES**

Diapo 3 page 19 

Ici prend une valeurs dans le clavier puis je la décrémente de 1 jusqu'a atteindre 0
```sh
read i #Read var form keyboard
while [ $i -gt 0]
do
	echo "i = $i"
	i=$[$i-1]
done
```

