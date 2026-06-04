# TD8

## Exercice 1

1) 

Nombre chromatique d'un cycle élémentaire : 2 - 3
Nombre chromatique d'un graphe biparti : 2

**Propriété** : Un graphe biparti, as pour propriété de toujours avoir un nombre chromatique égale à 2

2) 

Si $G_0$ un graphe partiel de $G$, alors $\chi(G_0) \leq\chi(G)$

Une clique st un sous graphe complet.

Le nombre chromatique d'une clique st toujours son nombre de sommet.

Donc $\chi(G) \le \omega(G)$

3)

Graphe d'ordre $n$ est un graphe avec $n$ sommets.


a)

Chaque couleur forme un stable, donc $n \le \sum_i{S_{ci}} \le \sum_i{\alpha(G)} \le \chi(G) \times \alpha(G)$

avec $S_{ci}$ les sommets de couleur $i$.

b)

Supposons qu'on colorie chaque sommet du stable maxiumum avec une seul et même coleur et chaque autre sommet avec une couleur différente.

Si $G$ possède une clique maxiumum de taille $\omega(G)$ alors cette clique C doit être exactement $\omega(G)$ couleurs.

On obtient le résultat puisque $\chi(C) \le \chi(G)$
On bient une coloration valide avec $n - \alpha(G) + 1$ couleur.

Donc $\chi(G) \le n - \alpha(G) + 1$

4)

Un graphe $K_{3,3}$ est 3 coloriable et pas planaire.

Il faut alors un graphe qui en contient un avec 1 sommet au bon endroit pour qu'il soit 4 coloriable.

## Exercice 3


- Si le graphe est de taille 1, on renvoie 1
- Si le graphe est biparti : renvoie 2
- Sinon renvoyer 4

**Théorème des 4 couleurs** : Tout graphe planaire peut être colorier avec 4 couleurs différentes

## Exercice 5



