---
title: CM2
---

# 1. Rappel statistiques descriptives

## Echantillion - Type de caractères

### Echantillion

Souvent si la population est trop grande ou on as pas accès à une partie, alors on étudie un sous-partie de celle-ci.

Il faut bien choisir les échantillon pour éviter les bias.

### Type de caractère

Ce sont les caractèristique des individus, ils peuvent être 
- Leurs caractéritisque personnels
- Les réponse qu'ils donnent au sondage (il réponde "très bien" au sondage)

Ils sont de deux types :

1. **Caractère qualititif**

Il est **ordinal** si les résultat tiennt compte d'un ordre, sinon il est **nominal**.

Exemple : Bien, Très bien, pas fou


2. **Caractère quantitatif**

C'est lorsque que les résultat de l'individu peut être exprimer sous forme numérique (ex: prix que vous être prète à mettre).

Il peut être **discret** (1, 2, 3, 4) ou **continue** entre (0 et 100 dans R)


## Modalité - Classe

### Modalité

C'est les **différentes valeurs que peuvent prendre une caractéritisque**. 

Par exemple la caractéritisque note peut prendre comme modalités : (0, 1, 2 ... 20).

### Classe

Le problème c'est que parfois avoir trop de modalité pour une caractéristique peut nuire les résultat du sondage donc on regroupe ces modalité dans des intervalle pour créer ainsi une classe.

**Une classe est alors un ensemble de modalité.**

Par exemple on pourrrais dire pour l'exemple d'une note :

- Les notes entre 0 et 10 sont dans la classe "mauvaise note"
- Les notes entre 10 et 20 sont dans la classe "bonne note"


Le nombre de classe optimal à avoir peut être déterminé à l'aide de plusieurs règles :

- **Règle de sturge** : Nombre de classe $= 1 + 10log(n)/3$ ou log est en base $10$

- **Rège de Yule** : Nombre de classes 

## Effectifs - Fréquences

### Effectifs

**L'effectif d'une modalité ou classe**, c'est le **nombre de personnes qui pour une caractéritisques ont choisi la modalités $x_i$**.

- Par exemple : L'effectifs des personnes ayant 12 / 20.

**L'effectif total** : $n$ associté à $k$ modalité (ou classe) est la some de tout les effectifs :  $n = n_1 + n_2 + \dots + n_k$

### Fréquence

C'est la **fréquence du choix d'une modalités au classe à été choisi**.

En fait c'est le pourcentage de personne qui ont choisi une modalité par rapport au nombre de modalité totale.

Par exemple fréquence de personne qui on eu 12 / 20 :
$$
f_i = \frac{n_i}{n}
$$

- Avec $n_i$ le nombre de personne ayant 12 /20
- Avec $n$ l'effectif total des modalitées.

### Fréquence cummulé

En fait le but c'est de définir l'effectif et la fréquence pour les personne ayant choisi une modalité inféieur à la modalité $x_i$.

**Effectifs cummulé croissant**
- Tout ceux qui ont eu plus de $n_i$.
- Ex: Tout ceux qui ont eu plus de 10

**Effectifs cummulé décroissant**
- Tout ceux qui ont eu moins de $n_i$.
- Ex: Tout ceux qui ont eu moins de 10

## Représentation graphiques

### 1. Diagramme à secteurs circulaire

Appelé aussi "**diagramme camembert**", il peut être modéliser de la façon suivante :

On preprésente chaque modalité $x_i$ par un secteur qui as un angle de $\theta_i$.

$$
\theta_i = \frac{n_i}{n} \times 360° = f_i \times 360°
$$

Pour $i = 1, 2, \dots k$

### 2. Diagramme en barres

Même principle mais chaque mesure d'une bare

$$
L_i = \frac{n_i}{n} = f_i
$$

Ici on on as alors une valeur entre 0 et 1, il suffit après de multiplier la valeur par la valeur maximale d'une barre.

### 3. Dagramme à courbe cumulative



# 2. Estimation paramétrique

## Méthode des moments

# 3. Intervalles de confiance

## IC asymptotique


