---
title: CM2
---

## Mise en form normale conjonctive (FNC / CNF en anglais)

*FNC = Forme Normal Conjonctive*

(La forme Conjonctive c'est avec les $\land$ à l'exterieur et la disjonctive c'est avec les $\lor$ à l'extérieur)

- Un littéral: une varaible ou une négation de variable : $p$, $\lnot p$

- Une clause: une disjonction de littéraux : $p \lor \lnot q \lor r$

- Formule en FNC : une conjonction de clauses : $(p \lor q) \land (\lnot p \lor t) \land (\lnot r \lor \lnot p)$
  - Toutes les formules son dans des parenthèse
  - Les $\land$ sont à l'extérieur et les $\lor$ à l'intérieur


**Toute formule propositionel peuvent se mettre sous cette forme !**

C'est dans cette forme la que les *problems solver* ou *SAT* utilise cette forme.


### Démonstration = Méthode

1) On élimine les $\implies$, en transformant $F \implies G$ par $\lnot F \lor G$

2) On propage les négations vers les feuilles avec règles :

- $\lnot(F \lor G)$ devient $\lnot F \land \lnot G$
- $\lnot(F \land G)$ devient $\lnot F \lor \lnot G$

3) On simplifie les double négations

4) On distribue les $\land$ sur les $\lor$

5) On simplifie

**Attention** : Ceci rend la formule du coup plus grande souvent !

### Exemple

$\lnot(p \implies q \land q \implies p)$

1. On commence alrs par enelver les implications

$\lnot((\lnot p \lor q) \land (\lnot q \lor p))$

2. On propages les négations

$(\lnot(\lnot p \lor q)) \lor (\lnot(\lnot q \lor p))$

3. On simplifie les négation avec la loie de De Morgan

$(p \land \lnot q) \lor (q \land \lnot p)$

4. On fait la distribution pour inverser les $\land$ et $\lor$

$(p \lor ( q \land \lnot p )) \land (\lnot q \lor \lnot p))$

$((p \lor q) \land (p \lor \lnot p)) \land ((\lnot q \lor q) \land (\lnot q \lor \lnot p))$

5. Ici on as alors une FNC correcte mais on peut simplier encore !

$(p \lor q) \land (\lnot q \lor \lnot p)$

## Le problème SAT

Elle permet de trouve pour $F$ un modèle qui est satisfaisable.

- Entrée : une formule propositionelle F en forme normale conjonctive
- Sortie : $F$ est-elle satisfaisable? Si oui fournir un modèle (assignation qui satisfait $F$)

Pourquoi en FNC ?

- Forme normale utilisée par les algos
- F est satisfaites ssi chaque clause a au moins un litéral vrai
- Ensemble des clauses = ensembles de contraintes à statisfaire

On peut utliser SAT égamelement pour montrer une tataulogie : on montre que sa négation n'as pas de modèle (UNSAT)

### Utilité pratique de SAT

- Encoder un problème logique propositionnelle
- Utilier un souvleur SAT (ex: glucose, sat4J, minisat)
- Retranscire le modèle pour trouver une solution au problème

Application : coloriage de graphes, planification; modélisation de circuit, algo, protocole, model-checking, ...

- On as très vites des problèmes avec des milliers de variables
- Le temps de résolution de dépend pas juste du nombre de variable(ex des pb avec 1k variable peuvent se résoudre plus que des pb avec 100)


### Algorithme

**Algorithme incomplets**

- Avantage :
  - Possible de trouver un modèle rapidement si le problème est satisfaisable

- Inconvénient :
  - Mais pas sur de trouver un modèle mem si la formule est SAT
  - Si la forume est non-SAT, aucune réponse
  - A utiliser si on pense que la formule est SAT, si on as besoin d'un modèle

**Algorithme complets**
- Il donne toujours une réponse (si asssez de temps et d'espace)
- Principalement algorithme DPLL et optimisations


### Format Dimacs

Format **Dimacs** pour écire le problème


```dimacs
c Petite exemple de commentaire
c
p cnf 5 3
-5 4 0
-1 5 3 4 0
-3 -4 0
```
- première ligne : introduite par  `p` pour décrire le problème, avec le nb de variable (ici `5`) et le nombre de clauses (ici `3`)
- Après les ligne son toute les "ensemble" qui sont $\land$  entre eux
- Dnas chaque ligne un espace est un $\lor$
- Les variables sont numéroté, donc 5 = variable numéro 5
- les `-` sont des $\lnot$ (*not*)
- `c` introduit un commentaire
- `0` singnifie fin de ligne (on commence une nouvelle clause ensuite)


## Coloriage de graphes avec 3 couleurs

A chaque sommet $s$, on associe 3 variable propositionelle, $s_v, s_r, s_b$.

- Donc la couleurs de chaque sommet
- Le nombre de varaibles est $3 \times n$ avec le $n$ le nombre de sommet.


### Formalisation des contraintes

1. Pour chaque sommet $i = 1, \dots, n$ prend au moins une couleur

$$s_{i,v}, s_{i,r}, s_{i,b}$$

2. Pour chaque sommet $i = 1, \dots, n$ prend au plsus une couleur (si le sommet est en vert alors il n'est pas rouge)

$$
\lnot s_{i,v} \land \lnot s_{i,r}, \lnot s_{i,v} \land \lnot s_{i,b}, \dots
$$

3. Les duex sommet d'une arrête $(s_i, s_j)$ ne prennent pas la même couleur $c$, pour $1 \leq i \leq j \leq n$, pour $c \in \{v,r,b\}$

$$
\lnot s_{i,c} \lor \lnot s_{j,c}
$$

Pour avoir le **nombre de clauses**, on additionent le nombre de clauses des différentes règles :

1. $n$ clauses
2. $3 \times n$ clauses
3. $3 \times$ nombre d'arrête

## Des macros

On put formuler des problèmes à l'aide de macro

- `AtLeastOne(x1, x2, ..., xn)` : au moins une proposition vrai
- `AtMostONe(x1, x2, ..., xn)` : au plus une seul proposition vrai


## Coeur du fonctionnement d'un solveur SAT

### DPLL [1962]

Créateur : Davis, Putnam, Logemann, Loveland (😎)

Littéral pur :
- Si une variable apparait partout positivement (ou négativement), on peut assigner la valeur à *true* (ou à *false* dans l'autre cas)

Propogation unitaire (BCP Boolean Constraint Propagation)
- Si tout les litéraux d'une clause sauf un sont assigné à *false*, alors on doit nécessairement assigner ce dernier à *true*
- Comme on est dans une clause FNC, alors pour que la clause soit vrai il faut qu'on moins un soit vrai, si tout les autres proposition sont fausse, alors la dernière doit être marquer vrai ! cra sinon ça marche pas !!!

Et si aucun de ces deux choses marche alors, on va faire des tests par cas,

essayer si X variable est *true* puis si il elle est 
*false* pour voir ce qu'il se passe.



# CONTROLE A LA RENTREE !!!

