# Notion d'adressage

## Adressage physique et logique

### Adressage logique (Adressage IP avec protocole IP)

**Adresse IPV4**
- 32 bits (4 octets)
- 3 octets sur le préfix

**Adresse IPV6**
- 128 bits (16 octets)

*Rappel ocets et bits* :
- Chaque octet est un nombre entre 0 et 255

## Adressage plat et hiérarichique

**Adressage hiérachique** :
- designe un ensemble de machine

**Adressage plate** : 
- désigne une massage unique

# Couche internet

## Le protocole IP

Une adresse est un moyen d'authentification

- IP ID : l'IP routable (accesseible sur internet)
- Host ID : l'ip sur le réseau

**On peut définir l'IP réseau (host ID) de plusieurs façon** :
- de manière statique : l'adresse est fixe mit maniuellement
- de manière dynamique avec le protocole DHCP (dynamique host configuration protocole) ou BOOTP


### IPv4

**Composé de 2 Partie** :
- Partie NET_ID (réseau)
- Partie HOST_ID (partie hôte)

Afin de pouvoir le décomposer il faut utiliser le **masque réseau** (netmask).
- Il faut appliquer un *et logique** (**AND**) binaire entre les **masque réseau** et l'**adresse IP** !

Après qu'on applique cette opération :
- On obitent alors la partie `NET_ID`, suivie des 0 qui compose la partie `HOST_ID`.
- L'écriture **CIDR**, c'est le nombre de bits qui compose le `NET_ID`
- Ex: `192.168.2.1` avec le masque `255.255.255.0` on obtient => `192.168.2.0`, ici le CIDR vaut 24 bits (3 * 8)
- *C'est plutot utile pour savoir si des machines sont sur le même réseau !*

*La partie `HOST_ID` est composer de 0 mais n'est pas visible ! Il faut faire l'opération suivante pour l'obtenir*

Pour obtenir la partie `HOST_ID` il faut faire un `~ du netmask` suivie d'un `AND` sur l'adresse
- En gros on inverse les bits du masque réseau, pui on reéffectue un `AND` logique sur l'adresse IP.
- Ex: `192.168.2.1` avec le masque `255.255.255.0` on obtient => `0.0.0.1`

**Adresse broadcast** :
- On prend la partie `NET_ID` et on replace les autres bits récent par 1
- Ex: `192.168.2.0` comme partie `NET_ID` on obtient => `192.168.2.255`


**Attention !!** Quand on fait des opération binaire il faut bien avoir en compte qu'il faut comparer les nombre en mode **binaire** !
- La partie `NET_ID` ou `HOST_ID` peut être sur seulement quelques bits (au lieu d'un octet complet)
- Par exemple la partie `HOST_ID` peut être seulement sur les 4 derniers bit de l'adresse !
- Ex: si on prend le dernier octet de l'adresse, `1111 1000` donc le dernier octet du masque réseau sera un nombre ! Mais il n'empeche pas qu'il prend bien une partie du masque réseau !

**REMARQUE** : Aussi l'adresse IP n'est pas forcément découper en deux partie (une à droite et une à gauche), les valeurs des deux partie `NET_ID` et `HOST_ID` peuvent avoir leurs bits réparti de n'importe quelle façon dans l'adresse !


*En gros faites bien les opération ça peut être tricky des fois quand tu fais tout de tête*

**Il ya deux adresse IP interdite** 
- `0.0.0.0` (l'adresse réseau)
- et l'adresse du broadcast

### Adressage par classes (IPV4)

Les classes A, B et C sont réserver poru les utilisereurs d'internet,
- **Elle permet d'en déduire le masque réseau d'une IP**.

Elle à été créer afin de résoudre le problème de pénurie d'adresses,
le but est de pouvoir associé une adresse à plusieurs sous réseaux.

**Classe A**
- `NET_ID` = le **1er** octet.
- 1er bit de poid fort à `0`
- Masque : `255.0.0.0`

**Classe B**
- `NET_ID` = les **deux** premier octets.
- les deux bits de point fort = `10`
- C'est la classe la plus utilisée, les adresse aujourd'hui sont pratiquement épuisées
- Masque : `255.255.0.0`

**Classe C**
- `NET_ID` = les **trois** premier octets.
- les trois bits de point fort = `110`
- Masque : `255.255.0.0`

Il ya aussi d'autres classe
- **D** ...
- **E** ...

Masque par défaut : `255.255.255.240`.

**REMARQUE** : Aujourd'hui on as pas trop besoin de faire ça car avec l'adresse **IPV6** il n'y a pas de pénuirie !


### Interace de boucle locale (loopback)

C'est une interfae virtuelle d'un materiel réseau.

- ça permet de simuler le passage par les couches réseaux de la machine vers elle même.
- Sur UNIX l'interface de loopback est abrégé `lo`

### Gestion des adresses IP d'internet

L'**IANA** (Internet Assigned Numbers Authority) est une orgnisation américaine qui gère l'adresse des adresses IP dans le monde.

- **RIR** (Regional Inernet Registeries)
- **RIPE NCC** (Europe and africa)
- **LIR** (Local Internet Registeries

### Adresse IPV4 sous réseaux (subnetting)

Pour segmenter un réseau en sous-réseaux,

Par exemple pour créer 3 sous-réseaux, il faudra prender 2 bits dans la partie histid et on créeera 2^2 donc 4 sous-réseaux

Exemple : pour le réseau `192.168.1.0/24` découper en 4 sous-réseaux
- `NET_ID` = 24 bits
- `SUBNET_ID` = 2 bits
- `HOST_ID` = 6 bits

Le `SUBNET_ID` est alors sur **2 bits** on va alors varié les **deux premiers bits** de la partie `HOST_ID` afin de créer les différents sous-réseaux (mais la partie réseaux elle ne change pas !
- On aura alors `01`, `00`, `11` et `10` ce qui nous donne bien 4 sous-réseaux

Le masque de sous réseaux sera 24 + 2 = 26 bits soit `255.255.255.192` !
- Chaque sous résaux aura alors un CIDR à 26.

### Plage d'adressage des réseaux

Le nombre de machine adressable dans chaque sous-réseaux : 

- `2^(nb bits hostid) - 2 adresses interdites`

### IPV6

Elle est sur **128 bits** :

- Préfix global (48 bits)
- Sous-réseaux (16 bits)
- Interface (64 bits)

Il ya plusieurs type d'adresse : 

- ????
- ???? (Adresse privée équivalent privé)
- Adresse Unique Local (ULA)



### Protocole ARP

ARP (Adress Resolution Protocol)

Elle permet de **faire la correspondance entre une adresse IP et une adresse MAC**.

C'et utile car les applications utilise des IP et non des adresses MAC :
- En gros le système (routeur, machine , ...) fait une requete ARP afin de connaitre l'adresee MAC de cette IP
- Ensuite le système peut mettre en cache le résultat afin de pas à avoir à refaire la requête ensuite.

### Protocole ICMP


ICMP (Internet Control and error MEssage Protocol)

- Utilisé pour ping et traceroute/tracert (permet de connaitre par quelle routeur on passe lors de la requête)



