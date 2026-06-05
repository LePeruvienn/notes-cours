---
title: CM3
---

## Zipper

Listes : ajout au milleur + persistance => copie inutiles

Solution : avoir un point de vue **local** (cf. liste doublement chainées)

```ocaml
type 'a zipper = {
    left : 'a list; (* Toute les valeurs à GAUCHE du point courant*)
    right: 'a list; (* Toute les valeurs à DROITE du point courant*)
}
```

`left` : les éléments précédents ;
`right` : les éléments suivants

ça permet de naviguer facilements dans la liste !

NOTE : ℹ️ **L'élément actuelle aquel on pointe est le PREMIER ELEMENT DE LA LISTE DE DROITE**


### Fonctions du Zipper

```ocaml
empty : 'a zipper
leftmost, rightmost, is_empty : 'a zipper -> bool
insert : 'a zipper -> 'a zipper

(* Ces fonctions peuvent échoués : *)
delete : 'a zipper -> 'a zipper
go_left : 'a zipper -> 'a zipper
go_right : 'a zipper -> 'a zipper
get : 'a zipper -> 'a
```
### Exemple

```ocaml
let empty =
    {
        left = [];
        right = [];
    }
;;

let is_empty z =
    z = empty
;;


let left_most z = 
    z.left = []
;;

(* Il faut faire attention ! *)
(* Le premier élément de la liste de droite est notre curseur *)
let right_most z = 
    match z.right with
    | [] -> true
    | [_] -> true
    | _ -> false
;;

(* Soucis ici on avance pas dans la liste ! *)
(* - si on fait plusierus insertions alors, *)
(*   les éléments ne seront pas dans le bonne ordre.*)

(* Mais en fait pour moi c'est logique on ajoute juste l'élément au début de la liste de droite *)
let insert e z = 
    {
        left = z.left;
        (* On ajoute notre élément devant la liste right *)
        right = e::z.right; 
    }
;;

exception Impossible_vide

let delete z = 
    match z.right with
    | [] -> raise Impossible_vide
    | _::r ->  {
        left = z.left;
        right = r
    }
;;

let go_left z = 
    match z.left with
    | [] -> raise Impossible_vide
    | e::l -> {
        left = l
        right = e::z.right
    }
;;

let go_right z = 
    match z.right with
    | [] -> raise Impossible_vide
    | e::r -> {
        left = e::z.left
        right = r
    }
;;

let get z = 
    match z.right with
    | [] -> raise Impossible_vide
    | e::_ -> e
;;

let insert_and_move e z =
    let z' = f rightmost z then z else go_right z in
    insert e z'
;;

(* Créer un Zipper depuis une liste *)
let from_list l =
    {
        left = [];
        right = l
    }
;;
```

On peu remarquer que du coup quand on print un zipper qui veut modéliser cette liste : `[1, 2, 3, 4, 5 ]`

Si on se place on millieu on aura : 

```ocaml
left : [2, 1], right : [3, 4, 5]
```

Ici on voit que la liste left est à l'envers, donc si on veut depuis cette liste vers une liste clasique il y a plusieurs méthodes :

1. Allez le plus à gauche posible puis renvoyer la liste de droite

```ocaml
let lot_list = fun z ->
    if left_most z
    then z.right
    else lot_list (go_left z)
;;
```

Petit soucis avec ça, à chaque go_left on créer un nouveau zipper donc c'est pas très opti

2. On retourne la liste de gauche on la retourne, puis on retourne la liste de gauche concaténer avec la liste de droite

```ocaml
let lot_list = fun z ->
    (List.rev z.left)@z.right
;;
```

vvv J'ai pas trop compris celle la :/

```ocaml
let lot_list_la_bonne z = 
    List.fold_left ( fun l e -> e::l )
        z.right
        z.left
;;
```

### Itérateurs avec Zipper

Quand on créer une nouvelle structure de type liste, il faut prendre l'habitude de créer de 2 à 3 itérataeur pour celui-ci, c'est ce qu'on va faire avec le zipper.

Ici on veut appliquer la fonction `f` à tout les éléments du zipper (faire un map quoi)

```ocaml
(* Ici on peut juste faire un map de sur right et left *)
let map_zipper f z = 
    {
        left = List.map z.left ;
        right = List.map z.right
    }
;;

let _ = map_zipper (fun n -> 2 * n) zipper_cible
```

Pour les fold c'est plus chiant

```ocaml
let fold_right_zipper f z acc = 

    (* Partie droite *)
    let acc0 = List.fold_right f z.right acc in

    (* Partie gauche : il faut le parcouri de gauche à droite !*)
    (* Il faut inversé acc et e sinon on peut avoir des problèmes *)
    List.fold_left (fun acc e -> f e acc) acc0 z.left
;;


let fold_left_zipper f z acc =
    
    (* Partie gauche *)
    let acc0 = List.fold_right (fun acc e -> f e acc) z.left acc in

    (* Partie droite *)
    List.fold_right f z.right acc0
;;
```

## Manipulation de listes

```ocaml
List.rev z (* Inverse la liste *)
liste1@liste2 (* Concatenne 2 listes *)
elt::liste (* ajoute l'élément au début de la liste*)
liste::elt (* ajoute l'élément à la fin de la liste*)
```


## Arbres

C'est des listes chainée en gros mais il ont plusieurs sucesseur au lieu d'un seul

### Définition

```ocaml
type 'a tree = 

    (* Soit noeud vide *)
    | Empty

    (* Soit on as un noeud, qui as :         *)
    (* - un noeud gauche, droit et sa valeur *)
    (* - un noeud droit                      *)
    (* - sa valeur                           *)
    | Node of ((a' tree) * a' * (a' tree))
```

**NOTE** : `'a` ça définit n'importe quelle type c'est un peu comme un template.
- en gros on pourrais faire : `int tree` ensuite ect ...
- Ici on dit on prend un type qui s'apelle `a` qui représente n'importe quelle type
- Si on met le `'` après le a ça créer juste une varaible qui s'appelle `a'` PAS UN TYPE !!

### Itérateurs

Ce qui est chiant dans les arbre c'est se balader dessus

Le map est plutot simple on applique juste une fonction récurcive sur tout les noeuds

```ocaml
let map_tree f t = 
    match with
    | Empty -> Empty
    | Node(fg, r, fd) ->
        let r' = f r in
        let  fg' = map_tree f fg in 
        let  fd' = map_tree f fd in 
        Node(fg',r',fd')
;;
```

Pour les folds il y a plusieurs façon de parcourir la l'arbre


