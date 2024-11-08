
# Réseaux de neurones

- réseaux inspirer du cerveau humain
- Composé de plusieurs couche de neurones artificiels (ou noeuds) qui transmette des infos


## Structure

input layer -> hidden layers -> output layer


## Fonctionnement d'un neuron artificiel

- Entrée : prend des valeurs en entrée (caractérisuqtuqe ou features)
- Caclcul de la somme pondérée
- Ajout d'un Biais : C'est une valeurs additionnelle qui aide à ajuster la some pondérée
- Fonction d'activiation : transforme la somme pondérée en une sortie


## Architecure des réseaux de neurones

- Perceptron Multicouches (MLP) => Celui qu'on va faire le plus
- Convolution Neural Network (CNN)
- Recurrent Neural Network (RNN)
- ...



## Couches

**Couche d'entrées**
- Première couche
- Reçoit les caractéristique de l'entrée
- Ne fais pas de calculs

**Couches cachées**
- Couches intermédiaire
- Elles peuvent être nombreuse, plus elles sont nombreuse plus l'entrainement est long
- Elles appliques des poids, biais et une fonction d'activiation

**Couches de sorties**
- Dernière couche
- Fournit le résultat finale
- Elle produit une proba entre 0 et 1


**Connexions entres les couches**
- Chaque couche modifie l'information
- Ce procesus se poursuite jusqu'a la couche de sortie


## Fonctions d'activation

### Tangeante Hyperbolique

- Sortie : entre 0 et 1
- Avantage : Centrées autours de 0 => Meilleur convergence, souvent utilsé pour les couches cachées
- Invonvénient : Problème des gradients qui disparaissment

### Rectifie Linera Unit

- Sortie : Valeurs positive
- Avantage : Légère et simple, rapide à calculer + évite le problème des gradients
- Inconvénients: Peut conduire à des neurones mort (qui renvoei toujours 0)
- Utilisation : Par défault pour les couches cachées

### Softmax

- Sortie : Somme à 1
- Avantages : idéale pour les classicication multi-classe
- Inconvénients : Plus couteuse en terme de calcul
- Utilisation : Dernière couche


## Apprentissage d'un réseau de neurones

Repose sur l'idée de réduire l'erreur entre ses prédictions et les résultat attendu en ajustantes les biais et poids à chaque étapes

1) Initialisation
2) Propagation Avant
3) Calcu de l'erreur
4) Rétropropagation de l'erreur
5) Descente de gradient

### Propagation Avant

(Forward Propagation)

- On traverse tout le réseau
- On applique à chaque fois une combinaison linéaire

### Calcul de l'erreur
(ou de la perte)

- Comparation avec la valeurs réelle (étiquette) avec la fonction de perte
- On as a quelle point l'erreur est grande

### Rétropropagation de l'erreur
(Backpropagation)

- On corrige les poids et les biais en fonction de l'erreur claculer
- On calcule l'imapct de l'erreur global avec le calcul des gradients

### Descente de gradient
(Gradient Descent)

Une fois les gradient calculer, on fait une descente de gradient pour ajuster son poids
- Modifier chaque poids dans sa direction opposé : poids = poids - n = gradient
- n est le taux d'apprentissage
- si n trop élevé les poids peuvent trop varier et ne pas converger



## Concepts clés en apprentissage des réseaux de neurons

### Vanishing Gradient (Gradient évanescents)
- Ce problème apparait lors de la rétropropagation


### Underfitting (Sous-apprentissage)
- Quand le modèle est trop simpe pour les données
- Mauvais performence sur les données de test et d'apprentissage
- Solutions : 
	- Complexifier
	- ...

### Overfitting (Surapprentissage)
- C'est quand le modèle c'est trop entrainé sur nos deonnées d'entrainement et caputre alors des détails qui sont que propre à nos données d'entrainement
- Du coup sur d'autres valeurs que celle d'entrainement il marche pas bien
- C'est souvent à cause qu'on as un modèle trop complexe par rapport à nos données disponible
- Solutio :
	- Limité la complexité
	- Arretez l'entrainement des que les performence sur les données de validiation diminue
	- Ajouter plus de données


## Pyhton
- Utilisation des librairies python `keras` et `tensorflow`