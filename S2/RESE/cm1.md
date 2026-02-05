# Références

- Guy Pujolle, "*Les Réseaux*", Eyrolles, ed. 2014. <- Conseillé par la prof !
- ...

# Introduction

## Généralité

### Définition

C'est un ensemble de système informatique interconnecté.

Un réseau s'appuie sur deux notions : 
- L'interconnexion : transmettre les données d'un noeud
- La communication : échanger des données entre processus

#### Intérêt des réseaux

- Paratges de ressources et d'informations
- Centralisation des données et des services
- Médium de communication

## Evolutions des réseaux de communication

Il ya aussi aujourd'hui les NAT qui sont fournis par la boxe
Le NAT permet de donné une adresse IP unique et publique à un foyer.

Il ya deux type d'IP dans un foyer avec une box :

- Adresse IP unique à une box et à un foyer.
- Les adresses IP locale (une par appareille) qui sont privé et pas pas unique

Tout les nouveaux services s'appuie sur 2 grands réseaux : 

- internet et son protocole IP
- les réseaux mobile sans fil


Aujourd'hui il y a une transition vers l'IP !
- Les réseaux télécoms, tnt, sont voix à être transformer vers des pasquets IP.
- Tout les flux transitionne vers flux numérique IP (alors qu'avant c'était des flux signaux)

En fait aujourd'hui on as séparer la partie materielle de la partie logicielle, ce qui nous permet aujourd'hui de pouvoir programmer les réseaux. (Réseaux SDN, Software Designed Networking)

### Exemple de réseaux de communications

#### Réseaux téléinformatique

- Ordinateurs, serveurs, ...

#### Réseaux de télécommunications (la voix, la parole)

- RTC, Réseaux mobiles, RNIS, ...

Réseaux mobiles, 2 principes : 

1) Accès sans fil, par lien radio

2) Concept cellulaire -> Mobilité du réseau, *handover* (on change "d'antenne" maos on reste sur le même réseau !)
   Rareté des fréquence -> paratge des fréquence entre relais (en gros les relais évite d'utiliser les même fréquence que leurs voisins)


#### Réseaux de télédiffusion (l'image, la vidéo)
Ils servent à la diffusion des cnaux de télévisions entre les studios TV et les particuliers.

- réseaux de distribution terrestre (TNT)
- Les réseaux satellites (Vsat)

Exemples: Numéricabes (Paris), Vsat ou Etelsat


#### Réseaux multimédia

Acutuellement la technologie tend vers **la réunion de ces trois type de signaux** pour obtenir ce qui est apelé les **réseaux multimédia**.


## Types de réseaux

### Classifications selon la topologie

La topologie c'est la mnière de relier des équipements entre eux,

| Topologie| Architecture | Avantanges | Inconvénient |
| --------------- | --------------- | --------------- | --------------- |
| Bus | Tout les ordniateur sont relier à la même ligne | Facile, peu couteux | Problème de support physique |
| Etoile | Un swich au centre qui distribue les informations | ? | ? |
| Anneau | Les ordniateur sont relier à leurs voisins, afin de former un "anneau" | ? | ? |
| Maille | Toutes machines sont reliées aux autres | ? | ? |


### Classifications selon le mode de diffusion

**Mode de transition point à point (unicast)**
- ...

**Mode de transmission par diffusion**
- ...

### Classifications selon le mode de gestion

**Gestion centralisé** (client/serveur)
- Centralisation des ressources sur un serveurs
- deux rôle distinct (un client et un serveur)

**Gestion déscentralisé** (pair à pair)
- Chaque utilisateur peut prendre le rôle qui veut

### Classifications seon de la taille (typologie)

Selon la distance maximal reliant deux points (la portée) :

- **PAN** (Personal Area Network) *une personne*
- **LAN** (Local Area Network) *Une maison, un batiment*
- **MAN** (Metropolitan Area Networks) *entreprise, université*
- **RAN** (Regional Area Network) *Une ville, une région*
- **WAN** (Wide Area Network) *Continent, mondiale*

### Organisation des réseaux étendu `WAN`

- C'est un réseau qui fonctionne au delà de la partée géographique d'un réseau local LAN.
- C'est souvent propriétaire, il faut parfois payer pour y avoir accès.
- Elle permet de faire le lien entre plusiseurs réseaux, Ex: LAN -> WAN -> LAN, quand on va sur internet

**Types de WAN**
- WAN public
- WAN privé
- WAN virtuel

**Mode de transport**
- Diffusion "*broadcast*" : un émetteur transmet des informations à un grand nombre de récepteurs (ex: radio)
- La collecte : c'est des capteurs qui essaye de récup des données.
- échange bi-directionnels, échange entre les deux machine (on est receveur et envoyeur). Les informations communique grâce au routage.


#### Architecture d'un WAN public (Coté opérateur)

Un réseau télécom se compose de 3 grands niveaux

**Partie COEUR** : réseau de transport (réseau dorsal: backbone)
- Véhicule l'information

**Partie METRO**
- Assure le transport

**Partie ACCÈS**
- Assure le lien finale entre l'utilisateur et le réseau.

## Structure de l'internet

### Réseaux d'opérateurs (ISP, FAI)

Internet : le réseau IP

**Acteurs impliqué** :

- Fournisseurs de contenu et d'applications (FCA) : *Netflix, Microsoft, ...*
- Les hébergeurs : les propriétaire des serveurs qui héberges les FCA
- Les transitaire : les gestionnaire de réseaux internationaux, intermédiare entre FCA et les FAI en leurs fournissants les "tuyaux" pour acheminé le traffic
- Les points d'échange internet (IXP)
- Les réseaux de diffusion de contenue (CDN), c'est des serveurs qui possède du contenue "cached" de FCA, afin de se rapprocher de leurs utlisateurs.

**Interconnexions des données**
- Routage interne
- Routage externe

#### Modes d'interconnexion

**Internet Transit**
- C'est un service vendu par un fournisseur à un client, pour **donné un accès à internet**

**Internet Peering**
- Peering c'est un type d'accord d'interconnexion qui permet l'échange de données de manière gratuite entre deux fournisseurs.


#### Organisation de l'internet : Hiérarchie des réseaux d'opérateurs

**Opérateur de Tier 1** 
- Plus haut niveau n'achète pas de transit => ne paye personne
- 100% peering

**Opérateur de Tier 2**
- Achète du transit et fait un peur de peering entre eux.
- Fournisse du transit au tier 3

**Opérateur de Tier 3** (petite taile)
- Orange SFR


### Transports des informations

#### Principales étapes

1) Captures des inforamtions sources

- Données discrètes : c'est des données numérique
- Données contenue : c'est des données analogiques

2) Codage source

- Adapter les donnes au cancal et éliminer les redondances, (cmpréssion sans perte d'informations)
- Ex: Code Huffman

3) Codage canal

- Adapter les inforamtions source au support physique
- Ajouter de la redondances dans les messages afin de sécurisé l'informations aux perturbations, ect

4) ??

### Codage sources/numérisation des inforamtions

On veut écrire "abacadabra"
- On as besoin de 3 bits pour encoder le messages.

Après on peut appliquer l'algo de Huffman.
- Le principes est de donner le moins de bit au lettre qui aparaisse le plus, afin de raccourcir la taille du message.


