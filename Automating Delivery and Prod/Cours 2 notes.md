/FS structure = la structure des fichiers


Directory = a file containing a list of files

Un fichier est composé d'une list de bloc et de ses informations
La list de block est la liste des différente partie du disque ou sont stocker les information du fichier.

I-node: La structure de fichier linux (qui est comme on a dit au dessus)

La structure de nos dossier sont comme un arbre (mais c'est pas forcément un arbre)

Absolute path = starting in the file system root
Relative path = starting in working directory

Symbolic link = a seperate file containing the path of the linked file
Hard link = a directory entry

**Liste de différente entrées et sorties**
- standart input = stdin, deault from keyboard, descriptor 0
- standart output = stdout, default to screen, descriptor 1 
- standart error = stderr, default to screen descriptor 2

Le but est de maitriser ces flow pour le rédiriger !!

*exemple de redirections*

On va pipe des commandes dans des fichiers

```
sort <f1 > f2
```
Sort the line of f1 and put them in the file f2

```
wc -l <f2
```
count the word in the file f2 and print the resulet in stdout

`<` = input
`>` = output

Le problème de ces 2 commande c'est qu'on est obligé de créer un fichier pour pouvoir le lire et compter les ligne alors qu'on pourrais juste faire un pipe

```
sort <f1 > f2 | wc -l
```



Regular expression (RegEx) = a pattern describing a set of strings
*en gros ce qu'on utlise pour grep pour trouver un certain type de fichier*

ex:
- `ls *.jpg` listez tout les fichier qui termine par .jpg
- `grep "sys[0-9]" <f1` affichier tout le mot qui commence par sys puis un chiffre
- `sed "s/^a/A/" <f1` remplacer tout les a du début de la ligne



Tout les caractère spéciaux sont considérer comme spécial dans e RegEx et pas commme des caractère normaux


**!! Tout les trucs sur comment utilisé les caractère spéciaux dans le RegEx sont dans les diapo !!**






