## Cycles

**Cycle**
C'est uen chaine qui ne contient pas deux fois le même arc et dont le sommet initial et le sommet terminal coïncident.

**Cycle élémentaire**
Cycle qui passe une fois au plus par un sommet


- Dans un graphe quelquconque il peut avoir un nombre exponentielle de cycles.

## Base de cycles

**Notation vectorielle**
LEs arcs d'un grpahe étant numoroté de 1 à $m$, on peut faire correspondre à tout cycle à $m$-uplet (un "vecteur") composé de $-1$, $1$ et $0$ de la manière suivante :

- Si l'arc appartient pas au cycle on met un $0$
- Si l'arc appartient au cycle et est parcouru dans le bon sens (il est alors directe) on met $+1$.
- Si l'arc appartient au cycle mais parcouru dans le mauvais sens (on le qualité de "inverse"), on met $-1$.

Un cycle peut aussi être vu comme une combinaison linéaire des cycle qui le compose.

### Définition
On peut définir une **base de cycles** (dans le sens vectoriel) comme étant une famille de cycle :

- **libre** : tous les cycles indépendants aucun ne peut se définir comme une combinaison linéaire des autres. 

et 

- **génératrice** : tout cycle peut s'écire comme une combinaison linéaire des cycles de même famille.


### Nombre Cyclomatique

C'est le **nombre de cycle d'une base de cycle**.

On le calcul avec la formule :

- $u(G) = m - n + p$

Avec $m$ le nombre d'arrête, $n$ le nombre de sommet et $p$ le nombre de composante connexes.


## Arbre

Un arbre en théorie des graphe est un **graphe connexe** qui ne **comporte aucun cycle**.

- Depuis n'importe quelle graphe connexe on peut en retirant des arrête créer un arbre.
- Si on ajoute une arrête à n'importe quelle arbre alors on créer automatiquement un cycle et il n'est plus un arbre.

## Cocycle

Soit $A$ un ensemble de sommets d'un graphe $G$, on appelle cocycle associé à $A$, qu'on notre $\mu(A)$ l'ensemble des arc incidents à $A$, ceux qui quittent $A$ seront notés positivement et ceux qui pointent vers $A$ seront notés négativement.

Exemple : 
- $\mu(A) = { D, F } = (1, 0, 0, -1, 1)$.

Avec $A$ un ensemble de points, qui contient les sommets $D$ et $F$.

En gros on prend un ensemble de points, et pour toutes les arrêtes :

- Si ils sortent dans un des sommets $+1$.
- Si ils rentre dans un des sommets $-1$.
- Si il ne touche pas les sommets $0$.
- **Si il sort dans un sommet et qu'il rentre aussi dans un des sommets on met $0$**.

## Base de Cocycle

Une base de cocycles est :

- **Une famille de cocyles libres** : colinéaire
- **Et génératrice** : tout cocycles peut s'inscrire comme une combinaison linéaire des autres.

Le nombre **cocyclomatique**, noté $\gamma(G) = n - p$, est le nombre délément d'une base cocycle.

Exemple:

- $\gamma(G) = {(ADB), (ABC), (BCF)}$


**Alogrithme pour trouver une base de cocycle** :

1) On transforme notre graphe en arbre.
2) Pour chaque arrête on la retire, afin de créer 2 composante distincte.
3) On calcul le cocycle d'une des deux composante, dans le graphe quelquconque.
4) On rajoute le vecteur de cocycle dans notre base (et on rajoute l'arc qu'on avais retirer).

On répête ces étapes pour toutes arrêtes.


## Planarité

Un graphe **planaire** est un graphe qui à la particularité de pouvoir se représenter sur un plan sans que **aucune arrête en croise une autre**.

- En gros les arrêtes ne se croise pas, ou si on en déplacement des sommets les arrête se croise plus.

## Faces

Région du plan limitée par des arrees dont l'esnembe des consitue la frontiére + face infinie.

- En gros une zone entourer le sommets et délimitées par les arrêtes

Les faces dépendents de la représentation planaire du graphe.

## Frontière et contour

**Grphe planaire topologiques**
Graphe planaire topologique est une représentation planaire d'un graphe planaire.

**EN GROS C'EST JUSTE UN GRAPHE PLANAIR DESSINER**, c'est la même chose qu'un graphe planair, c'est juste que pour pouvoir avoir des faces on est obligé de le déssiner donc il donne un nom nouveau (mais te casse pas la tête c'est la même)

- Contour de $F1 = F, A, B, C, D, D, E, A$
- Frontiéres de $F1 = F, A, B, C , D, E, F, I, H, F$.
- La frontière dépend de la représentation pas le contour.

Les contours sont des **cycles élémentaire** !

**Théorème**
Dans un graphe planaire topologique, les contours des faces finies constituent une base de cycles.

**Théorème d'Euler**
Dans un graphe planaire à $n$ sommets, $m$ arrêtes et $f$ faces, on a : $n - m + f = 2$

## Graphe dual d'un graphe planair topologique

$G^*$ graphe dual d'un graphe $G$ planaire topologique si :
- Sommets de $G^* =$ faces de $G$.
- $e^* = (f^*, g^*)$ est une arrête de G^* si les faces $f$ et $g$ de $G$ partagent l'arrête $e$.

## Graphe biparti

Un graphe est dit **biparti** si sont ensemble de sommet peut être diviser en deux sous ensembles disjoints $U$ et $V$. tels que chaque arrête ait une extrémité dans $U$ et l'autre dans $V$.

- En gros c'est la possibilité de diviser un graphe en deux sous ensemble **stable**

**Propriétées**
Si $G$ est un graphe simple planair connexe contenant au moins 1 face finie alors 
- $m < 3n - 5$, avec $m$ le nombre d'arrête et $n$ le nombre de sommets.
- il existe au moins un sommet $e$ de degré $d(e) < 6$


