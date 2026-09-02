**[LIENS VERS LES DIAPOS](tinyurl.com/4kf9tzwy)**

# Architecture et Web Services

Le prof est un kiffeur d'IA. (*si tu en utilise pas tu est masochiste askip* 💀)

**Prérequis**

- Programmation Orientée Objet
- Java
- bases de Données
- XML
- IDE Eclipse

## Notion d'architecture orienté ervices

Différente architechure de Web Services :

- **SOAP**
- **gRCP**
- **REST**
- **GRAPHQL**

Leurs but était de créer un standart pour communiquer avec des applications externe.

### Paradigmes

**Paradigme procédure**
- Prcédure fontion et struture de données, a

**Paradigme Objet**
- Classes, lié à un langauge de programmation

**Paradigme Composant**
- Composant (groupe d'interface)
- Lié à un modèle de composant

**POS, POO, POC** : Pourquoi on veut améliorer ?

### Définitions

- **Un Service est Autonome** (sans états)

- Un service Expose un **Contrat**

- Les frontière entre es services sot explicite

- Les services communique par des messages

### Architecture

Il ya 3 acteurs :

**Registery**
- C'est la base de données

**Provider** 
- C'est une application (souvent un backend)

**Consumer**
- C'est une application (souvent frontend)

Et aussi *Les partenaires* je crois que c'est les services externe que t'utilise dans ton appli.

## Le Web

### Les origines

Avant on utilisait que le standart HTML et HTTP.
- On faisais des requetes HTTP au serveur et il renvoie du HTML

Mais pour le B2B (donc quand on veut envoyer et recevoir des données) on utilisait le XML.
Qui était un standart de fichier (style JSON) qui permet de transformer des données.

### Définitions

Un service Web est une application logicielle 

1. Identifié par une URI dont les infertfaces et les liaisons sont définies, décrite et dévoucerte avec des mécanismes XML (ou autre)

2. 

## Standarts

**SOAP** : Transporte (couche HTTP)
- Simple Object Acess protocol

**WSDL** : Décrit le contrat (les endpoints) en XML
- Web Services Description Langauge

**BPMN** : Décrit le processus métier 
- Buisness Process Model Notation

### WSDL

On peut dérire du coup sous format XML plusieurs choses :

**<SERVICES>**
- C'est enfait une collection de endpoints qu'on peut utiliser
- `localhost:8080/annuaire`, `localhost:8080/annuaire/add`, ...

**<TYPES>**
- Les différent types qu'une entité ou schéma de base de données peut avoir.

**<MESSAGES>**
- Décrit les noms et type d'insemble de champs à transmettre, en fait c'est les paramêtre à donné pour une requête.

**<PORTTYPE>**
- Ici on décrit les ensemble d'opérations possibles, il ya plusieurs type d'opérations :
  - *OneWay* : Le service reçoit un message en entrée (`<input>`)
  - *Request-Response* : Le service envoie un message `<input>` et recoit `<output>` ou des érreurs `<fault>`
  - ...

**<BINDING>**
- Ce sont les format des messages et le protocole utiliser pour l'envoie (`SOAP` par ex)

**<SERVICE>**
- C'est le point d'entrée d'un service unique, qui est la combinaiss d'une adresse internet d'une liaison.

## SOAP - Simple Object Acess Protocol

- Intégartion XML au dessu de HTTP

- Pour acceder aux services objets et serveurs

- Codage universel XML par opposition aux spéficiques :
  - DCOM - DCE/NDR
  - CORBA - IIOP/CDR
  - JAVA - RMI/JMRP
  - RDA - XDR

Résolution des problèmes de sécruritées :
- Les firewall supportent des ports spéficiques (HTTP, FTP)
- La plupart des middleswares assignes des part dynamiques

Associé à WSDL pour la publication d'interfaces

**Un échange type**
- En fait c'est une surcouche de HTTP donc tu envoie du SOAP qui est transformer en HTTP qui est après de transformer en SOAP.

