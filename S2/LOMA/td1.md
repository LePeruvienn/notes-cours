---
title: TD1
---

# Logique Propositionnelle 1/2

## Exercice 1

- Si Alice et Julie viennet à Paris, Zoé viendra aussi
- Si Julie vient à Paris, Alice aussi
- Si Julie ou Zoé, l'une des deux au moins viendra à Paris

Variables :

- `a` : Alice viendra à Paris
- `j` : Julie viendra à Paris
- `z` : Zoé viendra à Paris

Formules :

- $(a \land j) \implies z$
- $j \implies a$
- $(j v z)$

Table de vérité :

| $a$   | $j$   | $z$   | $(a \land j) \implies z$  | $j \implies a$  | $(j v z)$     |
|-------|-------|-------|-----------------|-----------|---------------|
| true  | true  | true  |      true       |   true    |     true      |
| true  | false | true  |      true       |   true    |     true      |
| true  | true  | false |      false      |   true    |     true      |
| true  | false | false |      true       |   true    |     false     |
| false | true  | true  |      true       |   false   |     true      |
| false | true  | false |      true       |   false   |     true      |
| false | false | true  |      true       |   true    |     true      |
| false | false | false |      true       |   true    |     false     |

Ici on voit que seulemnt 3 cas peuvent satisfaire les règles


| $a$   | $j$   | $z$   | $(a \land j) \implies z$  | $j \implies a$  | $(j v z)$     |
|-------|-------|-------|-----------------|-----------|---------------|
| true  | true  | true  |      true       |   true    |     true      |
| true  | false | true  |      true       |   true    |     true      |
| false | false | true  |      true       |   true    |     true      |

On voit bien que dans tout les cas qui correspondent aux règle, zoé vient à paris dans ce moment la.
- Alors on peut en déduire que zoé viens bien à Paris !


**Deuxième méthode, conséquence sémantique** :

On doit alors démontrer que les 3 formules {$f_1, f_2, f_3$} sont une conséquence sémantique de `z`.
- On as alors : {$f_1, f_2, f_3$} $|= z$


On doit montrer que $v(z) = true$

Supposons que $v(z) = false$

Comme $[f_3]_v = true$ et que $v(z) = false

On déduit que $v(j) = true selone la règle $f1$.

Comme alors $v(j) = true$ alors selon la règle $f2$, $v(a) = true$

Mais si $v(a)$ est vrai ! Alors selon $f_1$ $v(z) = true$ ! Mais on as supposé qu'elle est fausse.
- Impossible ! Il ya une contradiction.

Donc comme on as provué que $\lnot  v(z)$ est une contradiction alors, $v(z)$ est toujours vrai.

## Exercice 2

- Tout membre non écossais porte des chaussettes oranges.
- Tout membre porte un kilt ou ne porte pas de chaussettes.
- Les membres mariés ne sortent pas le dimanches.
- Un membre sort le dimanche si il es Écossais.
- Tout membre qui porte un kilt est Écossais et marié.
- Tout membre Écossais porte un kilt.

Variables :

- `e` : membre est écossais
- `k` : porte un kilt
- `o` : porte des chaussettes orange
- `d` : sortir le dimanche
- `m` : est marié

Formule : 

- $a_1$ : $\lnot  e \implies o$
- $a_2$ : $k \lor  \lnot  o$
- $a_3$ : $m \land \lnot  d$
- $a_4$ : $(e \implies d) \land (d \implies e)$
- $a_5$ : $k \implies e \land m$
- $a_6$ : $e \implies k$

Démonstration :

Le but est de démontrer que ces règles ne sont pas satifaisable simultanément.

- On va alors faire une démonstration par l'absurde

On va supposer qu'il existe un membre qui peut respecter toutes ces règles simultanément.


Supposons que v existe $[ a_i ]$ = true pour tout $H_i$


#### Code Minisat

```
c e = 1
c o = 2
c k = 3
c m = 4
c d = 5
c
p cnf 5 9
1 2  0
3 -2 0
4    0
-5   0
-1 5 0
-5 1 0
-3 1 0
-3 4 0
-1 3 0
```

```
UNSAT !!
```
