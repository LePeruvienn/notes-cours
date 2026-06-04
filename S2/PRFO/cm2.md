# Noyau (pas très fonctionnel)

## Exceptions

Comme en objet : vameur en cas d'erreur

```
1/0;;
Exception: Division_by_zero
```

- affinage du typage (fonctions partielles)
- pour intérrompre le calcul, et peut être poru le reprendre plus tard autrement


Définition :

```ocaml
exception Mon_exception
exception Autre of string
```

Levée : 

```
raise Mon_exception
raise (Autre "Impossible de faire le calcul")
```

Rattrapage : cf objet

```ocaml
try e1 wth Motif_exc -> e2
```

1. Evaluation de e1 sans exception -> valeur de e1

2. Exception dans e1
- a) ...
- b) ...

## Listes

Structures dynamique

Structure : 
- Vide
- Ajout de `e` en tête de `1`

```ocaml
type lise_d_entiers = 
| Liste_vide_d_entiers
| Listes_avec_un_elmentes_au_moins of (int * liste_d_entiers)
```

```ocaml
let ajout e l = Listes_avec_un_elmentes_au_moins(e, l)
;;

let liste_est_vide = fun l ->
    match l with
    | Liste_vide_d_entiers -> false
    | Listes_avec_un_elmentes_au_moins(_, _) -> false;;

let rec mem = fun e l ->
    match l with
    | Liste_vide_d_entiers -> false
    | Listes_avec_un_elmentes_au_moins(e', l') ->
        if e = e'
        then true
        else mem e l';;
```

## Itérateurs

### `map`

Parcours de structure + Construction de résultat portant sur la structure.

`map` : liste des résultats de l'application d'une fonction sur chaque éléments.

Définition 

```
map f (a1::...::an::[])
```

En gros c'est : `(f 1), (f 2), (f 3), ...`

```ocaml
let rec map = fun f l ->
    match l with
    | [] -> []
    | e'::l' ->
        let vl = ....
....
```

### `fold`

Parcours de structure + Construction de résult portant sur la structure.

`fold` : composition d'application d'une fonction sur les éléments

listes deux sens possible

- `fold_left f accc (a1::..::an::[])` $\rightarrow$ `f(...(f acc a1)...)an`

```ocaml
let rec fold_left = fun f acc l ->
    match l with
    | [] ->
    | e'::l' ->
        let acc' = f acc e' in
        fold_left f acc' l' ;;

let rec fold_right = fun f l acc ->
    match l with
    | [] -> acc
    | e'::l' ->
        acc' = fold_right f l' acc in
    f e' acc'
```

## Zipper

Listes : ajout au milleur + persistance => copie inutiles

Solution : avoir un point de vue **local** (cf. liste doublement chainées)


