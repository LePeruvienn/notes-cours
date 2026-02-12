# 2. Fonctions principale d'un réseau

## Modèle d'interconnexion

### Le modèle de référence

Le modèle **OSI** (Open Standart ), qui comporte plusieurs couches.

**Couches** :

7) Application
6) Présentation
5) Session
4) Transport
3) Réseau
2) Liaison des données
1) Physique


On découpe les fonctionnalité en plusieurs couche afin de pouvour évoluer chaque couhe de manière indépendnate.

Aussi il ya une abstraction entre les couches, on pas besoin de connaitres les détail d'implémentation des autres couche afin de pouvoir communiquer entre elles


**Dialogue vertical** (même machine) : services
- La couche de niveau N utilise les serice de la couche N-1 et fournit des services à la couche N+1
- Ce dialogue est possibe grace à l'abstraction des interfaces appelé SAP (Service Application Point)


**Dialogue horizontale** : Communication virtuelle (entre machines différentes)
- Une couche N est continuée d'ensemble d'entités, formant un sous-système de niveau N
- Une couche N ne peut dialoguer qu'avune une couche de même niveau N
- On est obligé de traverser toute la pile afin de passer des informations entre machine

#### Décrire un Protocole

**PDU** : Protocole Data Unit, c'est des messages envoyer entre machines.

**MSC** : un scénario d'achange (une execution possible)

**Notation automates** :

- `?X` : réception du message X (évenement d'entrée)
- `!X` : envoie du message X (action de sortie)

Exemple : ?QCAVA !RCAVA = recevoir QCAVA puis envoyer RCAVA

## Le Modèle OSI

### Rôle des couches

#### 7) Application

- Le point de contact entre le processus applicatif et le réseau
- C'est l'application et l'utilisateur

#### 6) Présentation

- Formate les données d'une façon qui ne dépend pas de l'OS
- Compréssion de donnée, cryptage

#### 5) Session

- Synchronisation des echanges, en créant une session entre les processus différentes
- Définit le type de communication (bi direction, ...)

#### 4) Transport

- Elle assure l'acheminement des données
- Elle fait la communication de bout en bout entre processus applicatif
- Elle controle aussi le flux, les érreurs, ...

#### 3) Couche réseaux

- Elle assures la communication entre les équipement intermédiare
- Par exemple les routeurs, switch, ...
- En gros c'est elle qui gère le routage, dit quelle paquet va ou


#### 2) Liaison

- Structure les données,
- Elle assure la transmission des données physiques

#### 1) Physique

- Gère la connexion physique sur le réseaux, des messages binaires,

#### Exemple

Un utilisateur fait un message vocal :

- Ses données vont traverser les couche de **haut en bas** afin d'envoyer le messages à son interlocuteur.

- Il va passer par des équipement avec des niveau de différente :
    - Switch (niveau 2) : as besoin que de deux couche, Physique et Liaison (adress mac + cable)
    - Routeur (niveau 3) : Physique et Liaison, Réseau (... + adress IP)

- Le message arrive au serveur, les données vont alors tranverser les couches OSI de **bas en haut**.

## Les Unité de données de Protocole (PDU)

Composer de :

| Entête | Données | En-queue |
| --------------- | --------------- | --------------- |


- Il s'agit pour chaque couche de définir la forme des "entete + données" échangée avec la couche homologue.
- Chaque couche possède son PDU


**Ces PDU vont tranverser les couches du modèle OSI** :

A chaque fois que un PDU déscend il deviens alors le SDU de la couche N - 1.
La couche N - 1 va rajouter alors son PCI au SDU afin de créer le nouveau PDU de la couche N - 1.

En fait :

PDU -> SDU, SDU + PCI = PDU -> ...

- **à l'inverse si on alors recoit des données on fait l'inverse, on enleve le PCI et on remonte le PDU** ! Le PDU monte les couches

le PCI est l'entête de la couche N actuelle.

*( le SDU, c'est juste le PDU du service au dessus, N+1 )*



**PDU(s) et couches OSI** :

- *Application, Présetntation, Session* : **dépend du protocole utiliser** (Message pour TCP/IP)
  - (FTP, HTTP, ...)

- *Transport* : **Segment**
  - (Permet de controler le flux des données entre 2 noeud finaux)

- *Réseau* : **Paquet** 
  - (sont échanger aentre les routeurs avant sont arriver)

- *Liaison des données* : **Trame**
  - (Une suite organiser de bits échanger entre noeuds du meme réseau)

- *Physique* : **Bit**
  - (Un 0 ou un 1 tout simplement)


## Les techniques d'interconnexion

### Modèle TCP/IP 

Couches :

- Application (OSI: 7, 6, 5)
- Transport (OSI: 4)
- Internet (OSI: 3)
- Accès au réseau (OSI: 1, 2)

### Commutation et Routage

*Commutation : c'est ce que fait les switch (contrairement au routeur, il transfert juste la trame aà l'adresse MAC liée, le routeur lui se base sur quelle est le meilleur chemin pour envoyer le paquet, il fait djikstra ect)*

**1ère classification**

Il existe deux grand familles de techniques ed transfert dans les réseaux de commutation :

- **Commutation de circuit** (utilser dans la télphonie RTC)
- **Le transfert de paquet**, commutation et routage de paquet (C'est internet, le réseau IP)


**2eme classification**

Il existe deux grand familles de techniques ed transfert dans les réseaux de commutation :

- Le Commutation
- Le Routage

#### Commutation

**1. Commutation de circuit**

Avantage :

- Donnée transmises immédiatement
- Pas de stockage
- Débit rapide et constant

Iconvénient :

- Lignes monopolisées
- Circuit inutiliser si les correspondant n'ont pas de données à échanger

=> technique en voie de disparition et pas adapté à internet

**2. Commutation de messages** (Store-and-Forward)

En gros on sauvegarde dans la switch le message et on l'envoie quand c'est demander (j'ai pas bien compris en vrai)

Avantage : 
- Pas de circuit réserver

Inconvénient :

- temps de réponse très long

=> Pas adapté pour des système en temps réelle

**3. Commutation de trame** techniques utiliser aujourd'hui (cellule)

Les circuit sont partager, fragmenter en petit paquet sans les stocker,

En gros ça divise tes données en plusieurs paquet indépendant.

**4. Commutation de paquet en mode "Circuit Virtuelle"** (packet switching)

Les paquetes suive le même chemin tout le temps,
mais c'est pas fou car si le circuit est coupé on perd tout.

**5. Commutation des paquets ("mode data-gramme")** : technisque très utilisé aujourd'hui !

En fait on envoie un paquet avec une destination, et c'est le routage qui se débrouille pour trouver un chemin.

Il n'y a pas de chemin définit !

Avantage :

- Pas de chemin fixé donc pas de réservation de ressources

Inconvénient :

- Ne traite pas la **QoS** (Quality of Service)
- En cas de surcharge du réseau, des blocs d'information peuvent être perdu
- Il y a pas de garanti d'ordonencement (certain message peuvent arriver avant d'autres, ça arrive dans le désordre)


