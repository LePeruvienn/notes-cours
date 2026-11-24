# Lumières

## Ça vous fait pensez à quoi ?

- Raytracing
- Global Illumination (GI)
- Point vs Directional light
- Ombres, (précalculer ou *bake*, vs dynamique)

## Généralité sur la lumière

Possède à la fois les propritété d'une onde et d'un corpuscule
- Onde : possède une longeur d'onde une amplit
- Corpuscule : se déplace en ligne droite

### Onde

Spectre d'absorption / émission
- Quand un photo passe dans un gaz, il va être filtrer par le spectere d'emission du gaz


### Corpuscule

Composante diffuse et spéculaire
- Diffuse : Le fait que les rayon rebosside et ce qui créer un "dégrader du plus au moins lumineux sur la surface"
- Spéculaire : Le reflet de la lumière qui est la ou il y a la plus grande concentration de rayon.
- Shininess : à quelle moins la spécular à un impact et sur quelle forme.
- Emissive : commentun objet renvoie de la lumière
- Réfraction : comment l'objet reflette ce qu'il y a autour de lui


### La robe

La robe est bleu et noir il y a pas de débat (c'est le prof qui l'as dit).

### Couleur additive / soustractive

Rendu numérique : **RGB**
> Couleur additive

Impréssion : **CMYK**
> Couleur soustractive


## Les materiaux de rendu

### VertexLit

C'est lorsqu'on applique le calcule de l'éclairage sur chaque vertex, au lieu de chaque chaque pixels.
> Cela rendu alors le rendu plus rapide, mais moins "bien" car l'éclairage peut sembler moins réaliste, moins juste.

### Diffuse

C'est commme le vertex lit sauf sur chaque pixels.

### Spécular

On en as parler avant.



### Parallax Bumped Specular

Il ya la **normal map** :
> C'est une image RGB qui contient les vecteurs normal de chaque "pixel" de la géométries.
> Ces vecteurs normaux sont utilisé lors du calcul de l'éclairage de l'objet, modifié la normal map
>  permet alors de changer alors la manière dont l'objet est éclairer

Et la **height map** :
> C'est une texture qui contient qu'une seul couleur, il permet de définir quelle est le relief de chaque pixels.

En fait c'est quand on utilise les deux ça fait du coup un parralax + bumped.


