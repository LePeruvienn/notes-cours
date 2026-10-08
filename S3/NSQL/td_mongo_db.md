# TD MongoDB


## Exercice 1

***Question**  \
vous n'avez créé ni base, ni collection, ni schéma. Que s'est-il passé ? À quoi sert le champ _id ?

> Il permet d'identifier chaque membre de la colletion par un ID unique. Il est générer automatiqueemnt dès qu'on ajoute une entrée dans la collection.


**Question**  \
genres est un tableau, pourtant la syntaxe est la même que pour un champ simple. Qu'en déduisez-vous ?

> Si le champ est un tableau, alors MongoDB regarde si un membre de l'array correspond à la valeur qu'on as donnée. Si OUI alors elle le rajoute à la liste de retour.

**À vous de jouer**  \
les films dans lesquels joue Michael Caine, triés par année (sort).
```
db.films.find({ acteurs: "Michael Caine" }).sort({ annee: 1 })
```

les 3 films les plus récents (sort + limit).
```
db.films.find().sort({ annee: -1 }).limit(3)
```

les films de SF sortis après 2010 dans lesquels joue Michael Caine (comparez avec votre réponse du TP Redis).
```
db.films.find({ acteurs: "Michael Caine", annee: { $gt: 2010 } })
```

**Question**  \
le champ vues n'existait pas : qu'a fait $inc ? Comparez avec INCR dans Redis.
> Il suppose que la valeurs était à 0 et donc la met à 1 (0 + 1 = 1)


**A vous de jouer**  \
Insérez dans la collection films un document qui a une structure totalement différente (par exemple une série, avec un tableau de saisons et d'épisodes).
```
db.films.insert({ nom: "Maxence", prenom: "nom", date: 2  })
```


