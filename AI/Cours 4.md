
# Clustering

C'est de l'apprentissage non-supervisé

=> Méthode ed'apprentissage ou on n'as pas d'étiquettes sur les données

C'est le modèle lui meme qui doit trouver une structure dans ces données, c'est lui qui les sépare en cluster.

Ex : Un modèle qui tri les images par catégorie (paysage, animals, selfie ...)


## Principe de clustering

C'est le modèle qui sépare les données pas l'humain

=> Fuzzy clustering, ou clustering flou qui permet de mettre plusieurs label à une seule entité

### Type de clustering :

- **Clustering partitif** : K-Moyennes ou K-Means
	- Diviser les données dans un nombre prédéfinis de cluser, quand point est assigné au groupe le plus proche
- **Clustering hiérarchique** (Agllomératif ou divisionnel)
	- Représenté sous forme d'arbre, création d'un hiérarchie entre les culsters
- **Culustering basé  sur la densité** (DBSCAN)
	- Séparez les données par densité

#### K-means

Diviser les données avec un certain nombre de K-cluster

1. On choisi K points qui représenterons le centre du cluster, ces points sont appelé centroides
2. On associe les points au cluster le plus proche
3. Recalculation des centroides, on le recalcule par rapport la moyenne des points
4. Répétition => On répète les étapes 2 et 3 jusqu'a avoir des changement très très faible

Avantages :
- Simple
- Rapide

Limites :
- Sensible aux outliers (au point qui sont un peu n'importe ou, ou très éloigné)
- Nécessite de connaitre K à l'avance

#### Clustering hiérarchique

Créer un arbre de cluster ou chaque cluster est regroupé dans une cluster plus grand

Deux approches

- **Agglomératif** : On commence avec des cluster individuel, puis on les fusionne entres eux petit à petit jusqu'a avoir un seul et gros cluster
- **Divisionnel** : On fait l'inverse, on prend un gros cluster qu'on divise de plus en plus

1. Chaque point est un custer
2. Fusion des cluster les plus proches
3. Répétitiion des étapes

Avantage :
- On peut voir tout ça sous forme d'arbre ce qui est cool pour bien comprend les résultat
- Après du coup on peut le découper à la hauteur qu'on veut pour après choisir le nombre de cluster qu'on veut
- Pas besoin de définir le nombre de cluster à l'avance
  
Limites :
- Complexité computationnelle, ne convient pas au grand groupe de données


### Clustering DBSCAN

Regroupe les points par rapport à leurs densité

Paramètre de DBSCAN
- *epsilon* => rayon de recherche de ses voison
- *MinPoint* => nombre de point minimale pour faire une cluster

Il est mieux que K-means lors de regroupement de données pas très structuré


Avantages
- Pas besoin de connaitres le nombres de cluster à l'avances
- Peut identifier les formes irégulière
- Capabel de détecter les points abbrérants ou "bruit"

Incovenients
- Sensible au paramètres qu'on lui as attribué
- et peut avoir du mal à séparé des données avec des densité très différentes


## Evaluations des clustering


Problème => pas de données annotées, dont on peut pas savoir si c'est correcte ou pas 

Irentie intra-cluster (WCSS) : Musures si les clusters dont cohérent entre eux
- Paramètres de l'inertie :
	- K : Nombre de cluster
	- Ci : Point dans le cluster i
	- Ui : Centroide du cluster i
	- Distances entre Ci et Ui
	  
-> Méthode du coude pour déterminé le nombre optimale de cluster

Indices de silhouette : Regarde si tout à été bien regroupéé
- Elle mesures la cohésion interne (distances entre les point d'un meme cluster)
- Séparation externe (distance entre un points et celui des autres cluster)
- Parmètres
	- a(i) : distance moyenne entre un point i et tout les autres
	- b(i) : distance moyenne entre i et tout les points i du cluster le plus proche de ceui de i
	- s(i) : varie entre -1 et 1, 
		- Si s(i) est proche de 1 : Le point est bien assigné à son cluster
		- Si s(i) proche de 0 : le point est à la frontière de deux cluster
		- si(i) négatif : le point est probablement mal assigné


# PYTHON !  VOIR LE DIAPO !!!


