# Les bases d'un moteur de jeu

C'est des TPs sur Unity et un projet

## C'est quoi un moteur de jeu ?

Outils pour développer des gens et des expérience intéractive 3D ou non.

C'est cool car
- C'est souvent simple à utiliser et ça permet de créer plus rapidement
- Permet d'avoir des jeux plus performant et jouable sur différentes platformes
- Plein d'outils intégrés

Mais ils y a souvent un prix à prendre en compte (liscence) *sauf godot 😎*

Plusieurs type de moteur : **générique** et **spécifique** : 

- Générique : Peremette de créer une grand variété de jeu, parfois au détriment des performance et de l'expérience de développement

- Spécifique : très bon mais que pour ce jeu la

Quelques exemple de moteurs

- Public : RPG Maker, Game Maker, Unity, Unreal Godot, ...
- Propriétaire : Frostbite, Snodrop, IdTech, ...

## Rendu Graphique

Mais il ya aussi des jeux sans rendu : **A Blind Legend** !!

- Transform : correspond à la position et rotation et taille de l'objet dans le monde.

- Objet de Rendu : composé d'un **mesh** ou maillage géométrique et d'un **materiau**. Le **mesh** représente la forme de l'objet (son squelette) et le **materiau** représentet la façon dont il va être affichier à l'écran (texture, effet visuel, ...).

Une mesh c'est les données géométriques (vertices), qui peuvent contenir plusieurs informations notamment la position et les coordonnées de textures.

Ces informations la sont ensuite donné au **shader** du materiau qui lui va utiliser les informations de la mesh pour déssiner l'objet àl'écran. Le materiau lui aussi peut posséder des paramêtre d'entrée (réfléction, couleurs) qui lui aussi peut modifié le rendu du **mesh**.

Certaine mesh peuvent être associé à des squelettes (Rig) qui peuvent être manipuler pour "transformer" la mesh (déplacer le personnages, ...), c'est grâce au **rig** qu'on peut faire des animations.


## Scène

Aussi appeller "*Scene Graph*" ou "Graphe de Scène"

C'est la hiérachie des objet dans le monde.

Elle est souvent composer de noeuds qui contienne une informations de positions et des feuille (noeuds sans "enfant") qui elles sont souvent des mesh et materiau (donc contient position + géométrie, ...)

Exemple de graph de scène :

```
Racine
- Village
  - Maison A
     - Table
  - Maison B
     - Chaise
- Foret
  - Arbre
    - Feuilles
    - tronc
....
```

## Caméra

- Un objet dans la scène permettant l'affichage d'un point du vu

Configurable par :

- sa position,
- rotation,
- FOV,
- near/fear plane (plan le plus proche et le plus loin)

Une scène peut posséder plusieurs caméra

## Lumière

Elle est produite par un objet dans la scène, permettant d'éclairer les autres objets dans la scène.

Elle peuvent être :
- **Calculer en temps réelle** : apporximatif mais peut convenir selon le style de jeu

- **Précalculer** : aussi dit "baked", donc un rendu réaliste mais pas dynamique ou peu, avec les information stocket directement dans les textures (lightmaps)

- **Mixte** un mélage des deux (ex: élément fixe on précalcule et élément dynamique on le calcul en temps réelle)



Dans les cas de lumière temps réelle il peut avoir plusieurs représentation : 

- **Point Light** : Une lumière qui éclaire partout autour d'elle "sphère"
- **Spotlight**
- **Directionnal Light**

## Outils

### Controleurs de jeux (Inputs)

- Ensemble de fonction pour récupérer les entrées utilisateurs selon les périphériques

- Couche d'abstraction du périphérique pour faciliter le dev.

### Physique

- Détection de collisions (on ajoute des **collider** à nos mesh)
- Simulation physique en temps réelle (gravité, frottement, force, ...)

### Autres outils

- Audio
- Animations
- Système de VFX (Particle system de Unity)
- Sérialisation (pour level design, sauvegarde des données de jeu)
- Simplification du workflow (prefab, debugger, ...)


