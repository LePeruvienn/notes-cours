# TD7

## Exercice 1

Formule d'Euler $a > 3 \times s - 6$, avec $a$ nombre d'arrête et $s$ le nombre de sommet, alors il est pas planaire

1. 

C'est un graphe $K_5$ (*complet à 5 sommets*), donc il est pr définition pas planaire


2.

C'est un graphe Planair, il n'est pas complet.

$9 < 3 \times 5 - 6 <=> 9 < 9$ Donc pas supérieur alors bien planaire !


3. 

Il y a dans le graphe un sous grpahe $K_{3,3}$ (*biparti à 3 sommet complet*) donc il n'est pas planaire

4.

Il est planaire, pas complet !

5.

Il pas est planaire :'(

$30 > 3 \times 10 - 5 <=> 30 > 25$, donc il est pas planaire selon la formule d'Euler

6.

Pas planaire askip

## Exercice 2 

1. 

$m < 3n - 5$ avec $n$ le nombre de sommet et $m$ le nombre d'arrête.

$14 < 3 \times 10 <=> 14 < 30$

Donc il vérifie la condition, il peut alors être planaire, ou peutre pas.

En fait cette formule si la doncition n'est pas rempli permet d'asssurer qu'il est pas planaire. Mais pas dans l'autre sens.

On peut prouver qu'il est pas planaire en trouvant le **mineur du graph**e qui **est $K_5$ !**

Voir `cm3.md`

2. 

Il n'y a pas de trinagles (cycle à 3 sommet) car deux voisins d'un même sommets ne sont jamais adjacents.

Il n'ya pas de cycle de longueuer 4 car deux sommets non voisins ne partagent jamais deux voisins communs.

Donc le graphe de patersen ne contient quacun cycle de longueur $\leq 4$.


- En fait les sommets adjacents n'ont pas de voisin en commun donc ce n'est pas possible de faire des cycle de taille 4.

3.

Toutes faces est bordée par au moins $c + 1$ arêtes.

Donc en comptant les arêtes autour des faces : $(c + 1) \times f \leq 2 \times n$,

- Avec $c$ la taille de cycle minimal, $f$ le nombre de faces et $n$ le nombre de sommets.

Avec euler : $n - m +f = 2$ donc $f = 2 - m + n$

On injecte : 
- $(c + 1) \times (2 - n + m) \leq 2 \times m$
- $(c + 1) \times (2 - n + m) \leq 2 \times m$
- $(c - 1) \times m \leq (c + 1) \times (n - 2)$

Donc $m \leq \frac{(c + 1) \times (n - 2)}{(c - 1)}$

4.

On prenant $c = 4 : \frac{5 \times (n - 2)}{3} + 1 <=> m < 4,33$

Donc il n'est pas planaire !

