# NOSQL ?

> ça veut pas dire no sql ça veut dire **Not Only SQL !**

On vetu des oslutions poiur des problème qui sont posé par les limites du sql/SGBDR

- Les stockages clé / valeurs
- La gestions des schéma externes


## Le Stockage clé / valeur

Pourquoi ça marche mal ?
> Car en gros il doit chercher parmi toutes les lignes, donc pour 1000 lignes l'algo doit parcourir 1000 lignes.

Technologies qui permettes de rendre ça meilleurs :
- Rédis
- MemCache


## La gestions des schéma externes

En gros c'est la possibilité de récupérer les mêmes données avec des schéma différents.

C'est souvent un problème quand on update les bases de données, les schéma des bases de données doivent alors toujours être rétro-compatibles :

> on ne supprime alors jamais de tables ni de collonnes

Le schéma va toujours évoluer, si on veut garder des retour constant on peut stocker les retour d'api de façon brute.

> Une solution est de renvoyer les données sous format `.json`

On as des technologies qui stockages es données sous format `.json` : 
- MongDB
- ElasticSearch (*MongoDB + API REST*)


## Conslutions

quand on parle de base de données NoSQL, on parle de : 
- Base de données clé valeurs
- Base de données arbres
- Base de données documentaires


