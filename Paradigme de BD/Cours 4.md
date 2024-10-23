
# PROJET : NOUVEAU PARADIGME DE BD

!!! **PROJET = 40% DE LA NOTE** !!!

=> Projet en binome

*TP5 est une exemple du projet*

1) Trouver une question intéréssante => Chacun aura un sujet différent : Trouver un fichier CSV/JSON/...  et d'un donnée wikidata pour répondre à cette questions
2) Créer une ontologie pour décrire le domaine
3) Convertir l'ensembe de données tabulaires en RDF *(Utiliser OntoRefine et tout)*
4) Utilisé SPARQL pour lier les entitées au graphe de conaissance externe
5) Répondre à la question de l'étape 1
6) Visualisez les résultats de cette requête dans une applicataion WEB
7) Documentation de ce qu'on as mit en oeuvre

**DATA LIMITE** : dans 1 mois le **lundi 25 novembre** 2024 à 23h59


- On pas pas le droit de prendre les meme sujet que en cours
- Il faut qu'on soit obligé d'utiliser Wikidata et de notre graph locale


Exemple de projet
- Forza 4 : Il as un fichier CSV avec toutes les voiture du jeu, puis il regarde quelles sont les pays qui ont le plus de voiture dans le jeu (CSV = voiture, Wikidata = pays)


=> Exemple d'application web (sur moodle) !
- Il ya tout le code source sur git


# BONUS 3 POINTS (et aussi pour le DS !!)

- Si la requête SPARQL ne fonctionne pas sans l'inférence 
	- En gros faut faire un raisonneur avec une règle et que le projet l'utilise (ex : x est le frere de y)
	- Dans graph DB il montre toutes les données inférées
	- Dans graph DB quand on créer le dépot il faut mettre **OWLMax** et pas RDF Plus
	- Il faut qu'on utilise des ontolige symétrique, transitive pour que ça soit inférré

**EN GROS**
- Faire une bonne ontologie avec OWL
- Fair en sorte que cette ontologie permettre de répondre à la question, avec des propriété symétrique, transitive ect ...
- Faire en sorte que sans ces propriété ça marche pas !