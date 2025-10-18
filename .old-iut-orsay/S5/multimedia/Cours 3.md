# L'image

## Acquisition

Un capteur optique fonctionne généralement à l'aide d'une grille de capteurs photosensibles qui laissent passer le courant éléectrique lorsqu'ils sont touché par des photons, de la lumière !!

**Onde lumineuse (photons) => | Capteur Optique | => Signal électrique**


Résolution = Taille de l'image, nombre de pixel total (ex: 1920 * 1080)


Plusieurs type de capteur optique :
- **Caméra tri-CDD** : Trois matrices CCD, et un seul passage. Chaque matrice correspond à une couleur primaire (rouge, vert blue)
- **Caméra mono-CDD** : Un seul capteur, une mosaïque de filtres


## Synthèse additive et soustractive

- Additive (ondes lumineuses) = Couleurs primaires : RGB (Red, Blue, Green)
- Soustractive (peintures) = Couleurs primaire : CMY (Cyan, Mauve, Yellow)

## Autres moyens de produire une image ?

- **IA générative** : ex Lexica.art (open source)

## Exemple de Formats

- **.BMP** : Aucune compréssions donc taille de fichir importante
- **.PNG** : Compréssion sans perte, transparence, robuste
- .**JPG** : Compréssion avec perte, réduction de taille importante, pas de transparence
- **.TIFF** : Avec ou sans perte. Format propriétaire Adobe
- .**WEBP** : Compréssion sans perte, transparence, métadonnées, profil de couleur ICC, animation. Format ouvert par Google

Libre de doit et opensources : .PNG, .BMP, .JPG

Canal *alpha* = transparence

## Représentation des couleurs

### RGB
- Canal Rouge, Canal Vert, Canal Bleu
- Une image est souvent coder par 8 bits par canaux RGB

On pourrais représenter tout les couleurs d'une image dans un "cube" 3D. Un repère 3D

**Incovénient de la représentation RGB**
- Toutes les couleurs visible ne sont pas représentable
- Couleurs difficilement interprétables
- Chaque composante est sensible au changement d'éclairage

### HSV
Représentation en teinte saturation et valeurs

Aproche psychologique de la perception des couleurs :
- Teinte (Hue en anglais) : couleur
- Luminosité : clair, foncée
- Saturation : pureté (couleur peu saturé = délavée)

**Inconvénients**
- La teinte est mal dfinie pour les luminosité faibles

**Avantages**
- Composantes décorrélées
- Teinte et saturation ne sont pas sensibles aux changement d'éclairage et ombre

### CIELAB
Composantes
- L : clarté, luminosité
- a : chrominace vert -> rouge
- b : chrominance bleu -> jaune

**Avantage**
- Une distance LAB est corrélé avec la distances perçu. utils por comparer des couleurs et évaluer la qualité de compréssion


## Histogramme

**C'est quoi?**
- Représentation graphique pour représenter le nombre de pixel/occurence de chaque couleurs
- Permet de voir la répartition des couleurs dans l'image
- Grace à ces histogramme on peut savoir si notre image est de bonn qualité

### Améalioration d'image

Les transformation d'image permettent de modifer la répartition des niveaux de gris, d'améliorer le contraste ou accroître l'entropie

- **Etirement ou normatlisation** : $I'=$  => Permet d'améliorer le contraste
- **Egalisation d'histogramme**
- **Logarithme**
- **Exponentielle**

### Autres utilisations

Dans opencv : Equaliszation; Calculation, Comparaison, Back Projetection, Template Matching

Backprojection, exemple :
- Permet de déterminé les différentes zone de l'image.