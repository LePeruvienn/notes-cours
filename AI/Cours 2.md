
# Classification supervisé

But : donner un label (une classe) à des données


Diviser les données pour :
	- Entrainement
	- Validation
	- Test


## Préparations des données

- Normalisation: Etape necessaire pour remttre à niveau le modèle

Techniques
- MaxAbsScaler
- MinMaxScaler
- StandartScaler


## KNN

Algorithme de classifications

**KNN** = Algorithme des `k` plus proche voisin
- On choisi une valeur pour k
- ON calcule ldes distances dd entrel a nouvelle données N et ses voisin Xi déja classifié
- Parmi les points Xi, les plus proches de N sont retenues
- On attribu à N le label majoritaire


**Choix de la valeurs de k**
Il faut ajuster cette valuers, le choix de cette valeurs influe sur la perf de l'algo

- Une valeur paire produits des ex-aequos
- Une valeurs trop faible va rendre les résultat sensible au bruit
- Une valeurs trop haute augmente le temps de calcul

**Choix mesure de distance**

- Distance soit Euclidienne soit de Manathann

**Avantages/invonvéniant**
- Simple efficaces pour des petit ensembles
- Couteur en calcul pour des gros ensemble donc pas fou

## Arbre de décision

Algo qui utilise une structure en arbre pour prendre des décisions sur une série de questions.

- **Chaque Noeud** = REprésente un teste ou une question sur une caractéristique
- **Chaque branche** = Non ou Oui
- **Chaque feuille** = Réponse

(Exemple arbre comportementale c'est un arbre de décision)


à chaque noeud les données vonst être diviser
On va répété le processur jusqu'a que chaque feuille soit dans la meme classe pour tout les échantillion

Pour ensuite pouvoir prédire



Anvantages/invonvéniant
- Facile à comprendre et peu de préparations
- Sensible aux données bruité et il va sur apprendre

## SVM

Principes

- Trouver l'hyperplan optimate
- Maximiser la marge
- Gérer la non-linéarité avec des "Kernels"

Avantage/invonvéniant
- Perfomrant pour petites/moyennes base de données, efficace en haute dimension et flexible
- Mins efficace pour de très grand jeux de données



## Evaluations

Utiliser des métrqique pour 
- Mesurer les performence
- et le comparer avec d'autres modèle

**Matrice de confusion**

- Class prédite : ce que le modèle à répondu
- Classe réelle : resulate des tests

Voir ou le modèle c'est tromper


**Rappelle**

Rapelle = VP / (VP  + FN)

Utilisé musrer la proportions des vrai et faux résultat données par le modèle


# Python (SKlearn)

Exemple :

- Manipuler des données dans un fichier csv

Chargement des données dans un dataframe (comme en TP)

Découpage des données, avec la librairie **sklearn**


Normalisation des données avec les méthodes qu'on as vu avant


Définitions du modèle

