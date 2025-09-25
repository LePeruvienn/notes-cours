# AWS
----
Au début des TPs y aura pas trop de code ça sera du point and click

Possèdes de nombreuses catégories genre 23

IAM = Gestion des utilisateurs, qui as accès à quoi


Exemple de terminologie pour parler de services AWS :
- S3 => Service de stockage
- E2 => Serivce de virtualisation


### Trois façon d'agir avec AWS

- **AWS Management Console (Dashboard)**
- **Command Lineinterface (AWS CLI)**
- **Software Developement Kits (SDKs)**

## Infrastructure mondiale d'AWS

On peut choisir ou se trouve nos machines virtuels dans le monde.

- Chaque zone disponibilité est une partition totalement isolé e de l'nfrastructure AWS.
- Les zones de disponibilité sont constutués de centre de données distincts, c'est fait pour isolé les apannes
- Elles sont interconnectées
- AWS recommande de répliquer les données et eles ressources entre les zones de disponibilité pour assurez a résillience


### AWS data centers

Ils sont des bases de données sécurisé, c'est la bas ou toutes les données sont stocké ect

### Point of Presence
- AWS à plusieurs point de serivces à travers le réseau mondiale
- ça comprend des **edge locations** qui comprenne un plus petit nombre de **Regional edge cache**
- Les **Regional edge cache** sont utilisé pour accéssé à des contenue avec un accès pas très fréquent

Les edges c'est des datacenters qui se trouvent à des endroit éloigné pour être plus proches des utilisateurs

**Data Center**
- **QoS** : Qualité de Service => *Point des développeurs*
- **QoE** : Qualité d'Experience => *Point de vue de l'utilisateur*
	- **CND** : Content Network Delivery => *Faire en sorte que les serveurs soient plus proches des utlisateurs*
- => Ils sont tout les deux définis dans le **SLA** (Service Level Agreement)
	- ex: le forfait téléhpone (10GB/ mois, 50MG/s de débit, SMS illimités, ...)
	- C'est un accord qu'on définis avec le fournisseur de service


### ASW Infrastructures features

- **Elasticity and scalability**
	- Infrastructure élastique, adaptable
	- On peut la scale et l'adapté à notre grandissement
- **Fault-tolerence**
	- On peut continuer à être présent mem esi il y a des bugs
	- Il y a des backups
- **Hight availability**
	- Toujours présent
	- débit de qualité


# Amazon VPC
---


## VPCs and subnets

- VPCs
	- Isolé des autres VPCs
	- Dédié à votre compte AWS
	- Est dans une seule région AWS et peut s'étendre dans plusieurs zone disponibles
- Subnets
	- Lise d'adresse IP qui divise le VPC
	- Ce sont des réseaux publics ou privé

### IP adressing

Quand tu créer un VPC on t'assigne un IPv4 CIDR block (range of IPV4)


### Tables de routages

### NAT (Network Adress Translation)


# Amazon EC2

=> Amazon Elastic Compute Cloud

- Ce sont des choses qu'on déploiement sur des machines virtuelles, qui chaque machine virtuelles est une instance de EC2
- On nous donnes le controle totale sur l'OS de chaque instance
- On peut lancez des instance dans les tailles qu'on veut

Instance type naiming, ex : t3.L
- t = family name
- 3 = version
- L = Large c'est la taille


## Amazon sahred responsibility model

Le client et AWS sont responsable de choses différents

- Client
	- Customer data
	- Application et gestion des identité et des accs
	- OS, network et parfeu de l'entreprise
- AWS
	- Logicielles
	- Infrastructure réseau


# Scenario

1) Client
2) AWS
3) AWS
4) Client
5) Client
6) AWS
7) Client
8) Client