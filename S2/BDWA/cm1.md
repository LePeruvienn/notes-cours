# BDWA 

20 séance de 1h45 :

- On va d'abord voir les bases de données
- Puis travailler avec le framework Symphonie

La plupart des gens on déjà vu les bases de données donc c'est plutot un cours de rappel.

Controles :

- **1er controle** 2H, Examen écrit le 17/04/2026
- **2ème controle** 4H, Question sur le projet qu'on as fait le 11/06/2026

**PROJET** en groupe de 2, à rendre le 21/06/2026

# I. Introduction aux bases de données

## A. Base de données

Les bases de données sont utilisé dans tout les type des applications.
Elle permette de stocker, utiliser et d'analyser des données.

- Le terme base de données est apparu en 1964, inventé pour le programme Applo de la NASA.
- Une base de donnée (BdD ou BD) est une ensemble **structuré d'informations perssistante** partagées par plusierus applications d'une même entreprise

La structure des base de données est définis une seule fois.
Elle est utilisé par une ou plusieurs applications.

## B. Objectifs

- Stocker et organiser de grand volumes de données

## C. Système de gestion de base de données

C'est un logiciel qui permette d'intéragir avec une base de données pour :

- décrire et structurer les données
- défnir des contraintes
- intérroger et mettre à jour les données
- préservé les données
- ...

Ex: MariaDB, MongoDB, Postgre, Oracle


**Architecture de SGDB**

LDD : Language de définitions des donnée
LMD : Langauge de manipulations des données

## D. SGDB relationnels

- Créer en 1970-1980 : utilise une algère relationnel. Apparition du language SQL.
- Déductif : utiliser des prédicats.
- Orienté Objets : instance de classe hiérarchisées.

Très utiliser quand on as besoin de transaction sous contrainte et sécurisé (banque)

- Nouveau SGDB : **NoSQL**

Plutot utiliser dans les choses ou il ya pas de fortes contraintes (streaming, réseaux sociaux)

Elle suivent le principe **ACID**

- **A**tomicité : une transation s'éxecute au complet ou pas du tout (sans s'intérrompre)
- **C**ohérence : assure que chaque transaction mènera e système d'un état valide à un autre état valide
- **I**solation : deux transaction simultanées A et B n'interfère jamais.
- **D**urabilité : ne fois qu'une transaction est validée les données doivents être permanante.

# II. Un survaol des bases de données relationnelles

## A. Conception d'une BdD

Formalismes utilisés :

- Modèle conceptuel de données (**MCD**)
  - Aussi appelé modèle E-A (entité-association)

- Modèle logique de données (**MLD**)

## Modèles E-A

Une entité est un **objet physique ou abstrait** ayant une existence propre et pouvant être différencié par rapport aux autres objets.

Exemple

- Objets physiques : Maxence TOURNAUD
- Objets abstrait : vol numéro #IJ509 partant de Berlin

Contre exemple :

- Un livre de BdD écrit en 1975

Pas une entité car il n'est pas unique.

Une entité est décrite par l'ensemble de ses propritété appelées **attributs**.

Ne pas confondre le nom de l'attribut et sa valeurs ! 
- Nom : numéro de vol
- Valeur : #IJ509

Les valeurs doivent appartenir à un domaine ou typage spécifique
- l'attribut "nom" appartient au type "vol"

On peut alors avec ses propriété créer des instance d'un type ou domaine.


### Associations
Une association d'entité est un regroupement de deux ou plusierus entités pour décirre une ralité de l'organisation.

*On les cardinilitées à l'inverse du diagramme des classes* !

**Cardinilitées**
Elle représente le nombre maximum et minimun d'instance de cette entité
- 0, 1 et N (ou *)

**Associations réflexives**
C'est une association qui fait le lien entre plusieurs entités du même type.
- Ex: Des clients qui peuvent être parrain d'autres clients.

### Généralisations

Exemple: on est dans une entreprise avec 3 types d'employer :

- Programmeurs
- Chefs de projets
- Secrétaire

Ils on tous un noms et un identifiant

Mais pour certain type on veut des infos en plus

- Programmeur : langauge de programmation
- Chef de projet : plus haut diplome

**1ère solution**
- Une entité employer qui contient tout.

**2ème solution** :
- Un domaine employé avec une association avec le domaine métier
- Dans les associations on met les données nécessaire au métier.

**3ème solution** :
- Entité mère employé
- Après il y a une association catégorie, qui est lié à 3 entité (une pour chaque métier)



