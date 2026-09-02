# Protocole REST

**REST** : Representational State Transfert 

Se repose uniquement sur HTTP, n'impose pas de framework ou autres.

## 1. Rappel sur HTTP

**HTTP** : Hyper Text Transfert Protocol

- Permet d'acceder des fichiers situé sur le réseau internet (il est usitlisé dans le World Wide Web)

- HTTP se place au dessus de du protocole TCP et fonctionne selon le principe de requête réponse

dans HTTP ce sont les URLs qui permettent d'identifié les resources

### Types de méthodes

Il ya plusieurs types de méthodes : 

- `GET` : c'est une méthode dite 'safe' car souvent elle ne modifie pas l'état du serveur
- `POST` : ici c'est l'inverse, c'est pas safe car ça modifie souvent l'état du serveur

### Requête

La reqyete est transmise pas le client au serveur.

- Une ligne de requête (*request-line*) contentant la méthode utilisé
- L'URI du service demander
- Une ou plusieurs l'inges d'entête

L'entête elle permet de décrire la façon dont le serveur doit envoyé la requête au client, on peut dire quelle langue on préfère qui on est et quelle version on utilise.

## 2. Le modèle de maturité de L. Richardson

### MMR - Niveau 0 - Mécanisme de "tunneling"

HTTP comme système de transport pour intéragir à distance.

En gros c'est quand en SOAP, on passe toutes les requête/réponse avec du POST et du OK-200, avec des données pour communiquer entre le serveur et le client.

Mais du coup ça créer des complications :

- Tout passe par la même URL, c'est pas très propres 😞
- Donc on as aussi des XML toujours un peut "custom" donc dur à prendre en main

C'est chiant

### MMR - Niveau 1 - L'utilisation des ressources

C'est la manipulation des ressources via plusieurs URI mais toujours le même verbe !
- Exemple : `get/{id}`, `remove/{id}` et ensuite `get/1`, `get/12`, ...

Aussi maintenat on manipule du coup des entité souvent définis par des identifiant (comme vu au dessus)

Et en gros c'est la méthode **CRUD** quoi enfait (Create Read Update Deleted)

### MMR - Niveau 2 - Verbes et code de retour

Utilisant des verbes HTTP en respect de leurs code de retour.

En gros on utilise les bon code de retour par rapport à ce qu'on fait :

- Donc 201 quand on veut créer ect ....


### MMR - Niveau 3 

- Plusieurs URis, plusieurs verbes
- Des liens entre pages
- **Introduction la décobrabilité et l'auto-docomentation du protocole d'échange**

## 2. REST et l'approche orienté ressource

- Exploité ur les Architechure Orientées Donnés (DOA)
- REST n'est pas un standard, il n'existe pas de spéficiation W3C

**REST** est l'acronyme de : **RE**presentational **S**tate **T**ransfert, ça à buzzer en 2010.

- Elle se base sur les requûete HTTP et leurs code/verbes

Donc[https://cours/api?method=findStudent ...]() Pas reste car on définit une méthode dans l'URL ou autre

ET [https://cours/students/1]() ici oui reste car on va envoyer la méthode via le verbe HTTP !!

### Ressources et URI


