### Circuit vs Cycle 

**Circuit** : Chemin qui revient à son point de départ **(orienté)**
**Cycle** : même chose mais sans tenir compte du sens **(non orienté)**

### Graphe Complet

Graphe ou chaque point peut atteindre tout les autres.

### Graphe Mineur (d'un autre graphe)

Graphe ou on fusionne les sommets pour créer un graphe plus petit.

### Graphe connexe vs fortement connexe

**Connexe** : Tout les sommets du graphe sous relier entre eux **(pas orienté)**

**Fortement connexe** : même chose mais le sens compte **(orienté)**

#### Prouver Connexe

Donner un chemin qui passe par toutes les arrêtes

#### Prouver Fortement connexe

**Alogorithme des + et des -**

- On chosi un sommet et on lui met + et - au dessus
- On commence avec les **+**
  - Dès qu'un noeud marqué + à une arrête sortant on marque son noeud d'arriver +
- Puis on fait les **-**
  - Des qu'un sommet marquer - as une arrêt qui est entrante, alors on marque le sommet de départ -

**Tout les sommets marquer + et - sont fortement connexe**

### Chemin Hamiltonien et Cycle Hamiltonien

**Un chemin Hamiltonien** est un chemin qui passe par tout les noeuds du graphe sans passer deux fois par le même.

**Un cycle Hamiltonien** c'est la possibilité de faire le chemin dans les deux sens (on part et on reviens). Et chaque fois on ne passe pas deux fois par la même arrête.


### Ensemble Absorbant

On définit un ensemble $G$.

Il faut que tout les sommets qui n'appartienne pas à l'ensemble $G$. On une arrête qui les relis à un sommet qui lui appartient à l'ensemble $G$.

### Ensemble Stable

C'est un ensemble de sommets qui sont tous pas relie directement par une arrête entre eux.

- **Stable maximal** : On ne peut plus ajouter de sommet sans que ça soit plus stable
- **Stable maximum** : Le plus grand nombre de sommet dans le stable possible

### Noyau

**Noyau c'est une ensemble Stable + Absorbant**

### Fonction de Grundy 

On numérote les avec le moins de numéro possible, 

### Fonction de Grundy dans un graphe sans circuit

On prend les nœuds dans l’ordre inverse du tri topologique. On a alors jamais le choix pour
numéroter un nœud (car soit c’est un puits qu’on numérote avec 0 soit tous ses successeurs
sont numérotés). La fonction de Grundy et le noyau sont donc uniques.

### Gagner tout le temps aux jeux

pour gagner, un joueur doit, à la fin de son tour, avoir mis le jeu dans un état qui est dans le noyau. Ou, de manière équivalent, si l’état initial est dans le noyau, le joueur 2 a une stratégie gagnante, sinon c’est le joueur 1.

En effet, si un joueur peut jouer dans le noyau, par stabilité du noyau, son adversaire doit forcément jouer hors du noyau. Et par absorption, le joueur peut rejouer dans le noyau au tour suivant.

Puisque l’état perdant est nécessairement dans le noyau et que le graphe est sans circuit, l’adversaire va forcément finir dans cet état.

### Combinaise linéaire de cyle

On peut représenter les cycle avec des vecteurs

Par exemple le cycle $(a,b,c,a)$

### Graphe complet

C'est un graphe ou tout les sommets sont voisin entre eux (c'est à dire qu'ils sont relier entre eux)

### Cliques

Définition Soit $G$ un graphe non orienté, une clique de est un sous-graphe complet de $G$.

- **Clique Maximale** : On ne peut pas ajouter un sommet au graphe, sans qu'il ne devienne plus complet
- **Clique Maximum** : C'est la clique qui possède le plus grand nombre de sommets

- **Clique Minimale** : C'est une clique telle que si l'on retire n'importe quel sommet, elle perd sa propriété de clique.
- **Clique Minimum** : C'est la plus petite clique possible dans le graphe.


### Graphe Complémentaire

On dit le graphe Complémentaire à $G$ (noté aussi $\bar{G}$), le même graphe mais avec les arrêtes inverser


### Base de cycle

Indépendate, génératrice,

On la note en vecteur, avec si les arrête sont dans le bon sens

### Calcul

Depuis notre graphe on créer un **sous-graphe connexe** qui est un **arbre**

Puis ensuite on y ajoute alors une arrête : cela **créer alors un cycle !**

- On répête cette opération, et lorsque l'ajout d'une arrête créer un cycle alors on note le cycle.

Ex : base de cycle : {$C_1, C_2, C_3, C_4$}

Nombre d'élément dans une base de cycle pour un graphe G: 

Nombre d'élément dans une base de cycle pour un graphe G: 
- $m − n + p = 4$ ($m$ nb arcs, $n$ nb nœuds, $p$ nb comp connexes)


##
