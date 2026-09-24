# DOCKER 101

**à quoi ça sert Docker ?** 

Chez moi ça marche -> et ça marche en production ! (environnement identique)


## Comment ça se passe sans Docker

### Préparer un envrionnement de dev local

Installer des packages jusqu'à que ça marche
- touts les devs ont des postes différents
- comment garantir que ce qui est marche chez un dev marche chez un autre?
- comment garantir un cout d'onboarding minimal sur un projet ?

Frein à la scalabilité humaine de votre équipe


### Préparer un env de dev local

**Provisoning** 
- se connecter en ssh et intaller des packages.
- Ou lancer des scripts shell ou executables

Problème des scripts à executer
- on ne connait pas l'état de la machine
- c'est très vite horrible eet inmaintenable

Deux technos repondent à ce problème :

- **Ansible** : votre scripts au fromat yaml ave cdes controle pour savir executer des parties ou pas (pour peu de machine, car il faut lancer le programme sur chaque machine)

- **Puppet** : toutes les machins sont slave d'un machine principale et ont des agents qui executent les changements d'états (fait pour beaucoup de machine, les agents gère la mise en place)

### C'est quoi une app?

**Dans une app on as :**
- du code 
- un runtime vesionné
- des package versionné
- Input/Output
- une base de données
- des services tiers
- un système de fichier interne


**Qu'on lit souvent avec**
- Un OS
- des paquets avec des versions


## Docker

Souvent **Docker** est utilisé pour résoudre deux problème :
- On cherche à créer une application
- On cherche à executé une application sur une machine


