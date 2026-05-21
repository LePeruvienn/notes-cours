---
title: CM3
---

# Logique propositionnelle classique

C'est de la preuve de programme en C.

- **Premier volet : la syntaxe** (sibananeyntaxe : Maxence tourne autour du naud 🤯)
- **Deuxième volet : la sémantique**
- **Troisième volet : le raisonnement**

## Preuve formelle et règle de déduction

=> Au lieu de s'interresser à ce qui est vrai on s'interesse à ce qui est déductible


Un **séquent** est un coucle noté $\Gamma \vdash F$ ou $\Gamma$ est une ensemble fini de formules et $F$ une formule.

- $\Gamma$ est appelé contexte du séquent
- $F$ est appelé conclusion du séquent

Le contexte est trs important. Il doit être explicite.

Les séquents sont des objets manipulés dans les déductions de preuves.

Attention, ne pas confondre $\Gamma \vdash F$ avec $\Gamma \vDash F$.

**RAPPEL** On peut lire $\Gamma \vdash A$ : "On peut déduire $A$ à partir de $\Gamma$"

- $\Gamma$ = Gamma (majuscule)

### Généralitées

LA régles de déduction sont présentées de la manière suivante :

$$
\frac{\Gamma_1 \vdash F_1 \ \dots\ \Gamma_k \vdash F_k}{\Gamma \vdash F}
$$

**Exemples** :

La partie du haut sont les *prémices*, il peut ne pas en avoir :

$$
(ax)\  \Gamma, A \vdash F
$$

On les appeles des *axiomes*.

Autres exemple plus classique,

$$
\frac{\Gamma \vdash A \Rightarrow B \ \ \Gamma \vdash A}{}
$$


### Notion de preuves

Une règles dans prémisses est un **axiome**.

Le but est de construire un arbre avec lequel on va pouvoir déscendre à l'aide des règles d'inférences.

### Déduction naturelle

Il ya trois sortes de règles :

1. Les règles élémentaires ( lrègle dite de l'axiuome et celle de l'affaiblissement)

2. Pour chaque connecteur, une ou plusierus règle d'introduction. Le connecteur apprat quand on lit la règle de haut en bas.


### Exercice d'exemple !


1. Démontrons que $(F \Rightarrow G) \Rightarrow  F \Rightarrow G$ est un théorème.

$$
\frac
{F \Rightarrow G \vdash F \Rightarrow G}
{\vdash (F \Rightarrow G) \Rightarrow (F \Rightarrow G)}
{\Rightarrow i}
$$

---

2. Démontrons que $F \lor G \Rightarrow G \lor F$ est un théorème

$$
\frac{}{}
$$
