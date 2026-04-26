---
title: TD2
---

# TD2 

## Exerice 1

$P1 = (x \lor y) \land z$

$P3 = (\lnot z \land \lnot y) \lor (x \land y)$

$P4 = (\lnot x \lor y) \land (\lnot y \lor z)$

$P5 = \lnot(\lnot x \lor y) \lor y$

1)

v1 : $x \rightarrow true, \space y \rightarrow true$
- $P1 =$ assignation de $z$ 
- $P2 =$ assignation de $z$ 
- $P3 =$ true
- $P4 =$  
- $P5 =$  

v2 : $x \rightarrow true, \space z \rightarrow true$
- $P1 =$ true 
- $P2 =$ assignation de $y$ 
- $P3 =$ assignation de $y$
- $P4 =$  
- $P5 =$  

v3 : $y \rightarrow true, \space t \rightarrow true$
- $P1 =$ assignation de $z$
- $P2 =$ assignation de $y$
- $P3 =$ assignation de $x$ 
- $P4 =$  
- $P5 =$ 

2)

## Exerice 2

On note :

- $p$ : nimochio chante
- $q$ : quasimio chante
- $r$ : rario chante

1) $\lnot p \implies q$
2) $q \implies (p \land r)$
3) $r \implies \lnot q \lor \lnot p$

Si on rend ces clauses FNC, On peut rajouter $\lnot p$ à la fin pour voir si $\Sigma \models p$

- Si on reçoit UNSAT  alors c'est ça veut dire que $p$ est toujours vrai !

## Exerice 4

Il ya 4 cartes différente de valeur $v \in \{R, D, V, A\}$

Il ya 4 couleur différente $c \in \{Coeur, Pique, Trèfle, Carreau\}$

Chaque valeur $v$ et couleur $c$ peut être associé à une position $i,j$ avec $i, j \in \{0, 1\}$.

Pour chaque position $p$ 

- AtLeast($A_p, R_p, D_p, V_p$)
- AtMost($A_p, R_p, D_p, V_p$)
- AtLeast($Coeur_p, Pique_p, Trèfle_p, Carreau_p$)
- AtMost($Coeur_p, Pique_p, Trèfle_p, Carreau_p$)

Pour chaque position $p$ et valeur $v$
- AtLeast($v_p$)
- AtMost($v_p$)

Pour chaque position $p$ et couleur $c$
- AtLeast($c_p$)
- AtMost($c_p$)


Clauses :

- $A_{0,0}$
- $Pique_{1,1}$
- $D_{0,1}$
- $R_{i,j} \implies Trèfle_{i,j}$
- $A_{i,j} \implies \lnot Carreau_{i,j}$


