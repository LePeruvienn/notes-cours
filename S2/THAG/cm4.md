---
title: CM4
---

*Alistaire be like* : 🚄

# Controle 

Date : **dernière semaine de mai**
- On as le droit de ramener 4 feuille A4 recto-verso
- On as le droit d'imprimer

# Graphe et Optimisation

## Coloration

**Coloration** : Colorier les sommets de $G$ sas que 2 voisin aient la même couleur.

**Nombre chromatique** : $\gamma(G)$ : plus petit nombre de couleurs nécessaires pour colorier les sommets de $G$ sans que 2 voisins aient la même couleur.

Trouver un algo qui résoue ce problème qui assure trouver le nombre optimale est alors forcément de compléxité $O(e^n)$.

### Propritées

- Chaque clique $K_i$ aura alors $i$ couleurs.
- Chaque couleurs représente alors un ensemble stable

### Théorème des 4 couleurs

- Si $G$ **est un graphe planaire** alors $\gamma(G) \le 4$

Toute carte peut être coloriée avec au plus 4 couleurs

### Problème fondamental en théorie de l'ordonnancement

Ordonnancer $n$ taches sur $k$ processus en un minimum de temps, certaines tâches ne pouvant pas être executée en parralèle (partages des ressources)

- Conflit entre taches => graphe d'exclusion mutuelle

ordonnancement = coloration du graphe tel que chaque couleurs n'apparaisse pas plus de $k$ fois


### Remarque

Le nombre chromatique $\gamma(G)$ d'un graphe est le nombre nécessaire et suffisant pour colorier $G$.

- Un **minorant** sont tout les nombre entre la valeur optimal et 0
- Un **majorant** sont tout les nombres la valeur optimal et $+\infin$

Et la valeur optimal c'est le $\gamma(G)$, le nombre chromatique

Il existe pas d'algorithme efficae pour trouver $\gamma(G)$, mais en il existe qui permette de trouver des (bons) majorants.

### Ordre d'un graphe

L'odre d'un graphe $Ord(G)$ d'un graphe $G$ est a taille maximal d'une clique de $G$.

Le nombre chromatique est alors : $\gamma(G) \ge Ord(G)$

### Théorème de Brooks

$d_{max}(G)$est le degré maximum des sommets d'un graphe $G$.

Soit $G = (V,E)$ un graphe. Il est toujours possible de colorer $G$ avec $d_{max}(G) + 1$ couleurs.

Autrement dit $d_{max}(G) + 1$ est un majorant de $\gamma(G) : \gamma(G) \le d_{max}(G) + 1$

- Quand le graphe est en étoile (*ou soleil ☀️ RPZ Alistair*), alors avec ce théorème le majorant sera mauvais car le degré est très grand ! (Alors que souvent il faut que  2 couleurs)

### Algorithme de Welsh-Powell

Il donne une coloration vaide qui est un majorant (borne supérieur) de $\gamma(G)$, en temps polynomial

**Définition**

```
...
```

**Explication**

En fait juste on met une couleur à un sommet, puis on met la même à tout les autres sommet qui ne sont pas voisin entre eux.
- Puis on répète avec les sommets restant et une nouvelle couleurs

Cette alogrithme ne permet pas de trouver tout le temps la solution optimal, c'est piur ça qu'on dit que c'est un algo polynomial.

### Reliement-contraction

On colorie tout les sommets de la même couleurs

- Pour colorier un grpahe complet (une clique) contenant $n$ sommets il faut $n$ couleurs.

- On prend 2 sommets $a$ et $b$ non reliés (en fait ici on créer un cas par rapport à ce qu'on choisi)

  - Soit ils ont la même couleur
  - Soit ils ont une couleur différentes

- On créer alors un nouveau cas et pour chacun des cas si :
  - Même couleurs = contraction
  - Couleurs différentes = ajout d'une arrête

- On s'arrête quand on as un graphe complet.

Cette alogo à une compléxité de $O(2^m)$ avec $m$ le nombre d'arrête

**En fait en faisant comme ça alors on créer plusieurs cas différents afin d'avoir toutes les valeurs possibles. Il suffit d'ensuite choisir la valeur la plus petite** !


Après avec ce graphe colorier on peut le transformer en une clique plus petite avec cette algo :

- On prend 2 sommets $a$ et $b$ non reliés
  - Soit ils ont la même couleur = on les contracte
  - Soit ils ont des couleurs différentes on ajoute une arrête

On reviens alors à une clique plus petite équivalente.

## Coloration d'arête

Colorier les arête de $G$ sans que 2 arête adjacente aient la même couleur.

Le but est de trouver le nombre le plus petit d'arête à utiliser.

### "Line graph" ou "graphe des arête"

Le but est de passer d'un graphe à un graphe des arrête.

Les mêmes algo des graphe de sommets marche sur un graphe des arrêtes.

## Autres

```mermaid
graph TD
A((A))
B((B))
C((C))
D((D))
E((E))
F((F))
```


