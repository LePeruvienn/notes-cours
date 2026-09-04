# GraphQL

- C'est un langauge de query pour les APIs
- Développé par Facebook en 2012 et open-source depuis 2015
- Fait pour optimiser les intéraction avec les APIs

## Motivations

Soucis souvent rencontrer avec les APIs REST :

- Avec certaine APIs ont doit faire beaucoup de requête au serveur pour récupérer exactement les informations qu'on veut (**over fetching**)
- On as plusieurs endpoint à appeler en même temps
- Les APIs sont difficile à maintenir

REST nécessiste en fait une façon plus flexible de faire des requêtes.


## Concept de GraphQL

- On va utiliser des schéma, pour modéliser les données qu'on veut récupérer
- On va récupérer uniquement les données qu'on as besoin
- Modifier les donées sur modifier les données sur le serveur
- `Substription` : permet de avoir en temps réelle les changement des données

## Exemple de requête

```graphql
type User
{
    id:ID!
    name:String!
    email:String!
}

type query
{
    gretUser(id:ID!): User
}
```

## Implémentation de GraphQL

**Backend** : 
- Appollo Server (Javascript)
- GraphQL Yogo
- C# ....


...

## Avantage

- On récupère uniquement les data dont on as besoin (pas de overt fetching)
- Un seul endpoint ce qui simplifie la gestion des API
- ..

## Désavantage

- La mise en place du backend deviens plus complexe
- Peut être moins performante avec des requête complexe
- La mise en place du cache est plus compliqué à mettre en place (on as des requête custom donc on ne sait pas vraiment quoi cache)
- Beaucoup plus compliqué à apprendre


