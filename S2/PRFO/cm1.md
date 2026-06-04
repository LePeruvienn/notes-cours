---
title: CM1
---

# Introduction

Différent type de paradigme :
- Impératif - Fonctionnel - Objet

à choisir en fonction du problème qu'on veut résoudre

### Plan du cours

- Présentation du noyau fonctionnel de OCaml
- Types définis par l'utilisateurs
- Structure de liste `map`, `folds`, `zipper`
- Structure arboréscente

TPs et CMs

### Le fonctionnel c'est quoi ?

Tout est **valeur** : expréssions, *fonctions*
- Chaque fonction retourne par exemple toujours la même valeur

**Persistance** : **AUCUNE** modification
- Moins de bugs
- Corrections + facile à vérifier/prouver

Code concis :
- Lisibilité
- Moins de bugs
- Corrections + facile à vérifier/prouver

Similaire à méthématiques -> abstraction/haut niveau

Preuve **aisée** et naturelle

### ça sert à quoi ?

C'est niche pas trop utilsé sauf dans des cas spécial askip

### Différents languages

Beaucoup de language : Lisp; Haskell, Galina, SML

Et **OCaml** : ocaml.org ou caml.inria.fr

- Fonctionnel + traits impératifs + couche orientée objets
- Fortement typé
- Evaluation stricte

Plusieurs façon de compilé/interpréter :

- Compilé vers **natif** (*comme C*)
- Compilé vers *bytecode* (*comme Java*)
- Boucle d'itération (*comme Python*)

**Persistance** => Pas de gestion de la mémoire à la main !
- Du coup on ne fait jamais de free !

Askip au début c'est chiant mais après on se rend compte que ça évite beaucoup d'érreur donc on est content.


## CECI N'EST PAS UN COURS d'OCAML

C'est un cours de prog fonctionnelle
- Ya des livre cool sur ocmal mais askip faut pas les acheters

# Le Noyau Ocaml

## Les fondements

Programe = liste de :
- **expréssions**  -> évaluées pour obtenir des *valeurs*
- **déclarations** -> *noms* associées à des expréssions
- séparateurs `(`, `)` et `;`


Valeurs prédéfinies :

- Valeurs basiques (entiers, flottant, ...) **typées** ! Pas de conversion automatique
- Opération arithmétique logiques (`+`, `-`, `or`, ...) respectant les types
- Comparaisons 

Exemples :

```ocaml
# additions entre entiers
32 + 10 ;; # int = 32

# additions entre flottants
32.0 +. 10.0 ;; # float = 42.

# pas possible de mélanger les deux !!
32.0 +. 10 ;;

# opérations logiques
true && false # bool = false
(32 + 10 + 42)&&(32.0 +. 10.0=42.0);; # bool = true
(32+10<>666)&&(32.0 +. 10.0=42.0) # bool = true
```

- `+` additions entres entiers
- `+.` additions entres flottants
- `&&` *et* logique
- `<>` *équivalence* (même type)


## Déclarations

### Déclarations globales

But: donner un nom à une valeur globalements

```ocaml
let x = expr (* x : nom de la velur d'expr *)
let toto = 21 * 2
```
- identificateur -> expréssions
- la valeur ne sera **JAMAIS** modifié ensuite  !!

```ocaml
let titi = toto (* titi = 42, toto = 42*)
let toto = 3 * 222 (* toto = 666, titi = 42, toto = 42*)
```

La valeur de titi ? `42`


### Déclarations locales

But: donner un nom à une valeur locale

```ocaml
let x = e1 in e2 

let toto = 84 / 2 in
toto * 2
```

**Echainer** les déclarations

```ocaml
let x = e1 in
let y = e2 in
...
```

```ocaml
let x = e1 
and y = e2 in
...
```

Askip le deuxième c'est pas ouf de faire comme ça vaut mieux faire le premier

## Les expréssions

### branchements

```ocaml
if e1 then e2 else e3
```

Types : 
- `e1` de type `bool`
- `e2` et `e3` **du même type** !
- `else` **obligatoire**

Exemple :

```ocaml
if 666 < 42 then 666 else 42
```

### imbrications

Convertir des int en float avec `float_of_int` :

```ocaml
let x = 32.0 +. float_of_int 10
```

### Les fonctions

⚠️ **fonctions = valeur comme une autre**

```ocaml
(* Fonction anonyme *)
fun x -> e

(* Fonction nommée *)
let nom_fonction = fun x -> e

(* Fonction avec plusieurs paramêtre *)
let f = fun g -> (...(g e2)...)
(* Ici x et y en arguments *)
let mult_x_y = fun x -> fun y -> x * y 

(* Fonction qui retourne une foncion *)
let f = fun x -> (fun y -> z)
```

Typage $\alpha \rightarrow \beta$ 
1. `x` type de $\alpha$
2. `e` de type $\beta$ quand `x` de type $\alpha$

Application d'une fonction à un argument :
- Syntaxte `(my_fonc my_arg)`

#### Subitilité

```ocaml
let f = fun x1 -> fun x2 -> ... -> fun xn -> e
```
Application partielle (`f e1 ... ek`) avec `k < n` !
- De cette façon on applique pas toute la fonction !
- On as alors une nouvelle fonctione en valeur de retour.

Exemple :

```ocaml
let mult_x_y = fun x -> fun y -> x * y 
let mult_21_y = mult_x_y 21
```

De cette façon j'ai créer une nouvelle fonction qui prend 1 argument et qui le multiplie par 21 ! 

On peut créer de nouvelle fonction avec des fonctions !

## Récursion

Fonction récursive = cas de base + hypothèse de récurrence

```ocaml
let rec f = ... f ...
```

#### Exemple : la factorielle

Modélisation :
- **Base** : 0! = 1
- **Récurrence hypothèse** : n! = v -> $(n + 1)! =$ v $\times (n + 1)$

En code :

```ocaml
let rec fact = fun n ->
    if n = 0
    then 1
    else let hyp = fact (n - 1) in hyp * n
```

**Remarque** : récursion non terminale = pile d'appel non bornée = risque

#### Exemple : la factoriele générale

Une fonction qui prend $a$ et $n$ et qui retroune $a \times$ fact $n$.

$a$ est un accumulateur

```ocaml
let rec fact_gen = fun a n -> 
    if n = 0 then a
    else fact_gen (a * n) (n - 1)
```

**Remarque** : récursion **terminale** = pile d'appel bornée = **mieux**

## Type de produits

Ces expréssion ne sont pas la même !

- $(\alpha \times \beta) \times \gamma \ne \alpha \times \beta \times \gamma \neq \alpha \times (\beta \times \gamma)$

- $(\alpha \times \beta) \rightarrow \gamma \ne \alpha \times \beta \rightarrow \gamma$


#### Triplets

```
let (a, b, c) = f 1
```

## Inférence

Elle permet de créer des fonction qui' n'ont pas un type de retour fixe !

Une meme fonction peut alors retourner plusierurs type en fonction de comment elle est construite.

## Déclarations de type

Permet de créer ses propres types :

- déclaration : `type t = ...`
- affirmation : `(expr : t)` (*debug only, c'est pas bien  de forcer les types !*)

1. **Alias** = nouvea unom pour un type existant

```
type int_quad = int * int int * int;; 
```

2. **


## Constructeurs

- **Énumération**

```ocaml
type couleur = 
| Pique | coeur (* Majuscule en début de nom *)
| Carreau | Trefle
```

- Possibilité d'ajouter des étiquettes

```ocaml
type rang = 
| Roi | Dame |
Valet | Ordinaire of int (* Etiquette contenant un int*)
```

**Careau** = *constructeur*
- entrée : 0 argument
- sortie : valeur de type `couleur`

**Ordinaire** = *constructeur*
- entrée : 1 arg de type `int`
- sortie : valeur de type `rang`

## Filtrage

Opération inverse du constructeur = 
- Filtrage par strcture
- Mais pas par valeur !

```ocaml
match valeur with
| motif1 -> e1 (* constructeur + variable*)
| motif2 -> e2
| ... (* motifs tester DANS L'ORDRE !*)
```

Permtet d'éffecteur une action différente en fonction du constructeur (type)

Exemple :

```ocaml
let x = ...
match x with
| Roi -> Printf.printf "Wow"
| Ordinaire toto -> Printf.printf "Bof"
```

FIltrage = expréssion comme une autre -> utilisable partout

## Type inductifs

Type = ensebledéfini par les constructeur

```ocaml
type entier =
| Z           (* Avec Z qui définit le zéro *)
| S of entier (* Son entier prédecesseur *)
;;

(* Exemple *)

let mon_zero = Z ;; (* Zero *)
let mon_un = (S Z) ;; (* Un est le successeur de zéro *)
let mon_deux = S (S Z) (* Deux est le successeur de un *) ;;
...
```

Ici les champs de la "struct" sont des sortes d'enum (donc des champs mais qui ne sont pas lié à une valeur).

Si on veut les lié à une valeur on rajouter alors `of` ici par exemple `of int` pour qui que cette valeur peut prendre un `entier` ou une liste d'`entier`.

Exemple de transformation de notre type `entier` vers un `int` système.

```ocaml
let rec to_int fun e ->
    match e with
    | Z -> 0
    | S e -> 
        let v = to_int e in
        1 + v
;;
```

Exemple inverse `int` système vers notre `entier`

```ocaml
let rec from_int fun n ->
    if n = 0
    then Z
    else
        let v = from_int (n - 1) in 
        S v
;;
```


