# AMPHI 2 JAVA : GARBAGE COLLECTOR

C'est qui qui gère la mémoire ?
- **en C** : C'est moii (en gros l'utilisateur)
- **en JAVA** : C'est la machine virtuel de JAVA (S/O tony)

**En JAVA** : 

Ce qui gère la mémoire en JAVA c'est ce qu'on l'on appelle un **ramasse-miette** (ou **garbage collector** en anglais).

## I. Pourquoi ramasse-miette ?

Porgrammes-> besoin de mémoire pendant leurs execution
**Exemples**: Allouer des variables, étendre/réduire leurs taille.

**Probléme**: mémoire limité -> Deux options
- Manuellement : Source de problèmes (c'est compliqué)
- Automatiquement : dépend de bliothèques/programmes (donc on peut pas tout controlé, c'est aussi moins performant)

Ici on va se pencher la méthode "automatique", c'est à dire qu'on va parle de comment fonctionne le ramasse-miette (ou garbage collector).

**ramasse-miette** : collecte des "détritus" = les céllules mémoire plus utlisé par les programmes.
- Dificille de prévoir quand une cellule mémoire "devient" détruite -> Probléme indécidable (Théorème de Rice).


**Comme c'est déficille on as décidier d'utiliser des héreuristiques**

**Manière ou on laisse l'utilisateur décidier** :
1) Laisser l'utilisateur se débrouiller (gestion explicite)

**Manière ou la mémoire est gérer automatiquement** :
1) Compter les références vers les variables
2) Gérer en fonction de la pile
3) D'autres approches : marquage/balayage ; collection par copie ; ramasse-miette générationels


## II. Gestion explicite

**Les allocations**
- Statique
- Par la pile
- Par les tas (dynamique)

### 1) Gestion à la C/C++

En gros c'est cool si l'utilisateur est intéligent sinon c'est de la merde.

## III. Gestion automatique

= ramasse-miette

**Il doit :**
- être capable de garder/retrouver les données encore actives
- libérer les aures

### Comment décider quand un objet peut etre libérer ?

- On ne peut pas le savoir précisément
- Définir un moyen de le savoir

#### 1er algorithme : comptage de références**

**Principe** :
- pour chaque objet, on lui donne un compteur (entier) indépendant qui correspond au nombre de références à cet objet.

**Avantages** :
- Simple à mettre en place

**Inconvénients** :
- Lorsqu'on fait de l'allocation dynamique, lorsqu'on désalloue avec le comptage de références cela créer des troue en mémoire.


En fait l'algo est plutot naif, mais efficace sont plus grand soucis est vraiment de crée des trous dans la mémoire.


#### 2eme algo : marquage / balayage

**Principe** :
- Déclencher le ramasse-miette par intermittence -> Il doit alors stopper tout les programme lorsqu'il nettoie la mémoire.
- A chaque collections :
  - Phase de marquage = "trouvé les vivants" (les variables encore référencé)
  - Phase de balayage = "recycler les morts" (libérer les case mémoire qui ont des variables non référencé)

**Implantation** :
- à chaque objet alloué, alloue un marqueur


**Algorithme de marquage**
```
Pour toutes les racines du graphe d'objet
- Pour chaque objet rencontré
  - SI l'objet est déjà marqué
    - passer à l'objet suivant
  - SINON
    - marquer l'objet
    - propager l'algorithme sur ses objets référencé
```


**Algorithme de balayage**
```
- Parcourir la liste de mes objets en mémoire
- SI un objet est marqué
  - Le démarquer
  - Le conserver
- SINON
  - j'intègre sa zone mémoire à celle de la zone mémoire vide
```

L'algo est vraiment cool en vrai il ya juste un petit problème :
- Lorsqu'il ya beaucoup de mémoire

#### 3éme algorithme : copie-compactage

- Faire un marquage
- recopier les vivants dans un autre espace mémoire
  1) de façon continue.

- Ce nouvel eapce devant le tas
- L'ancien sera le futur tas du ramasse-miette

En fait le but c'est de remplir les troues qu'il peut avoir dans le tas.
- Pour cela on utilise un algo qui permet
