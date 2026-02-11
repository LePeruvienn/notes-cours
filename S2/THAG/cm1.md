# I. Généralités et définitions

## La notion de graph (un peu d'histoire)

- La théorie des graphe à été inventé par **Euler** dans la ville de Königsberg (Russie)
- Il habitait dans une ville traverser par un fleuve et connecter via des ponts, et voulais déterminé si il était possible de faire le tour de la ville en traversant 1 fois chaque pont de la ville.

-> Afin de résoudre se problème il l'as modéliser **sous forme de graph**.

Grâce à cela il as pu répondre à sa question et aussi pu établir une théorie appliquable sur les autres graphs.

Aujourd'hui la théorie des graphes est utilisé en data-science, pour des réseaux électriques, ...

## Graph non orienté

Un graph ou les liason ne sont pas orienté.
C'est à dire que chaque lien se fait dans les deux sens.

Exemple:
- graphe social de Facebook (réseaux d'amis)

**Définition**
Graphe $G = (V, E)$ non orienté, avec $V$ les sommets, et $E$ les arrêtes.

Plusieurs type de graphe orienté :
- Chaines
- Cycles

## Graphe orienté

Graphe orienté ! Le sens compte ici entre les liaison.

Exemple :
- Le graphe social de Twitter.

**Demi degré intérieur** : $d^-(v)$
**Demi degré extérieur** : $d^+(v)$
#### Chemin
Type de graphe orienté, ou la suite d'arc peut se suivre dans le même sens !
- C'est à dire qu'on peut faire le tour du graphe.
#### Chemin hamiltonien
Chemin qui passe une fois et une seule fois par chemin !
- C'est un problème dure à résoudre car en terme de combinatoire il est exponentielle.

## Récapitulatif

sommet, noeud
arrêtes
degré
voisin adjacent
chaine
cycle


- sommet, neoud
- arc
- 1/2-degré intérieur, extérieur
- successeur, prédécesseur
- chemin
- ...

## Utilisation des graphes

**Utilisation** :
- Modélisation, représentation de problèmes
	- Exemple : plan de de ville, arbre généalogique, jeux, ...
- Résolution de problèmes
	- Gestion de planning de livraison, ..
- Outils

**Exemple d'utilisation** :
- Uber, Blablacar, routage réseau, arbre généalogique, réseaux énergétiques ...

## Connexité

Une graphe est connexe si toute paire de sommet est relier par une chaîne (*une chaîne peut être composer de plusieurs*)

- On peut atteindre tout les sommets depuis n'importe quelle sommet !

## Sous graphe

$G' = (V', E')$ est un sous-graphe de $G = (V, E)$ si $V' \in V$ et $E' \in E$  et ...

- En gros c'est une partie d'un graphe.

## Composante connexe

**Sous ensemble-maximal pour une propriété $\alpha$ (ou ici connexité)** :
- Sous ensemble tel que l'ajout d'un élément ne lui fait perdre la propriété $\alpha$ (ou ici connexité).

**Composante connexe d'un graphe $G$** :
- Sous-graphe de $G$ connexe maximal.

C'est à dire le sous graphe est connexe + si on lui ajoute un élément il n'est plus connexe.
- En gros tu prend le plus grand ensemble que tu peut qui est connexe.

**Application algorithmique**
- Le but est de parcourir tout les sommets du graphe en partant par le point de départ
- Si on as déjà parcouru le point on reviens à celui-la d'avant et on essaye d'aller à un autre sommet qu'on as pas encore parcouru
- On as terminé quand on est revenu au point de départ et qu'on ne peut pas allez vers des sommets non parcouru.
- Après avoir terminé de classer notre première composante connexe, on peut faire la même sur un autre sommet aléatoire qui n'est pas dans une de nos précédentes composante connexe.


## Forte connexité

Un graphe orienté est fortement connexe si tout couple de sommet $(u, v)$ est relié par un chemin (un chemin de $u$ vers $v$ et une autre de $v$ vers $u$)

### Composante de fortement connexe de G
- Sous graphe de G fortement connexe maximal (même chose que pour connexe tout court)

#### Application algorithmique

- Marquer tout les sommets du sous graphe avec des "+"
- Marquer toute les sommets sortant vers d'autres noeud par des "+"
- On refait la même chose mais en faisant le chemin des arrêtes entrante en les marquant par des "-".
- Note composante fortement connexe est tout les sommets marquer par des "-" et des "+"

**REMARQUE** :
Tout graphe réduit est sans circuit ! (car sinon les éléments serait fortement connexes)

## Tri topologique ou mise en ordre d'un graphe

Un tri topologique d'un graphe acyclique orienté est un ordre total sur l'ensemble des sommets, dans lequel $s$ précède $t$ pour tout arc d'un sommet $s$ à un sommet $t$.

- Il permet de nous renseigner sur quelle sommet est le premier et lequel est le deuxième.

En gros ceux qui ont pas de prédécesseurs sont premiers et ceux qui ont pas de successeurs en deuxième.

**Algorithme** :
- Le but est de prendre tout les sommets sans prédécesseurs et les mettre dans la liste
- Puis ensuite on prendre tout les sommets qui ont aucun prédécesseurs (sans compter ce qui sont déjà dans la liste,)
- Et on répete cette action jusqu'à ne plus avoir de sommets.

Je rappelle que c'est applicable dans les graphe sans circuit !

## Exploration en profondeur (DSF)

Le but est d'explorer de manière profonde un graphe afin d'atteindre un point donner.
- On avance dans dans le graphe jusqu'à qu'on ne puisse plus le faire en cherchant notre sommet cible.
- Si on ne peut plus avancer on recul et on essaye d'autres chemin


## Matrice d'adjacence

Soit $G = (V, E)$, un graphe, ou  $V = n$ tel que les sommets de $G$ sont numérotés arbitrairement $v_1, v_2, \dots, v_n$. La matrice d'adjacence $A$ de $G$ se rapportant à cette ensemble de sommets est la matrice $n \times n$ booléenne $A$ avec :
- $a_{i,j} = 1$  si $(v_i, v_j) \in E$ et 0 sinon.

en gros c'est matrice qui permet de savoir quelle quelle sommets sont lié :
- j'arrive pas à bien faire le latek et sans mermaid c'est chiant et pas trop clair mais j'espère t'as compris


## Fermeture transitive

Soit un graphe $G = (V, E)$ avec, $\tau(G) = (V, \tau(E)$ est la fermeture transitive de $G$ pour tout $(x, y) \in V^2$ :
- $(x,y) \in \tau(E)$ $<=>$ il existe un chemin de $x$ à $y$ dans $G$.

En gros dès qu'on peut lier deux point entre via un chemin, alors on ajoute une arrête entre les deux point !
- Elle nous permet de savoir quelles sont les points atteignable à partir d'un point.

**Algorithme** pour trouver la fermeture transitive d'un graphe (*Roy-Warshall*)
## Graphe partiel

Soit $G = (V, E)$ un graphe. Le graphe $G' = (V, E')$ est un graphe partiel de $G$, si $E'$ est inclus dans $E$.

- Autrement dit, on obtient $G'$ en enlevant une ou plusieurs arêtes au graphe $G$ (sans toucher à ses sommets)


Souvent on utilie ça pour retirer des arcs tout en gardant sa fermeture transitive


## $\tau$ - équivalence

**Définitions** :

- Deux graphes $G$ et $G'$ sont dit $\tau$ équivalent si ils ont la même fermeture transitive

- Un graphe $G'$ est dit $\tau$-minimal $\tau$-équivalent ) $G$ si $G'$ est une graphe partiel de $G$, $\tau$-équivalent à $G$ et si on retire un arc $G'$, on obtient un graphe qui n'est pas $\tau$-équivalent à $G$.

- Un Graphe $G'$ est dit $\tau$-minimum $\tau$-équivalent à $G$ s'il est $\tau$-minimal $\tau$-équivalent avec un nombre minimum d'arcs.

## Chaîne eulérienne

Une chaîne eulérienne d'un graphe $G$ est une chaîne qui passe par toutes les arêtes de $G$ une fois et une seule fois.

**Théorème d'Euler** :
Un graphe connexe admet une chaîne eulérienne si et seulement si le nombre de sommets de degré impair est 0 ou 2.

(Le degré d'un sommet et le nombre d'arrête qui parle de celui-ci)

**Algorithme de recherche d'une chaîne eulérienne**

```
Entrée : Un graphe G = (V, E) ayant 2 sommets de degré impair
Sortie : Une chaine eulérienne G'

On démarre sur un sommet qui est de degré impair

G' = G
Tant que G' non vide Faire
	Traverser une arête e qui n'est psa un isthme,
	sauf si on est sur un sommet de degré 1 dans G'
	G' = G'\{e}
Fin Tant que
```

(Un **isthme** c'est une arête qui lorsqu'elle est déconnecter du graphe on sépare alors un graphe en deux)