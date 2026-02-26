# Le Routage

## Les chemins

Le routage permet de répondre à la question : **Quelle est le meilleur chemin à prendre afin d'arriver à destination.**

## Le Postulat du routage

C'est une table d'adresse qui est comporter :
- D'une adresse (ou on veut allez)
- Et d'une passerelle (quelle chemin à prendre pour allez à l'adresse)

## Table de routage

- Définit la correspondance entre **l'adresse de la machine visée** et **le noeud suivant** auquel le routeur doit délivrer le message.

Contenue de la table de routage :

- **destination** : IP D'une machine
- **masque** : masque associé au réseau de destination
- **passeraelle** (gateway) : IP du porchain routeur vers lequel il faut envoyer le datagramme
- **interface** : interface physique par laquelle le datagramme doit réellement être expédié
- **métrique** (cost) : utilisé pour le calcul du meilleur chemin

# Les protocole de routage

## Le routage dynamique

### Le routage interne

RIP : Routing Information Protocol

- Protocole de type "Vecteur Dstancjkk"

# Couche transport

## Numéros de ports

**Un socket** c'est une combinaison d'une IP et d'un port
- Il permet via un pipe de faire communique deux machine grâce à leurs combinaison IP+port

Les ports sont des portes d'entrée



## Le protocole TCP

**Phases**

- ETABLISHED
- FIN_WAIT_1
- FIN_WAIT_2

## UDP

### Structure d'un datagramme UDP

Taile **4 octets** : 
- Port source 
- Port de destination
- Longueur
- Somme de controle
- Données

Logueur du datagraphe Longieur de l'en-tête + données
- Codé sur 16 bits
- La longueur minimal est 8 octets
