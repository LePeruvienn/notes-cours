# Bonne pratiques

## Architecture sur Unity

### Prototypage

Unity c'est un super outils pour prototyper. Notamment avec :

- Les assets store
- L'outils pro builder pour créer des niveau / monde rapidement.

Quand on veut prototyper l'architecture n'as pas d'importances, **jusqu'au passage en production ....**

> CONSEIL: Quand on reprend un projet prototype ou de jam, REPARTIR DE ZERO ! FROM SCRACTH


### Architecture d'un Projet (pas un proto un vrai truc)

L'organisation des fichiers est importante car elle influe directement la facilité de travail sur el projet. C'est alors très important de mettre en accord dès le début lors d'un travail en équipe.

Il y a plusieurs façon d'organiser les fichiers
- **Organisation par fonction** (Scripts, Animations, Prefabs, ...)
- **Organisation par raison d'être** (Monde1, Monde2, CharacterBase, CharacterA, Common, ....)

Les deux sont ok ils ont leurs avantages et incovénients!


## Code

Le code peut être regrouper dans le dossier **Script** car il n'est pas géré de la même manière que les assets.

**Il faut toujours Décorrélé la logique, le rendus et le controles !!**
- ça rend le code plus modulaire.
- et ça facilite les tests automatisé.


Il faut aussi évitez les valeurs "hardcodé" et préviliégé la **modification des paramêtre via l'inspecteur!**


Utiliser les **Assembly Definitions** (notion `C#`):
- C'est en fait des libs `C#`
- Il permet de séparer les différentes partie du code en plusieurs libs afin de réduire le temps de compilation!


