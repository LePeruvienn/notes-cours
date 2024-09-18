
# Suite Script SH

```sh
while true; do
	echo -n "Enter an age below 19, 0 for exit: "
	read age
	case $age in
		0)
			echo "See you ! "
			break;;
		[1-2]
			echo "baby"
		*) ...
```



## Shift parameters

```sh
while [ "$1" != "" ]; do
	echo "Parameter $i  = " $i
	shift # This shift all the list the parameter that have been enter
	i=$[$i+1]
```

Un shift c'est quand une décale une liste en elevant le premier élément

```c
# Exemple de shift pour une liste de taile 3
[1,2,3] => shift => [2,3, null]
```


## Functions

```sh
f1 () { # Les paramètres ne sont pas mit dans la parenthe mais mit dedans comme si c'était un script
echo "The function received parameter: $1" # On récupère le premier paramètre donnée
return 1
}

# Exemple d'utilisation de la fonction
f1 hello # ici on utilise la fonction f1 avec en paramètre $1 hello

echo "The function returned $?" # La varaible $? contient le résultat de la dernière fonction appelé, c'est comme ça qu'on peut récupérer le "return" des fonctions !"
```



**!! Réviser le cours S4 virtualisation ** askip


---

# CI/CD

=> **Continius Integration / Continius Delivery**

Souvent utiliser avec les outils de versionning GIT

C'est quelquechose qu'on fait souvent quand on est développeur donc il faut l'automatiser


On peut parler de CI/CD **Pipeline**

C'est la liason entre note code local et le dépot distant,

Pendant la **Pipeline** on fait des tests et on déploie aussi notre code (par exemple on met notre site internet en ligne)

### Why CI/CD

- **Higher quality** : moins de bugs, et possiblité de revenir en arrière, test automatiques, ...
- **Low risk realease** : On peut toujours revenir en arrière
- **Lower costs** : C'est pa sles humain qui font des test, on gagne du temps
- **Better products** : L'équipe se concentre plus sur le dev, et pas sur la realease
- **Time to market faster** : Plus rapide à déployer, donc plus à realease
- **Happier team** : On fait des realease plus souvent donc on stresse moins pour le rendu

**Il y a beaucoup beaucoup beaucoup d'outils qui peuvent être utiliser pour effectuer ces taches** 

### Why with GItLab

Nous on va utiliser GitLab pour faire ça ! Car Git l'intègre déja par défault, on a pas besoin d'installer de librairie on plus (et c'est open source)


## CI/CD Components

- **Job** : action que tu veut faire
- **Stage** : Groupe d'action qu'on veut faire 
- **Pipeline** : Liste de Stage 
- **Runner** : Les programme qui vont faire les jobs

### Containerization

- **Container**
- **Containerization**
- **Docker**  a set of PaaS (Platform as a Service)
- **Dokcer images** : read only template to build containers
- **docker registery** : a repository for Docker images


## CI/CD Config on GIt

Il faut créer un fichier `.yml` qui s'appelle souvent :  `gitlab-ci.yml`

C'est dans ce fichier ou on met toutes les différents jobs et stage, ... Mais aussi des informations sur l'image qui va être utiliser pour effectuer ces taches

(Exemple de fichier de config sur le diapo)

*Exemple que j'avais fait perso d'un fihcier .yml*
```yml
name: Deploy # Nom du stage

on:
  push:
    branches:
      - main

jobs: # Défénitions des jobs
  build:
    name: Build
    runs-on: ubuntu-latest # Qui est le runners du jobs

    steps: # Différente étapes à faire pour le jobs
      - name: Checkout repo
        uses: actions/checkout@v3

      - name: Setup Node
        uses: actions/setup-node@v3
        with:
          node-version: '16'  # Specify the Node.js version if needed

      - name: Install dependencies
        uses: bahmutov/npm-install@v1

      - name: Build project
        run: npm run build

      - name: Upload production-ready build files
        uses: actions/upload-artifact@v3
        with:
          name: production-files
          path: ./dist

# ... Fichier pas complet ça continue
```

Ici c'est un script de déploiement de mon site internet sur GitHub pages
*Lien du fichier complet*
https://github.com/LePeruvienn/react-project/blob/main/.github/workflows/deploy.yml




## Syntax YAML

Ce type de fichier à été créer pour faire des fichier de configuration qui peut être facilement lu par des humains

- **Comments** : `#` 
- **Indentation se fait avec des espaces**
- **Lists** : `[Mary, Jhon]`
- **Assiosative Arrays** ...


## CI/CD Config file

C'est le développeur qui créer le fichier `gitlab-cli.yml`

Quand le fichier de configuration va être executer ?
- Des que tu fait un chagement sur ton dépot distant (que quand tu push)

Ou doit être placé le fichier?
- Dans la branch main et dans les branch dev

## CI/CD orchestration

- Stages are executed in sequence (On fait chaque stage un par un)
- Les jobs sont executé en praralèlle
- Quand tout les jobs d'un stage sont terminé, on passe au stage suivant
- Si il ya des erreur la pipeline fail et on renvoie les erreur (Carrément ça t'envoie un mail quand ça marche pas)


**Best practice in Git :**
- **New feature is needed** => create a branch
- **New buggs need fixed** => create a branch
- **When ready, create a merge request !**



## CI/CD Variables

- To control behavior of jobs
- To store values you want to re use
- To avoid hard-coding values in files

**Variables prédéfinis**
- I**nfo utilisateur :** *GITLAB_USER_NAME ; GIT_LAB_USER_LOGIN ; GIT_KAB_USER_ID*
- **Info branch :** *CI_DEFAULT_BRANCH*
- **Info commit :** *CI_COMMIT_BRANCH ; CI_COMMIT_SHORT_SHA ; CI_COMMIT_TIMESTAMP*
- **Info merge :** *CI_MERGE_REQUEST_SOURCE_BRANCH_NAME ; CI_MERGE_REQUEST_TARGET_BRANCH_NAME*
- **Info pipeline :** *CI_PIPELINE_SOURCE (values : push , merger_request, ...)*
- ... et plein d'autres

**Définir des variables**

On les définie en utilisant le mot `variable`, elles sont sauvegarder dans le fichier `.gitlab-ci.yml`

IL NE FAUT PAS METTRE LES DONNES SENSIBLE DEDANS !

Les données sensible doivent être mit dans les paramètre du projet

ex:
```yml
variables:
	GLOBAL_VAR: "A global var" # On peut y avoir accès depuis tout le fichier
	
job1:
	variables:
		JOB_VAR: "A job var" # On y a accès que dans le jobs on on est 

```


## CI/CD Rules

Utilise souvent des variables

ELle mpermettre de définir quelle jobs s'execute dans quelle pipeline


(Voir exemple dans le diapo 4 page 15)

Pour allez plus loin dans la dernière diapo y a des vidéo

