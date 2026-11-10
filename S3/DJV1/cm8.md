# Performances et optimisation

## Motivations

- Avoir du code plus performant (FPS 🤑)
- Avoir du code partageable (compréhensible facilement! Important quand on code pas seul)
- Avoir du code maintenable/scalable (pouvoir modifier ou étendre le code facilement)


## Performances

Il est difficile de prédire ce qui dégrade le plus les performmance d'un jeu.

Un code long n'uara pas forcément le même impact s'il s'execute :
- Pendant le temps de chargement
- occasinellement (ex: à chaque rammassage d'un objet)
- à chaque frame
- à chaque frame et sur beaucoup de game object

La diffculté peut aussi venir du manque de connaissance du fonctionnement du moteur interne d'Unity.

> NOTE: Il y a l'outils **Statistics** de Unity qui permet de récupérer les informations d'execution de la frame en cours et autres afin de mesurers les performmance du jeu.

## Profiler

- Il permet de comparer les performmance CPU et GPU.
- Il permet de voir quelles sont les fonctions les plus appelé et lequels prennet le plus de temps.
- Il permet d'analyser certaine frame précises.
- Il permet de voir si il y a des fuite mémoire


## GC Alloc

**GC alloc** singnifie de faire des allocations mémoire en `C#`. GC veut dire **Garbage Collector**, il s'agit donc de toute la mémoire gérée par celui-ci.

Le **GC** garde la mémoire utiliser et décider de la vider quand il le veut (il est chiant ce mec).

Donc il faut faire attention à comment on utiliser et gère cette mémoire ! (en gros on ce bat avec le garbage collector).

**IMPORTANT**:  On alloue de la mémoire seulement lorsqu'on instantie des classes ! Donc :
- Avec une classe : `new List<Foo>()` alloue de la mémoire gérée par le GC (sur le tas, c'est un `malloc` en fait)
- Avec une struct : `new Vector3()` n'alloue pas de la mémoire sur le GC car il est sur la pile ! (pas de `malloc`!)

Et oui, créer de nouvelle structure n'alloue pas de mémoire sur le tas, mais les classe oui!


> NOTE: Lorsqu'on travail avec des classes et qu'on las met dans une fonction, on passe toujours la référence : `foo(List<Foo> list) {}` ici il y a pas de copie! Mais si c'est une struct `foo(Vector3 v) {}` alors c'est bien une copie qui est effectué.

**Autres détails** : Les lambda, les delegate et les cast créer de la mémoire géré par le GC.


## Code

- Retirer les méthode Unity vide (**Il le appellent même si vide!!!!!**)
- Retirer les `Debug.Log()`

## Assets

Il y a des paramêtre d'import pour optimiser
- On peut utiiser les différent algos de compréssions de textures
- On peut désactiver le read ou write

## Temps de rendu

- Regarder le nombre de draw-call (regarder si les batch sont efficace)
- Voir le nombre de vertex (avoir un LOD ?)
- 

> **C'est quoi un draw-call** ? C'est lorsqu'on demande au 

> **C'est quoi un batch ?** Un batch est une technique de rendu permettant de réduire le nombre de draw-call


## UI & Audio

Il faut découper les écran en plusieurs canva :
- **Il ne faut avoir tout les écran sur le même canvas !!!!**
- Si un composant du canvas va être changer alors tout les autres partie du canvas vont être replacer (même ceux qui ont rien à voir)
- On peut aussi désactiver le `RaycastTarget` sur les éléments qui ne sont pas intéractif.


## Physique

- Simplifier les mesh collider et primitve si poosible
- Simplifier la matrice de collisions

Le Physics debugger est un outils qui permet de voir les perfs et autres ptet.

## Animations

- Utiliser une rig générique plutot qu'un humanoide
- Pour les animations simples, plutot les faire en code (ne pas utiliser d'animator!!)
