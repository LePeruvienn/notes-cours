
WebSémantique : Données, Logique, Requètes


Type de logique:
- rdfs
- owl
- geo

## Onotoligies

### Objectifs

- capable de parlé un language commun
- Partagé une compréhension commune
- Intégrer et partager des données qui proviennent de sources différentes
- Ruitilisations des connaissances
- Analyer les connaissance d'un domaine
- Bénéficier des raisonneur
- Nécessité d'avoir des language pour l'exprimé


### BD Relationnelle et Ontologie

Onotoligie **OWA** :

Hypothèse monde ouvert :
- Hypostèse appliqué dans le Web : ce n'est pas parce qu'on connais pas une valeur que cette informations est fausse

Alors que pour une base de données relationnelle si la données existe pas alors elle est fausse


Ontologie **non-UNA**

Hypothèse des nos uniques:
- Hypothèse pas appliquer dans le web, deux nom différent ne peuvent pas faire référence à la meme unité

Dans le web on peut avoir plusieur données avec des nom différents qui pointe vers la meme entités

(Exemple Barack Obama peut être appelé de différente façon dans le web)



### Web Ontology Language (OWL)

**Un autre standart**

- RDFS présente des limitation pour représenté des ontologies
- OWL est un langage de descriptions d'ontologies conçus pour la publication et le partage d'ontologie sur le web
- OWL permet : 
	-  Une riche représentation des connaissances
	- De raisonner sur ces connaissance en s'auupayant sur ne axiomatiqe formelle

### owl:Thing et owl:Nothing


- Tout les invidivu sont de type owl:CLas
- Tous les individus (les instances) sont de type owl:NameIndividual
- Une classe est simplement un ensemble d'individu

- Toutes les classes sont des sous classes de owl:Thing
- Touts les individus sont de type owl:Thing



### Expréssivité de OWL

- Identité : owl:SameAs, owl:differentForm
- Sémantique de class : owl:Thing, owl:Nothing, ...
- Smématnique de propriété : owl:equivalentProperty, owl:inverseOf, ...



