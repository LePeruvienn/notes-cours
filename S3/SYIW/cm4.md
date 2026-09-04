# SOAP versus REST

## SOAP Web Services

- Automnomes
- Exposent des contrats
- ont des frontière explicisse
- communiquent par message en utilsant des protocoles web
- sont identifiés par des URIs (URLs)
- ont des itnerfaces, liaison et méssages décrit en XML

### Problèmes avec les standart Web Services

Il ya beacoup de couche dans les standart WS dont ça rajoute de la compléxité pour rien ?

Plein de couche avec des standart différents gérer par des mécanisme différents,

On cherchais alors une nouvelle solution

## RESTFull WebServices

- Autonomes
- expose des contrat (de manière automatique avec les réposne HTTPs ect et leurs structure)
- as des frontière explicite
- communique avec des message utilisant des protocoles web
- identifié par des URIs
- fonctionne uniquement avec des messages REST

### Les 3 fondamentaux de REST

- Ressources
- URLs
- Opérations simple


### REST Opérations

- GET : pour récupérer des objet en lecture seul
- POST : peut être plusieurs choses, souvent pour ajouter, mod
- PUT
- DELETED
- HEAD

## Comparaison

**REST**
- Lightweight
- Human Readabe
- Easy to build (apporche top down)

Souvent pour les appli webs ect ...

**SOAP**
- Facile à utiliser (parfois ??? c'est son diapo hein)
- Rigide, on vérifie les types et le contart match bien les requêtes
- Plusieurs outils de dev
- Granularité


**Contrainte des WebServices** (SOAP)
- On l'aimprésion de reinveinter le web avec POST car on fait tout avec quoi
- C'est complexe
- On perd des avantage du web


**Contrainte de REST**
- Impossible de tout modéliser avec POST, GET, DELET etc
- En gros c'est très simple donc ne s'adapte pas bien à certain besoin


En fait les WebServices type SOAP voulais vraiment mettre en place une base extensible pour tout les besoins posible, alors que reste veut s'adapter aux besoins du plus grand nombre en restant simple.ja


### Quand utiliser SOAP ?

- Si tu pene nécessaire d'avoir un contrat entre le serveur et le client via une interface
- Si tu veut utiliser des features
- SI tu veut utiliser d'autres protocoles de HTTP



## Conclusion

| SOAP   | REST    |
|--------------- | --------------- |
| Un standart, un protocole   | Un style d'architechture   |
| ne peut pas utiliser RESET car SOAP est un orotocole et REST un modèle archi   | Peut utiliser SOAP comme protocole sous-jacent pour les services WEB, car en fin de compte c'est qu'une archi |
| Nécessite beaucoup de bande passant  | Nécessite peut de bande passante   |
| Ne fonctionne que avec XML  | Fonctionne avec tout les formats  |
| utilise des interface entre les services (WSDL)  | Utilise les verbes HTTP (PUT, DEL ...) pour s'auto documenter  |




