# Introduction et rappels de la statistique

## Utilisation des données

- Vente, marketing
- Assurance, Santé
- Ressources Humaine
- Médical pharamceutique
- Banque et finance
- Aréo-Spatial
- Ingénieurie
- La génétique humaine

## Histoire

Avant 1900
- Ancienne méthode ..

Statistique moderne :

- 1901 : Pearson
- 1920-1930 : Fisher développe annalyse de varance et la base des statistique inférentielle moderne
- 1940s : ...

Apparition des **données numériques** entre 1950 et 1800

**BigData & analyses avancée** (1990-2010)
- 1900 : Data mining
- 2000 : internet et analyse du web
- 2010 : ère du Big Data, machine learning et l'IA commencent à dominé l'analyse prédictive

**2020 à aujourd'hui**
- Croissanee des analyses pilotées par l'IA, deep learning
- Science des données


## Domaine d'application

**Science de la vie**
- MOdèle de durée de vie, dynamique des populations

**Marketing**
- Fouille de données (data mining)
- Voir les tendances du marché, quelle moment faire une action
- Espionner les clients


## Pourquoi faire ?

- Donner quelques outils courramenter employé en sttistique pour traier les données
- Extriare le maxixum d'information de ce tableau de données
- Utliser le données pour prendre des décisions plus intéligente

En gros on veut synthétiser eet structurer l'information contenue dans des "tableaux" multidimensionnel (lighe $\times$ colonnes)


## Typologie d'analyse

**Exemple : mesurer la dépendence entre la variable $X$ et $Y$.**

Il y a plusieurs type de dépendance :
- **dépendance** : $Y = f(X)$, on mesure l'influence d'une des variable sur l'autre
- **interdépendance** : $f(X,Y) = 0$


## Techniques

- Régression
- Multiple Analysis of Variance (MANOVA)
- Canonical correlation
- et d'autres encore ....

## Les méthodes

**Analyse des relations entre plusieurs varaibles**

On souhaite savoir quelles sont les varaibles liées entre elles sans qu'aucune des variables ne soit vraiment priviliégiée

- Toutes les varaibles sonst quantitative : **Analyse en Composante Principale** (ACP)
- 2 variables sont qualitatives : **Analyse Factorielle des Correspondaces** (AFC)
- $p \ge 3$ variables sont qualitative : **Analyse des Correspondances Multiples** (ACM)

## Analyser les données

Étapes princiales : 

1. **Identifaication de la question**
2. **Collecte des données** : la façon dont on les collecte, qu'est ce qu'on collecte
3. **Structuration des données** : 
4. **Analyse des donnés** !
5. **Présentation et interprétation des résultat**

## Etude d'un ensemble de données

Une étude d'un emselbe de données peut se décomposer en 3 étapes

1. **Une étude exploratrice** : à l'aide d'outils préviliagante les reprétentation graphique. 
- Pour se familiariser avec les données

...

## Types de l'analyse des données

**Descriptive** : qu'est ce qui s'est passé ()
- Peu complexe, peu de valeur

**Exploratrice** : Pourquoi c'est arrivé
- Un peu plus complexe, un peu plus de valeur

**Prédictive** : Qu'est ce qui est suceptible d'arriver
- Complexe et avec de la valeur

**Prespective** : Que devont nous faire
- Très complexe et avec beaucoup de valeur



## Logiciels

Payant :
- SAS
- SPAD
- ..

Ou des logiciels gratuit : language de programmation pour la maniuplation de données comme **Python**, **R**.

Il est bien de connaitre les logiciels mais le plus important c'est de comprendre la méthode utiliser et le fond de la réfléxion.

Quand on comprend vraiment ce qu'on fait après c'est très simple de passer d'un logiciel à un autre !

## Quelles compétences ?

- quelle est précisement la question posée ?
- quelle méthode utiliser avec quelles limites ?
- comment la metre en oeuvre ?
- comprendre les sortie du logiciel utilisé
- quelle décision ?

## Statistiques Descriptive

Statistique descriptive regroioupe les méthode dont l'objectif principale est la description des données étudiée.

- synthétiser les données
- Les présenter de façon graphique ou non
- Le calcul des résumé numériques (variance, moyenne, écart-types, ...)

Les termes **statistique descriptique ou exploratrice et analyse de données sont quasiment synonyme**

## Statistique inférentille

C'est quand on prend un échntillon pour essayer de prédire ou de quantifié un de plus grand groupe de valeurs.

C'est quelque chose d'utilisation notamment sur des statistique sur la population ou autres.


Souvent en fait on utilise les **statistique descriptive** sur l'échnatillon, afin de les utiliser pour faire des **stastisque inférentille** pour prédire ensuite les données du plus grand groupe.

## Pourquoi on as besoin des statistique ?

Toute étude statistique nécessite des choix fondamentaux :

- transformations des données
- sélection de variables
- choix de méthodes
- valeurs des options et des paramètres de ces méthodes

**C'est pas prudent de laisser le logiciel choisir pour vous!! Ce ne sont pas des choix anondin !!!!**

## Terminologie

- **Population** (statistique) : c'est l'ensemble (mathématique concerné par l'étude statistique. 
- **Individu** (unité statistique) : Tout élément de a population
- **Echantillon** : Sous ensemble de la population
- **Enquête** : Opération concernant à observer/mesurer l'échantillon/population.
- **Variable** (statistique) : 
  - `quantititive` : Variable numérique : (poid, taille)
  - `qualitative` : Variable non numérique (poste, genre)

## Typologie des variables

**Données** (discrète ou continue)
Contient des variables qui sont **qualitative** ou **quantitative**.

## Variable qualitative

Exemple : on demande aux élève d'une classe qu'elle est leurs chaine de télévision préféré

- **Variable qualitative nominales** : les variables qui coresseponde à des noms, il n'ay pas d'ordre précis (sexe, langues parlé)

- **Variables qualitative ordinales** : celles qui contienne un ordre (ex: niveau de satisfaction, A+, A, B, C)

Ici c'est nominale, car leurs classement ne définis rien (pas d'ordre de supériorité/inferiorité)

- **Fréquence absolue** : le nombre totale de personne ayant pris cete modalité (par ex: 4 personne ayant chosi TF1)

- **Fréquence relative** : pourcentage de personne ayant choisi une modalité (ex: 50% de personnes qui ont choisi TF1)

## Enconding les variables catégoricales

On peut utiliser un "*bitmask*"
- Cheveux brun `1, 0, 0`
- Cheveux blond `0, 1, 0`
- Cheveux roux `0, 0, 1`

Ou juste une valeur numérique
- Note C : `0`
- Note B : `1`
- Note A : `2`

## Représentation graphique

- **Courbes** (souvent utilisser avec des variables quantitative continue en utilisation la fonction cummulative)
- Camenbert
- **Batons** (souvent utiliser avec les varaibles quantitative discrète)
- ...

Pour les **variables quantitive continue** on peut aussi le découper en "classes"s.

Par exemple dire Entre 0-1 il ya 50% des personne te 1-2 il ya 50% encore.

ça nous permet aussi alors après de le mettre en histogramme, (cf: [lol rank distribution](https://plarium.com/wp-content/uploads/2024/12/league-of-legends-rank-distribution-1.webp))

### Histogramme

Le calcul du nombmre de classe pour un échnatillon de taille $n$ :

- **La règle de Sturges** :
  - nb. de classes $= 1 + log_2(n) = 1 + \frac{ln(n)}{ln(2)}$

- **La règle de Yule** :
  - nb. de classes $= 2.5 \sqrt{n}^4$





