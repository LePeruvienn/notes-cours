# Modèle Logique de Données (MLD)

- C'est en fait un modèle qui se rapporche plus du SQL qu'on va implémenter ensuite
- En fait souvent on fait MCD -> MLD -> SQL

## Syntax MLD

Exemple de MLD :

```
Employé(__num__, adresse, nom, prenom no_dept => Département)
Département(__num__, nom)

Avec no_dept Not Nul, Département IN Employé
```
- Les clé primaires son sous-ligné
- Les clé étrangère son représenter avec `nom_clé_etrangère => nom_table`

Ensuite après avoir définis notre table on définis notre contrainte

- `Not null` la clé peut pas être null (🤓)
- `A IN B` c'est à dire qu'il faut créer la table `A` avant la table `B`.

## Traduction E-A -> relationnel

Le but est de transformer notre MCD en tableaux relationnel,
Parfois on doit transformer certaine Entité-Association en table SQL si besoin.

La transformation se fait en 5 étapes :

1) Tranformations des entitées non faibles
   - Ex: `E(C, A)`

2) Transformation des entitées faibles.
   - Ex: `E2(C => E, C2, A2)`
   - Avec `C => ` la clé primaire de l'entité forte lié à l'entité faible (ça sera la clé étrangère de la table)
   - Avec `=> E` C'est la table pour savoir d'ou viens cette clé étrangère

3) Transformation des association binaire mono-valuées (en gros * vers 1)
   - Ex: `E2(C2, A2, C1 => E1, A3)`
   - Exemple chelou, t'es obligé d'avoir `X,X` à E1 et `Y,1` à E2 comme cardinalité.
   - Avec `X,X` peut pas être `1,1` et `Y` peut être 0 ou 1.

4) Transformation des association binaires multivalué dans les 2 sens (en gros *, *)
   - Ex: `Ass(C1 => E1, C2 => E2, A3)`, en gros l'association créer alors une nouvelle table !

5) Transformation des association n-aires (n > 2)

## Exemplle avec généralisation

Exemple avec une table employé qui possède plusieurs catégories (Programmeur, ChefProjet, Secrétaire)

```
Employé(__num__, Nom, Adresse)
Programmeur(__num__ => Employé, Language)
ChefProjet(__num__ => Employé, Diplome)
Secrétaire(__num__ => Employé)
```

## Formes Normales

**Dépendance Fonctionnel**
- Soient **X** et **Y** sont des attributs (simples ou composé d'une relation)
  - **Y** est **fonctionnellement dépendant** de **X** si et seulement si à toutea valeurs de **X** correspond au plus à une valeur de **Y**.
  - On dit aussi que **X** déterminé **Y**.
- Collaire : si 2 n-uplet ont même valeur sur les attributs X alors ils ont même valeurs sur ceux de Y.

**Dépendance Fonctionnel Elémentaire**
- On dit que la dépendance fonctionnelle X -> Y est éément si il existe pas X' $\in$ X tel que X' -> Y.

**1FN (1ère fome normal)**
- Si tous ses attributs sont simple, ça veut dire si ils ont pas eux même des relations
- Un attributs atomique (il est pas multivalué et pas composé)


**2FN (2ème fome normal)**
- Il faut valider la première forme normal.
- Toutes les DF issues de la clé sont élémentaires, c.à.d tout attribut non clé dépend de la totalité de toutes les clés.


## Restriction

Regarder diapo page 27, le schéma explique mieux
