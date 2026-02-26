# PARTIE 2. Graphe et sous-graphe particuliers

## Ensemble Stable

soit $G = (V, E)$ un graphe, un ensemble stable de G est un sous ensemble de S de sommets de $V$ tel que deux sommets de $S$ ne sont jamais voisin.

En gros c'est un **groupe de sommet qui ne sont pas voisin** dans un graphe !

Exemple :
- $S' = { B, F }$ stable
- $S'' = {B, F, C}$ stable maximal

### Théorème
Dans un graphe de $n$ sommet et de degré maximal 
$h$, la cardinalité de tout ensemble maximal est supérieur ou égale à $Card(\frac{n}{h+1})$

## Graphe Complet

**Propriété**
Un graphe dont tous les sommets sont adjacents deux à deux, c'est à dire que tout couple de sommets est relié par une arête.

- C'est un graphe ou tout les sommets sont voisin entre eux (c'est à dire qu'ils sont relier entre eux)
- Un graphe complet orienté est forcément fortement connexe

On appelle souvent à graphe complet $K_n$ avec $n$ le nombre de sommets.
- Le nombre d'arrête d'un graphe complet est égale à : $\frac{n \times (n - 1)}{2}$ (si c'est pas orienté)


## Clique

**Définition**
Soit un graphe $G$ non orienté, une clique de $G$ est un sous-graphe complet de $G$.


### Partition des sommets en cliques

Soit $G = (V, E)$ un graphe. $P = {C_1, C_2, \dots C_k}$ est une partition des sommets de $G$ en cliques si :
- $C_1, C_2, \dots C_k$ sont des cliques de $G$.
- $\forall i, j \in 1, \dots k$ : $V(C_i) \cap V(C_j) = 0$
- .... 

**Théorème**
Soit un stable de $S$ de $G$ et de $P$ une partition en clique de sommets de G alors $|S| \leq |P|$.
-> Si on as $|S| = |P|$ alors $S$ est un stable maximum et $P$ une partition minimum.

- $|P|$ le nombre de sommet qui ne sont **pas stable**
- $|S|$ le nombre de sommet qui sont **stable**

## Ensemble absorbant

**Définition**
Soit un graphe $G$ orienté. Un ensemble absorbant de $G$ est un sous-ensemble $A$ de sommets $G$ tel que tout sommet n'appartient pas à $A$ a un successeur dans $A$.

- En fait c'est un ensemble qui est accessible par n'importe quelle point du graphe
- C'est à dire que tout les autres sommet on au moins un successeur dans l'ensemble absorbant.

**Nombre d'absorption**
$\beta(G) =$ cardinal du plus petit ensemble absorbant


**Absorbant minimal** : Si on retire un sommet, alors le groupe n'est plus absorbant.
**Absorbant minimum** : C'est le plus petit groupe de sommet absorbant qu'on peut faire.


## Noyau

**Définition**
Soit un graphe $G = (V, E)$ orienté, un noyaux de $G$ est un sous-ensemble de sommets $G$ qui est à la fois **stable et absorbant**.

- Un graphe peut avoir un ou plusieurs noyaux ou aucun.

(*Askip ça permet de gagner à 100% au jeu des craies de Fort Boyard*)

## Fonction de Grundy

Soit un graphe $G = (V, E)$ orienté. $g$ est une fonction de Grundy de G si $g$ est une application de $V$ dans $N$ telle que $g(v)$ est le plus petit entier non attribué aux successeurs de $v$

- En gros pour chaque sommet on essaye de mettre un nombre différent à son successeur (souvent 0 ou 1, on ajoute un nouveau numéro seulement si son successeur et son prédécesseur est le même !
- Les entier qui ont un 0 c'est le noyau.

## Base de cycles


