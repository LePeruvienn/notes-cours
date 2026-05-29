## Couplage

**Couplage d'un graphe $G$** :  Ensemble d'arête $G$ tel que 2 arrêtes quelcuonques sont non adjacentes.

En gros c'est deux arrête qui n'ont aucun sommet en commun.

- **Couplage maximal** : te que ajouter n'importe quelle arête du graphe à ce couplage lui fait perdre sa qualité de couplage.

- **Couplage maximum** : coupage avec le plus grand nombre d'arête possible.

- **Couplage parfait** : c'est un couplage qui touche tout les sommets du graph (Il faut que le graphe ait un nombre pair de sommet !!!)

### Algorithme trouver un couplage maximal

```
G' <- G
C_max = 0
Tant qu'il existe des arêtes dans G' Faire
    Choisir une arrete e dans G'
    C_max = C_max union { e }
    Supprimer de G' l'arete e ainsi que les arêtes voisines de e
Fin Tant que
```


## Arbre

C'est un **graphe connexe et sans cycle**.

**Définitions** :
- Graphe connexe et sans cycle.
- Graphe sans cycle ayant $n - 1$ arêtes.
- Graphe connexe ayant $n - 1$ arête.
- Graphe sans cycle et en ajoutant une arête on crée un seul cycle (donc connexe).
- Graphe connexe, si on supprime une arrête il est plus connexe.
- Graphe contenant une chaine et une seul entre toute paire de sommets.

## Arbre couvrant


**Abre courvrant $T$ d'un graphe $G$** est un graphe partiel de $G$ connexe sans cycle.

Un **arbre couvrant** c'est un arbre qui ne contient pas de cycle.
- Il contient alors toujours un seul chemin entre deux paire de sommet.

### Arbre couvrant de poids minimum (ACM)

C'est un arbre couvrant dont la somme des poids des arêtes est minimal. (c'est à dire le poids eest inférieur ou égal à celui de tous les autres arbres courant du graphe)

### Algorithme de Kruskal

**Forêts** = Un ensemble d'arbres.

- On part d'une forêt d'arbre constitué  de chacun des sommets isolé du graphe
- A chaque itérationn on ajoute à cette forêt l'arête de poid le plus faible possible ne créant pas de cycle avec les arêtes déjà choisi.
- On stope quand on a examiné toutes les arêtes.

**Explication logique** :

- On prend tout les points du graphe, et on considère chacun d'eux comme un arbre (ils ne sont pas relier)
- On ajout une arrête avec le poids le plus faible, ne créant pas de cycle.
- On fait ça pour toutes les arrêtes possible.

A la fin on as un arbre de poids minimum.


### Algorithme de de Prim

- On part d'un arbre d'un arbre initial à un seul sommet du graphe.

- A chaque itération, on agrandit l'arbre en lui ajoutant le sommet libre accessible de plus petit poid possible.


**Explication simple** :

- On prend un sommet au hasard
- On ajoute une arrête qui lui est relier et qui est de poids le plus faible sans créer de cycle.
- `while (1)` cf : *MAXENCE* 💿


