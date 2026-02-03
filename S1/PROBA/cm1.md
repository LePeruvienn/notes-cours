
# Opération sur les évenement

## Propriétées

- Commutativité :
    $E\cup F = F \cup E  \quad et \quad E \cap F = F \cap E$
    
    $(E \cup F) \cup G = E \cup (F \cup G) \quad et \quad (E \cap F) \cap G = E \cap (F \cap G)$
    
- Distributivité : 
    $(E \cup F) \cap G = (E \cap G) \cup (F \cap G) \quad et \quad (E \cap F) \cup G = (E \cup G) \cap (F \cup G)$

## Combinatoires

### Arragement (sans répétition)

**L'ordre des éléments compte !!!**

Un arragement de $p$ éléments parmis $n$ :
- $A^p_n = \frac{n!}{(n - p)!}$

Exemple :
- Tirer 4 boules numéroté de manière sucessive et sans remise.

### Arrangement (avec répétition)

Le nombre d'arrangement, **avec répétion**, de $p$ éléments parmi $n$ est donnée par :
- $n^p$

Exemple:
- un Code à 2 chiffre entre 0 et 9 : $10^2 = 100$ possiblitées


### Permutation (sans répétition)

Le nombre de permutation de $n$ éléments ;
    - $n!$

*Car en fait on prend un groupe Composer de $X$ éléments : ${x_1, x_2, x_i, \dots, x_n}$
Quand on va calculer les élement possible on fait faire d'abord $n$ qu'on mutiplie au nombre d'éléments restant donc $(n - 1)$ et ainsi de suite ce qui donne $n!$

Exemple :
- Un nombre à 3 chiffre composer d'une permutation entre $0, 1, 2$ vaut $3! = 3  \times 2 \times 1 = 6$

### Permutation (avec répétition)

Le nombre de permutation de $n$ éléments de l'esemble $E = \{p_1, p_2, \dots, p_k\}$
- $\frac{n!}{p_1! \times p_2! \times \dots \times p_k!}$

Utiliser quand on doit faire des purmutation avec différentes groupe, exemple :
- On dispose de 3 boules rouges, 2 boules blanche et 2 boules jaunes, 
     $\frac{7!}{3! \times 2! \times 2!}$

### Combinaisons (sans répétitions)

Ici **l'ordre des éléments de compte pas** et il n'y a pas de répétition !

Une combinaison $p$ éléments parmis $n$, avec :
- $C^p_n = \frac{n!}{p!(n - p)!}$

### Combinaisons (avec répétitions)

Le nombre de combinaisont $p$ avec répétion d'un ensemble à $n$ éléments.
- $B^p_n = \frac{(n + p - 1)!}{p!(n - 1)!}$

Exemple:
- On lance 9 dés numérotés de 1 à 6 et on note les numéros qui aparaisse pour chaque dés.