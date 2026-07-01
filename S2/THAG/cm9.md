---
title: CM9
---

# Plus court chemins dans les graphes

## Algorithme de Djikstra

**Djikstra** (1930-2002) a proposé en 1958 un algo qui donne le plus court chemin d'un graphe donc la compléxité est de $O(n^2)$.

Il est utilisable ue pour les graphe à valuations non-négatives, ce qui implique qu'il n'ya pas de circuit de coût négatif.

### Algorithme

pour tout sommet $v \in V$ faire
> $d[v] \leftarrow \infin, \pi[v] \leftarrow NIL$

$d[s] \leftarrow 0$

$E \leftarrow \empty$

$F \leftarrow V[G]$

```
F = tout les sommets du graphe G
d[v] = distance du sommets v

tant que F != vide faire
    u <- v[d[v]] = min{d[x]|x in F} # On prend le sommet avec la plus petite distance
    F <- F - u # On enleve le sommet u de F
    E <- E + u # On rajoute u dans la liste des sommets

    pour ensuite chaque noeud adjacent[u]
        si  d[v] > d[u] + d(u,v)
        alors
            d[v] = d[u] + d(u, v)
```

**Explication**

On fait un tableau avec tout les sommets, qu'on met touts à une distance de $+ \infin$.

Ensuite on commence alors sur un sommet :

- Tout les sommets voisin qui sont plus proche que $+\infin$ on alors replace dans une nouvelle ligne du tableau


#### Exemple 1


```mermaid
flowchart LR

E ---|1| B
E ---|3| A
A ---|1| B
A ---|3| C
B ---|5| D
B ---|3| C
D ---|1| S
C ---|3| S
D ---|1| C
```

| A         | B         | C         | D         | E         | S         |
|-----------|-----------|-----------|-----------|-----------|-----------|
| $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ |
| $3_E$     | $1_E$     | $+\infin$ | $+\infin$ | $0$       | $+\infin$ |
| $2_B$     | $.$       | $4_B$     | $6_B$     | $.$       | $+\infin$ |
| $.$       | $.$       | $4_B$     | $6_B$     | $.$       | $+\infin$ |
| $.$       | $.$       | $.$       | $5_C$     | $.$       | $7_C$     |
| $.$       | $.$       | $.$       | $.$       | $.$       | $6_D$     |


#### Exemple 2


```mermaid
flowchart LR

A -->|1| B
A -->|4| G
A -->|3| C
B -->|2| D
B -->|5| E
G -->|5| F
G -->|1| E
C -->|3| E
E -->|6| F
F -->|5| E
D -->|4| F
F -->|3| D
```

| A         | B         | C         | D         | E         | S         |
|-----------|-----------|-----------|-----------|-----------|-----------|
| $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ |
| $0$       | $?$       | $+\infin$ | $+\infin$ | $+\infin$ | $+\infin$ |


### Si il ya des arcs négatifs !


Exemple on as un graphe avec des arrêtes négatives


```mermaid
flowchart LR

1 ---|1| 2
1 ---|10| 3
2 ---|-100| 4
3 ---|-1000| 4
```

On pourrais essayer de mettre tout en absolu, mais en fait ça va pas marcher tout le temps,

Il yaura toujours des soucis et tout c'est chiant

**L'Algorithme de Djikstra n'est pas Bidouillable**.


## Algorithme de Bellman-Ford

Algorithme de Bellman-Ford aussi appelé Bellman-Ford-Moore1.


Il permet de calculer le plus court chemin dans un graphe (comme Djikstra) mais il peut prendre en compte **les arcs négatif** ! Ce qui Djikstra ne pouvais pas.

Mais il ya des cas on ne peut toujours pas, par exemple lorsqu'il ya un **cycle à arcs négatif**.

Exemple :

```mermaid
flowchart LR

1 ---|-5| 2
1 ---|2| 3
2 ---|-5| 4
3 ---|2| 4
```

Ici par exemple on peut juste faire le tour du coup dans le cycle à l'infini.

L'Algorithme de Bellman-Ford permet alors de **détecter les cycles négatifs**.


### Exemple


```mermaid
flowchart LR

A -->|6| B
A -->|4| C
A -->|5| D
B -->|-1| E
C -->|-2| B
C -->|3| E
D -->|-2| C
D -->|-1| F
E -->|3| F
```

Il faut check toutes les arrête et pas faire un parcours !!!


On fait une liste de toutes les arrêtes dans l'ordre qu'on veut.

IL FAUT LES PARCOURIR LES ARRETE UNE ET UNE SEUL FOIS A CHAQUE ITERATION !

**SOUVIENS TOI DE PEXEP**

- Il ya un tableau avec les meilleurs distance pour chaque sommets.

- Il y a un tableau avec le dernier sommet on était passé ($\pi[v]$)

### Algorithme Floyd-Warshall

En gros on fait tout les cas possibles dans une matrices.


