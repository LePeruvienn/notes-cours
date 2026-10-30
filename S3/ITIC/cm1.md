# Introduction

**Modalité d'évaluation** :
- 1 Projet
- 1 Examen Final écrit de 2 heures.

## 1. Pourquoi tester les logiciels?

### Les test de logiciels au 21ème siècles

Le marcher logiciel est plus vaste et plus compétif, avec de grand impact sur les utilisateurs finaux. Il ya aussi d'avantage de logiciel embarqué à contrôler (trains, avions, ....)

Les logiciel deviennt des parties critique des systèmes il faut qu'il resent le plus fiable possible.

ça compte aussi pour le web.

Aussi il y a aussi le développement des **méthodologie agiles**, qui exerceent une préssion supplémentaire sur les testeurs.

### Exemples de pannes de logiciels importantes

- Le **Mars lander de la NASA**. Il n'est écrasé en raison d'un défaut lors de l'intégration des unités de mesures.

- **THERAC-25** (appareil de radiothérapie). L'appareil pauvais tuer les gens si ou l'utilisait (6 accident graves donc 3 patients décédé.)

- Explosion de l'**Ariane 5**, le logiciel as un un problème de précision décimal, ce qui as un créer un crash et à coûté es millions de dollars

### Par conséquent ...

**!! TESTER LES LOGICIELS DEVIENT DE PLUS EN PLUS IMPORTANT !!**

## 2. Objectifs des test des logiciels

### Définitions

ça peut paraître compliqué au vu de tout les scénario possible.

Les développeur parfois parte avec une définition érroner,

Ce **N'EST PAS** ❌ :
> - Tester les logiiels est le processus qui ontre qu'il n'y a pas d'erreurs.
> - Le but est de tester est juste de montrer qu'un programme éxécute correctement ses fonctionnalité.

Le vrai objectif est : **de montrer qu'un logiciel comporte des érreurs** ! ✅

Le but est d'éssayer de **trouver les érreurs** le plus tôt possible !

> NOTE: Aussi un logiiel qui fonctionne n'est pas forcément un logiciel qui n'as pas d'érreur !

### Deux aspect du test logiciel

1. Pendant la phase de programmation/conception

Contruire la qualité du produit lors de la phase de conception/programmation en partie par **les développeurs** (ex: tests unitaires), le but est de trouver le plus rapidement les bugs ossibles avant de les éliminer avant la mise en production.

2. Après que le prduit soit fini

Démontrer la qualité d'un produit à un tier une fois le produit términé, en général par une équipe dédiée ($\ne$ pas celle qui à développer le produit)

## 3. Qu'est ce que le test logiciel ?

### Définition du test par le niveau de réflexion

Tester peut petre vu comme un **processus destructitf** qui vise à essayer de tester le logiciel de façon à faire en sorte qu'il "casse".

Niveau à ne pas adopté
- Niveau 0 : il n'y a pas de différence entre le testong et le debugging
- Niveau 1 : Le but est de montrer l'exactitude
- Niveau 2 : Le but est de montrer que le logiciel fonctionne pas 

### Quelquest définitions

`Défaut/faute` : élément statique dans le logiel qui provoque une érreur

`Erreur` : état interne incrrecte du ogciel qui est la manifestation d'un défaut

`Défaillance/Anomalie` : caractérisée par des résultats inattendus ou un serverices non rendu **par la propagation d'une érreur**, e pendant le logiciel peut continuer de fonctionné.

`Panne` : arrêt total ou partiel du logciel.

Chaine de l'érreur : Défaut $\rightarrow$ Erreur $\rightarrow$ Défaillance $\rightarrow$ Panne

Causes des défauts :
- défauts humaines,  mauvaise compréhension, oublie, défaut de réalisation.

Types de défauts :
- Calcul,
- Logique
- Entrée/Sorties
- traitement des données

**Tout défaut ne conduit pas systématiquement à une défaillance ou panne**. Le logiciel peut continuer à fonctionner même dans ce cas la.

### Testing VS Debugging

**Testing** : Evaluer le logiciel en observant son execution.

**Test Failure** : Execution  d'un test qui ne retourne pas la valeur attendu par le test.

**Debugging** : Evaluer en logiciel en intervenant pendant son execution.

### Oracle

L'**Oracle** c'est ce qui exprime le résultat attendu.

Oracle simple à automatisé :
- résultat simple à vérifier
- Comparer à une référence

Oracle partiels mais automatisé :
- oracle basique : pass/crash (`assert` dans le code)
- ....

### Processus siplifié pour le test

1. On définit un cas de test (CT) à exécuter, un scénario à appliqué

2. On concréitse le case de tests en lui fournissant les données de test (DT)

3. On indique le résultat qu'on attend pour ce CT (prédiction de l'Oracle)

4. On execute le script de test testant le CT sur les DT

5. On compare le résultat obtenu à la prédiction de l'Oracle.

6. On rappote les résultats du test : succès / échec

### Fault & Failure Model (RIPR)

4 condition n

- Reachability : La

- Infection
- propagation

### Les difficultées

- **Choisir le cas de test / données de test**
- **Estminer le résultat attendu - le problème de l'oracle**

- Executé lesprogramme sur les données de tests (DTs)
- Calculer le verdict d'un test

> Attention aux système embarqué et physique! tester les trains, c'est compliqué on le fait souvent en simulation, pareille pour les verdicts des tests.

- Quand arrêter de tester ? Calcul d'une **couverture**.
- Rjouer les tests à chaque changement (*test de régréssion*)

> Attention, maintenance et optimisation ! Les tests doivent parfois chaque fois à être mit à jour, et aussi ça prend du temps de les rejouer!


**Limites des techniques de tests**

- Hypothèse sur la testabilité : systèmes sous test est déterminists (ou contrôle son non déterminisme), doit être initialisables

- Limites sur le résultat obtenu : on ne peut affirmer que le programme satisfait sa spécification. On ne peut le dire qu'avance un certain degrée.

### Différent rôles dans le test de logiciels

**Test Engineer** C'est lui que créer les tests avec leurs données, qui fait des cripts des test les lance, les analyse et fait les rapports.

**Test Manager** ...

### Conception des test et production de résultat de tests.

**Model-Driven Test Design**
- Model Structure
- Test requierments
- refinded requirments test spects

## 4. Test dans le cycle de vie du logiciel

**Place dest tests dans le cycle de vie du logiciel** : Il se passe souvent à la suite de la conception détaillé.

Dans le cas d'une organisation de projet en **cycle en v** à chaque étape du projet, on met en place en paralèle des test à vérifié.

### Validation et Vérification

**Vérification** Le but est d'ici vérifier que le sytème fait bien ce qu'il est censé faire.

La **Validation** à pour but de vérifier que le logiciel à été évelopper de manière correcte.

### Coût des test tardifs

Plus on test le logiciel à la fin, plus le coût des tests augmentes.

Il faut alrs intégrer les phases de tests le plus tôt possible.

## Les 3 dimensions du test

1. Avancement dans le développement
- `Test d'acceptation`
- `Test d'intégration` Tester un ensemble de composant du logiciel pour vérifier qu'il marche bien ensembles
- `Test unitaires` tester les fonctions d'une classe (ex: JUnit)

2. Sélection des tests
- `Test fonctionnels` ou `Boite noir`, le but est de tester le logiciel à partir des spécification depuis l'extérieur (sans regarder le code)
- `Test structurel` ou `Boite blanche`, Test chosis à partir du code source.

3. Ce que l'on veut tester (*les limites!*)
- `Test de bon fonctionnement`, faire une test qui comprend des entrée valides
- `Test de robustesse`, faire un test qui comprendre des données invalide.
- `Test de performances`, mesurer les performances du logiciel (temps d'execution, utilisation de la RAM, ect ...)

## 5. Test et méthodologie agile

### Pourquoi être agile ?

Le but d'agile est justement de repérer les soucis dans le développement d'un logiciel le plus rapidement possible afin de pouvoir itérer rapidement.

C'est quelque chose de très proche de la philosophie du test de logiciel ce qui est cool :)

### Test dans les méthodologie agiles

...

### Intégration continue

Le but est d'intégrer les test dans notre outils de SCM.

Par exemple dans gitlab, on peut intégrer le lancement de test lors de fusion de branche, ou par exemple lors de commit.

De cette façon on peut valider/rejetter un commit et détecter les érreur dans le code le plus rapidement possible

Il existe plusieurs outils permettant de mettre en place ce genre de pipelinepar exemple GIT CI/CD, Jenkins, ...

#### Processus


