# UI sur Unity

À quoi ça vous fait penser ?

- Ergonomie 
- HUD (**H**ead **O**f **D**isplay)
- Menus
- Canvas
- UX (**U**ser **E**xperience), notamment via le UI/UX

## User Interface (UI)

- Terme meployé pour désiner les affichage de texte, boutons et jauges (tout ce qui n'est pas l'environnement)
- Peut être un menu, une HUD, un popup, des marquages au sol, ect ...

C'est souvent ce qui est souvent pas l'univers du jeu et qui sert seulement au joueur.

## Screen-space et World-space

**Screen-space**
- Positionné par rapport à l'écran,
- Les unité de longueurs sont les pixels à l'écrans
- Menus, inventaire, minimap

**World-space**
- Positionné par rapport aux objets dans la scène
- Les unitées de longueurs sont les unités monde
- Noms au dessus des joueurs, marqueurs au sol, indications (dégats, ...)


## `Canvas` et `RectTransform`


- Une **UI est une arborescence de game object dont la racine possède le component `Canvas`**
- **Tout les game objects enfant du `Canvas` on alors un `RectTransform`** au lieu d'un `Transform` classique


### `RectTransform`

Le rect transform permet de définir la position des élémetn dans l'UI sur l'écran

**On peut lui définir un référentiel sur lequel se bas sur l'écran**
- cela peut être par rapport au centre de l'écran, à un des coins
- On peut aussi se référer à la bordure d'un axe (mode `stretch`)

Le `RectTransform` est un élément très important des UI, car il permet d'adapter l'UI à tout les type d'écran. Que ça soit du `16:9`, `16:10` et même du `4:3` !

## Les Components

### `Image`

Permet de mettre une image sur l'UI.

- Il va être étirer de façon à remplir le `RectTransform`
- On peut configurer la façon dont l'image s'étire (éventuellement ajouter du "*9-slicing*")
- On peut lui ajouter un materiaux pour modifier son rendu et lui donné des effets (ex: modifier sa couleur)

### `Button`

Permet de détecter un click utilisateur pour effectuer une action.

- API pour gérer les évenement et possible de les définir directement depuis l'éditeur
- Possède plusieurs états (clicked, hovered, pressed, ...)

### `Slider`

Jauge avec un curseur glissable,

Son intérêt se trouve surtout dans les menus d'options
- Volume, luminausité, ...


### `TextMeshPro`

Permet d'afficher du texte ! 

*Anectode* 🤓☝️
> De base Untiy avait créer `TextMesh` mais c'était éclater (ça s'aliasais, c'était flou, c'était moche). Un boug avait coder une version qui marchait mieux (`TextMeshPro`), et l'avait publier en tant qu'un addon payant. 
> Unity à décider de racheter cette addon et de l'intégrer à leurs moteur de base (car il était clairement mieux!)


L'addon permet donc d'ajouter du texte, avec de la couleurs des effets, ect ... c'est la base pour afficher du texte !

On peut aussi ajouter des "*outlines*" qui sont la façon dont le bord des lettre sont afficher;

### `Layout`

C'est un peu comme ce qui se fait dans le web :
- On peut y définir des grilles,
- Mettre des componant en mode "*flex*"

On as plusieurs type de groupes :

- `GridLayoutGroup` : mettre sous forme de groupes les éléments
- `HorizontalLayoutGroup`, `VecticalLayoutGroup` : un peu un *display flex* (met les objet à la suite verticalement/horizontalement)

Le `ElementLayoutGroup` permet d'ajouter des contrainte de rendimensionnement à des élément d'un groupe (ex: largeur minimal = 200 pixels)

Le repositionnement des objets sont couteux en calcul quand il ya de gros groupes imbriqué ! faut faire gaffe


## Références

**Documentation Unity UI**
- Ce qu'on as vu jusqu'a présent
- Legacy, mais c'est quan même utiliser dans la plupart des projets

**Unity UI Toolkit**
- Nouvelle façon de faire l'UI beaucoup plus proche du Web !
- Fonctionne avec du `XML`, et du `CSS` (ou un truc dans le genre)

**Rive**
- Outils propriétaire qui est intéressant pour construire des UI
- C'est un package Unity

**Game UI DB**
- Site internet qui références beaucoup d'UI de jeux vidéo
- Permet de regarder comment les autres jeux on conçu leurs UI !
- Parfait pour s'inspirer et très très cool !


