---
title: CM1
---

# Logique propositionnelle classique

Les 3 volets de la logique :

- Syntax (les mots qu'on as le droit d'utiliser, grammaire)
- Sémantique (c'est ce qui donne le ses à ce qu'on écris)
- Raisonement (comment à partir de nos formule on peut déduire d'autres formules)

## La syntaxe

En logique du premier ordre ou aussi appelé logique propositionnelle, comporte seulement des varaible et des connecteurs logiques.

Exemple :

- Varaibles 

```
A: il pleut.
B: 2 + 2 = 7
```

Ici c'est la variable propositionnelle qui peuvent être soit vrai ou fausse

- Connecteurs

On peut construire des propositions grâce aux connecteurs

Il pleut **et** j'ai une voiture
Il pleut **ou** j'ai une voiture
...


**Comment écrire une formule de la logique des propositions ? (syntaxe)**

$\top$ : Toujours vrai
$\perp$ : Toujours faux
...


Exemple de propositions (aparte que la prof a fait)
```
0 est un entier naturel
Si N est un entier naturel alors N+1 est un entier naturel
```

**Semantique**

- *inductivemnt* signifie qu'il ya pas d'uatres moyen de formuler une formule propositionnelle
...


Toute formule peut être écris sous forme d'arbre.

## La sémantique

*ou que signifie cette formule.*

Le sens d'une formule est donnée par sa valeur ede vérité $\in$ {$true, false$}
table de vérité de $p \implies q$

|  p   |  q   | : |  R   | 
|------|------|---|------|
| vrai | vrai | : | vrai | 
| vrai | faux | : | faux | 
| faux | vrai | : | vrai | 
| faux | faux | : | vrai | 


On note $[F]_v$ la valeur de la vérité de la forume $F$ selon l'assignation $v$. Elle est définit par

- Si $p$ est une varaible alors $[p]_v = v(p)$
- $[ \perp ] = false$
- $[ \top ] = true$
- $[ \lnot F ] = false$ si $[F]_v = true$ et $true$ sub $[F]_v = false$

*Les autres tables de vérité pour tout les signes*
- ...


**Théorème**
Pour connaitre la table de vérité d'une formule il suffit alors de connaitre la table de vérité de ses variables.

Ce qui est chiant avec ça c'est que du coup on doit alors définir **tout les cas possibles**,
- Cela alors reviens à $2^n$ ligne pour $n$ varaibles !


Une formule est **satisfaisable** c'est quand **on peut trouver une assignation** tel que elle soit **vrai**.
- Exemple: un puzzle est good si il est solvable !

On écris alors $v \models F$ c'est à dire que la varaible $v$ permet de satisfaire la formule $F$.


Une **tautologie** est valide si elle **est vrai pour toute assignation**.
- Exemple $\lnot p \lor p$


$F$ est une contradiction si elle n'est **satisfaite pour aucune assignation**.

**Théroème**
- $F$ est une contradiction si $\lnot F$ une tautologie !


Rappel :
- $\sigma$ = plusieurs formule
- $F$ = n'importe quelle formule
- $v$ est une varaible;


Si $\sigma$ est un **ensemble de formule** et $v$ une assignation, on dit que **$v$ satisfait $\sigma (v \models \sigma)$ si $v \models F$ pour toute formule** $F$ de $\sigma$.

Une formule $F$ est une **conséquence sémantique** d'une ensemble de formule $\sigma$ : $\sigma \models F$ si toute assiangation $v$ qui satisfait $\sigma$ satisfait aussi $F$.

- On pourra alors en déduire que $\sigma$ se déduit par $F$ !

En gros si pour toute les cas de $\sigma$, $F$ à la même valeurs, et bas pour avoir sigma on peut prendre $F$ à la place.


Deux forumule sont **sémantiquement équivalente** (noté $F === G$) si l'un est conséquence sémantique de l'autre et vice-versa.


## Un petit problème

Un psychiatre pour logiciens écoute un de ses patients énumérer ses sentiments :

- H1: J'aime Marie ou j'aime Jeanne
- H2: Si j'aime Marie alors j'aime Jeanne

Le psychiatre à déduit que son patient aime Jeanne, pourquoi ?

D'abord on trouve les varaibles :

- $m$ : modélise "J'aime Marie"
- $j$ : modélise "J'aime Jeanne"

Ensuite nos formules :

- $f_1: m \lor j$
- $f_2: m \implies j$

Après on veut vérifier de son raisonement,

Cela reviens alors de vérifier que $j$ est une conséquence sémantique

- {$m \lor j, m \implies j$} $\models j$

Il faut alors que $f_1$ soit vrai et $f_2$ soit vrai aussi.

On dresse alors la table de vérité :

| $m$ | $j$ | $m v j$ | $m \implies j$ |
|---|---|-------|--------|
| true | **true** | **true** | **true** |
| false | **true** | **true** | **true** |
| true | false | true | *false* |
| false | false | *false* | true |

On cherche seulement les lignes ou $m \lor j$ et $m \implies j$ sont vrai ! (car il faut que les deux forume soit vrai)

Et dans ces cas alors alors on voit bien que j est toujours vrai !


1er cas :
- Supposons que $v(j) = true$, alors cqfd ! Le patient aime Jeanne !


2ème cas :
- $v(j) = false$
- alors selon H1 alors $v(m) = true$
- On en déduit alors selon H2 que $v(j) = true$ CONTRADICTION !!
- Comme il ya une contradiction on en déduit que ce n'est pas possible de pas aimé Jeanne.


## Théorème important (askip)

Petite list sympa de carte à piège à invoquer en contrôle lorsque c'est la merde en controle,
Garanti coute pas beaucoup d'élexir, marche bien avec les deck 3.3 cochon ballon.

**Thorème 1.** (*2 élexir*)
Soit $\sigma$ = {$F_1, \dots F_n$}. Posons $H_n = F_1 ^ \dots F_n$. Les 3 formulations sont équivalentes.

1. $\sigma \models F$
2. $H_n \implies F$ est valide
3. $H_n ^ \lnot F$ est infaisable (contradiction)

**Thorème 2.** (*1 élixir*)
$\sigma \models F \implies G$ si et seulemnt si $\sigma, F \models G$

**Théorème 3.** (*0 élexir* BROKEN 🤯)
$\sigma \models F$ si et seulement si $\sigma, F \lnot F$ est une ensemble contradictoire.

## Equivalences

Le but est de replacer petite à petit des bout de la formule par des éléments sont équivalent.

(*voir le diapo pour les équivalence remarquable*)
