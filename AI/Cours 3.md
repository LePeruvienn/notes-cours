
# Régréssion

Ici on cherche plus à prédire des classes mais des valeurs numériques


- Principe de régréssions
- Algo
- Evaluations
- Python


C'est une méthode d'apprentissage supervisé pour prédire des valeurs continue

Objectif : modélisé la realitons entre plusieurs varaibles inépendantes

**Exemple** : Prédire le prix d'une maison (plusieurs facteurs sont prix en compte : pièces , localisations, surfaces)

Ces facteurs sont les **variables indépendantes** qu'on utilise pour prédire le prix


### Régréssion linéaire simple

Algo d'aprentissage qui permettre de prédire une varaibles continue avec 1 seule variable indépendantes

**Objectif** : Trouver une droite qui s'ajuste le mieux aux données

y = B1 * x + B0

y : var indépendante
x : variables dépendantes
B1 : coéfficients
B0 : ordonnées à l'origine


### Régréssion linéaire multiple


Extension del la régréssion linéaire avec plusieurs var indépendantes

y = B1  * x1 + B2 * x2  + ... + b

y : la valeur prédites
x1,x2, ... : les variables indépendantes
B1, B2, ... : Les coéfficients
b : l'ordnnées à l'origine


Objectif : trouverl es valeurs des coéfficients qui minimsent la différentes entre les valeurs prédites

**Visualisations** :  Ici on as une visualisation qui peut être plus plusieurs dimensions, chaque varaibles indépendantes ajoute une dimension

### QU'est ce que des variables corrélées


Les varirables corrélées sont des variables qui on tendances à varier ensemble :
- ex : Nombre de pièce et surface d'une maison

Pour la régréssion les varaibles corrélé peuvent causé des problème


- Corrélation positive => Une variable qui augmente une autres qui augmente
- Corrélation négative => Une variable qui augmente qui fait diminué une autres
- Pas de corrélation => Aucune corrélations quoi


## Régréssion Ridge et Lasso

Variante de régréssion linéaire

Permette d'optimiser la régréssion quand il y a beaucoup de valeurs corrélé

Leurs objectif est de réduire le surapprentissage


###  Régréssion Ridge

Elle pénalise la sommes des carrés des coéfficients des variables indépendantes

Evite le surapprensittage

Utilie quand plusieurs variables corrélé entre elle

Il n'aulle psas les coéfficients

Bon pour beaucoup de variables corrélé

### Régréssion Lasso

La régrésion lasso utilise une pénalité **basé sur la sommme des valeurs absolues des coéfficients**


Lasso peut mettre des variables exactement à 0 et donc éliminer des complétement certaine variables.

Si il ya beaucoup de données Lasso est utiles car elle permet d'éliminer les variables inutiles


Bon pour la sélection de variables et simplifié le modèle


# Régréssion non-linéaire


C'est une méthode de régréssion n'est pas représenté par une droite

Ici on représente des relations plux complexe avec des courbes


Une régréssion non-linéaire ça peut ressembler à 
- Courbe exponentielle
- Courbe piece de suivi d'un plateua
- Courbe sinuosidale


L'aglo va essayer de ptrouver des paramètre de l'équation qui correspond le mieux au données

Elle necessite des méthode d'optimisations plus complexe


Application pratique
- Biologie : modéliser croissances 
- Finance  : courbe de rendement
- Science physique : modéliser des p


#### Evaluation

Utilser les métrique d'évaluation pour : 
- Erreur quadratique moyenne (MSE) : Diff moyenne carré eentre les valeurs prédites en réelle
- Erreur absolue moyenne (MAE) : diff moy absolue entre les valeurs réelle et prédite
- R² (oefficient de détermination)


Comparaison MAE et MSE : 

**MAE** plus simple à interprété car elle va indique directiement l'erreur moyenne de la var cible

**MSE** accorde plus d'importance aux erreur improtante


**R² (coéfficient de déterminantion)** est compris entre 0 et 1 

SI R² = 1 cela signigie que le mod-le est explique 100% la variacles des données 
R² = 0 ça veut dire il as rien compris 


Plus c'est proche de 1 mieux c'est



# Python

(Voir le diapo je peut pas tout noté la)
*diapo 3 toute à la fin*

