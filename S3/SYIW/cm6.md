# Introduction à gRPC

**G**oogle **R**emote **P**rocedure **C**all

- Développer en 2015 par Google
- Use HTTP/2 pour le transport, Protocole Buffer pour la séraliazation 
- supporter avec plusieurs languages.

## Petit historique

- C'est le successaeur du *Stuby framework* un truc interne à Google
- OpenSource depuis 2015
- Très utiliser dans les archi microservice

## Motivations

- Besoin de plus de performence lors de la communication entre services
- La limitations des APIs REST 
  - Latence du aux requête HTTP multiple
  - ...

## Concept principale

- Définition de services : Protocole Buffers `.proto`
- Fortement typé pour éviter les érreurs et conservé les données structurer
- Permet de comprésser les binaires (ProtoBuf)
- Plusieurs méthode de communication
  - Unary (Request-Response)
  - Server Streaming
  - Client Streaming
  - Bi-directionnel streaming (communication simultanée)


## Exemple

```proto
service UserService
{
    rpc GetUser (UserRequest) returns (UserResponse);
}

message UserRequest
{
    string user_id = 1;
}

message UserResponse
{
    string name = 1;
    string email = 2;
}
```

## Avantages

- Haute performence
- Fortement typée
- Permet la communication simultanée
- Cross-lanauge support

## Désavantage

- Nécessite Prtocol Buffers ce qui ajoute de la complexité
- Non lisible par un humain (comparer à JSON en REST)
- Pas supporter dans tout les navigateurs (nécessite gRPC Web)


## Conclusion

- Adopté dans les infrastructure moderne cloud
- De plus en plus de navigateurs supporte gRPC
