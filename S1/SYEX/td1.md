# Systèmes d'exploitation

**C'est quoi ?**
- C'est un logcielles qui permet de faire le lien entre le hardware et le software d'une machine.

**Exemple de système d'exploitations** :
- Linux, MAC OS, Windows, Android, IOS.

## Organisation

 1) **Materiel** : CPU RAM controleurs et périphériques
2) **Moniteur** : Petit programmes en ROM
3) **Noyeau** : gère et donne accès au materiel
4) **Système** : couche de standarisation
5) **Applications**

## Permissions

Les système de protections sont pabasé dsur des **users (UID)** et des **group (GUID)**.

Droit sur les fichier et les dossiers : **xyz**. 3 nombre de 1 octet :
- **x** : read
- **y** : write
- **z** : execute

*Exemple : 777*

Pour donner des droits :

```shell
chmod 755 tutu
chmod 640 tutu
```


On peut avoir des raccourci pour appliquer des modification de permissions à des personnes :
- On sélectionne notre groupe de personnne : `a` pour "all" et `g` pour "group"
- On fait `-` pour retirer des permissions ou `+` pour en accorder
- On dit quelles permissions on vat ajouter ou enlever : `r` , `w` , `x`.
```shell
chmod a-x
chmod g+x
```

## Chemins ds fichiers

On range les fichiers dans des dossiers qui sont représenter par des `/`

Exemple :
```
Dossier1/Dossier2/fichier.txt
```

- Ici on va dans le  dossier `Dossier1` pour dans le  dossier `Dossier2`, afin d'acceder à `fichier.txt`.

Il y a aussi des chemin dit "spéciaux" :
- `../` : remonter au fichier au dessus
- `./` : dossier ou l'ont se situe actuellment
- `~/` : notre dossier `/home/` sous linux


## Executions de programme

Quand on execute un programme -> cela créer un **processsus**.

Un **Processus** possède : 
- **PID** : identifiant unique de ce processus.
- **UID**, **GID** : Identifiant d'utilisateur det groupe
- **Arguments** : les arguments qui lui ont été donné à l'execution du programme
- **Variable d'environnement**  (ARG0, ARG1, ...)
- **Flux d'entrée** (ENV0, ENV1, ...)

## Job controle

Un prg

## Le Shell

Le **Shell** est un programme dont les fonction sont :
- Permet d'intéragir avec celuici
- Lui demander d'executer des actions

### Principales expansions
- `$vname` La valeur de la variable `vname`
- `${vname...}` La valeur déduite `vname`
- `$$` Le PID du Shell
- 