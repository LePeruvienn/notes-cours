---
title: CM4
---

# Arbre : n-aires

Arbre avec un nombre de fils variables.

```ocaml
type 'a arbre =
| Empty
(* Ne peut pas être sous arbre d'un arbre non vide *)
| Node of 'a * ('a arbre list)
```

Ici ce qui est chiant par contre c'est qu'on peut écrire de différente façon la même chose : 

```ocaml
let t1 = Node(3 [Node(5, [])])
let t1 = Node(3 [Node(5, [Empty])])

(* Mais ça renvoie false*)
let faux = t1 = t2;
```

Donc en fait ce type d'arbre à plusieurs problème.

**SOLUTION 1.**

on peut créer une fonction afin de construire des ce type sans ces problèmes

```ocaml
let rec vire_empty la = 
    match la with
    | [] ->
    | Empty::la' -> vire_empty la'
    | Node(v1, l1)::la' -> Node(v1, l1)::(vire_empty la')
;;

let build_node v la =
    let la' = (* retourner la liste privé de ses Empty *)
        (* List.fold_right (fun t acc -> 
            match t with
            | Empty -> acc
            | Node(_,_) -> t::acc
        ) *)

        List.filter(funt t -> t <> Empty) la
    in
    Node(v, la')
```

**SOLUTION 2.**

Faire des types compatible différents selons les cas.

```ocaml
type 'a ne_arbre =
    | Node of 'a * ('a ne_arbre list)
;;

type a' arbre =
    | Empty
    (* On met ça pour que le type soit compatible *)
    | Ne of 'a ne_arbre
;;
```


En fait parfois notre type de données est pas suffisament précis. Donc il faut faire des fonction constructeur pour régler les soucis et/ou faire des type différent pour régles les soucis.

**NOTE** : `'a` se lit "*prima a*"

En fait ça permet de créer un type générique (`T` ou ici `'a`) qu'on peut remplacer par d'autres quand on utilise le type.
- On peut faire alors du coup des node de type `int`, `float`, ...


**NOTE** : `'a * (...)` permet en fait de dire que c'est un champ `'a`, avec ensuite des valeurs dans `( ... )`.
- Dans notre exmple :  `'a * ('a arbre list)` 
- On as un élément `'a` qui est la valeurs, puis les noeud suivant qui sont dans la liste.


## Arbres spécialisé

Avant on as fait des arbres génériques mais on peut aussi faire des trucs plus spécialisé.

```ocaml
type bexpr = 
| Val of bool
| And of bexpr * bexpr
| Or of bexpr * bexpr
| Not of bexpr
;;

let rec find_value expr =
    match expr with
    | Val b -> b
    | And(e1, e2) ->
        let v1 = find_value e1 in
        let v2 = find_value e2 in
        v1 && v2
    | Or(e1, e2) ->
        let v1 = find_value e1 in
        let v2 = find_value e2 in
        v1 || v2
    | Not(e1) ->
        let v1 = find_value e1 in
        !v1
;;
```


## Constatation

Il ya des problème dans Ocaml :

- Conflit de noms
- Représentation concrête polluante
- Duplication

SOLUTION : **Modules** !

##  Modules

### Généralité

Gros code : petites unités cohérentes, permet une meilleur maintenance et réutilisabilité.

**Module : Corp (privé) + interface publique**
- interface : ce qu'on expose avec l'extéireur
- corps : comment le code fonctionne

### Principes

| Interface                    | Corps                 |
| -----------------------------|-----------------------|
| Déclaration/Définitions types| Définitions types     |
| Déclaration de fonction      | Définitions fonctions |
 
Les types peuvent être juste déclarer dans l'interface et pas défini (type abastrait)


### Fichiers

- `.mli` = Interface
- `.mk` = implémentation

Compilation **séparer** avec `ocaml -c`
- D'abord `.mli` -> `.cmi`
- Ensuite `.ml` -> `.cmo` (ou `.cmx`)

Utilisation : dénomination par **majuscule**
- En gros : `list.mli` -> `List.filter` (le module doit être utiliser avec une majuscule au début !!!)

Un seul fichier à compiler : **le fichier modifié** !

### Exemple de module

**Interface** `ensemble.mli`

```ocaml
type ensemble (* Type abstrait d'entier *)

(* Variable : *)

val empty : ensemble (* l'ensemble vide, la valeur sera définit dans le corps *)

(* Fonctions : *)

val add : int -> ensemble -> ensemble (* ajout un un int à un ensemble et renvoie le nouvelle ensemble *)

val mem :  int -> ensemblem -> bool
```

**Utilisation** `main.ml`

```ocaml
let test1 = Ensemble.is_empty Ensemble.empty = true ;;
let test1 = Ensemble.is_empty (Ensemble.add 1 Ensemble.empty) = false ;;
...
```

**Compilation**

```bash
# Génère le fichier `ensemble.cmi`
ocamlc -c ensemble.mli

# Génère le fichier `ensemble.cmo`
ocamlc -c ensemble.ml

# Génére du coup le `main.cmi` et `main.cmo`
# Ici il cherche les `.cmi` des modules dans le dossier ou est lancer la commande
ocamlc -c main.ml

# Pour creéer une executable
# (Il faut que les module soit avant le main !)
ocamlc -o main ensemble.cmo main.cmo
```

## Ensembles

Structure **dynamique**

Fonctions :
- Vide + test vacuité$
- Ajout suppressions
- ...

### Listes

- Facile à implémenter
- Temps de recherche insertion


```ocaml
let rec mem e s =
    match s with 
    | [] -> false
    | e'::s' ->
        if e = e' then true
        else mem e s'
;;
```

### ABR

**Suppression** :
Lors du remove si on veut supprimer un noeud qui as des enfant. 
- On regarde le plus petit élément du sous arbre droit ou gauche
- On le remplace par la valeur du noeud
- Puis on ajoute l'arbre 

```ocaml
type ensemble = 
    | Empty 
    (* rg, r, rd avec rg < r < rd*)
    | Node (ensemble * int * ensemble) 
;;

let rec add e s =
    match s with
    | Empty -> Node(Empty, e, Empty)
    | Node(fg, r, fd) ->
        if e = r then s
        else if e < r then 
            let fg' = add e fg in
            Node(fg', e fd)
        else if e > r then
            let fd' = add e fd in
            Node(fg, e fd')
;;

let rec meme e s =
    match s with
    | Empty -> false
    | Node(fg, r, df) ->
        if e = r then true
        else if e < r then
            then mem e fg
        else
            then mem e fd
;;

let rec get_min s = 
    match s with
    | Empty -> assert false
    | Node(Empty, r, fd) -> (r, fd)
    | Node(fg, r, fd) -> 
        let (vmin, fg') = get_min fg in
        vmin, Node(fg', r, fd)
;;

let rec remove e s =
    match s with
    | Empty -> s
    | Node(fg, r, fd) ->
        if e = r  then
            if is_empty fd
                then fg
            else
                let (vmin, fd')= get_min fd in
                Node(fg, r, fd')
        else if e < r then
            let fg' = remove e fg in
            Node(fg', r, fd)
        else
            let fd' = remove e fd in
            Node(fg, r, fd')

```

Le problème ici c'est que l'arbre n'est pas automatiquement équilibrer.

### AVL

AVL = ABR + automatiquement équilibrer

```ocaml
type ensemble = 
    | Empty 
    (* rg, r, rd avec rg < r < rd*, et h représente la hauteur *)
    | Node (ensemble * int * ensemble * h) 
;;

let height t =
    match t with
    | Empty -> 0
    | Node(fg, r, fd, h) -> h
;;

let node fg r fg =
    let hg = height fg in 
    let hd = height fd in
    let h' = 1 + max hg hd in
    Node(fg, r, fd, h')
;;

let balance fg r fd = ... ;;

let rec add e s =
    match s with
    | Empty -> Node(Empty, e, Empty)
    | Node(fg, r, fd) ->
        if e = r then s
        else if e < r then 
            let fg' = add e fg in
            balance fg', e fd
        else if e > r then
            let fd' = add e fd in
            balance fg, e fd'
;;
```
