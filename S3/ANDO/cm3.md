# Liaison entre deux variables quantitatives

Soient $X$ et $Y$ deux grandeurs statitstiques quntitatives observées sur $n$ individus.

Le but c'est de : 
- **Déterminer** s'il existe une relation entre $X$ et $Y$
- **Caractériser** la forme de liaison (positive ou négative, linéaire ou non linéaire, monotone ou non monotone)
- **Quantifier** l'intensité de la liason
- **Valider** la liasion identifier


L'analyse graphique permet de comprendre les différentes ces différentes caractéristiques.

Le **nuage de points** ou *scatter plot* est l'outil priviliégié, car il est le plus adapté à cela, notamment car :

- situer les proximité,
- voir ou ce groupe les points
- ...

## Liaison Linéaire

C'est toutes les liaison sur des nuages de points qui se comporte comme une droite.

**Liaison linéaire positive**  \
$X$ et $Y$ évoluent dans le même sens et sont croissant 🥐

**Liaison linéaire positive**  \
$X$ et $Y$ évoluent dans le même sens et sont décroissant 😢

## Liaison non linéaire

Quand on as des nuages de points mais qui n'évolue pas comme une droite.

**Liaison non-monotone non-linéaire**  \
C'est lorsqu'on as un nuage de points qui forme une courbe qui n'est pas croissante ou décroissante de façon constante (pics à la suite par exemple). On dit alors qu'elle est **non linéaire** car ce n'est pas une droite et en plus de ça **non-monotone**, car elle est pas seulement croissante ou non.


**Liaison monotone non-linéaire**  \
C'est lorsque le nuage de point ne comporte pas comme une droite, mais reste monotone (donc constamment croissant ou décroissante). On peut prendre pour exemple par exemple la courbe de $e^x$

## Covariance

### Définition

Elle permet de **quantifier la liason** entre deux variable quantitatives ($X$ et $Y$).

$$
Cov(X, Y) = E[(X - E(X)) \times (Y - E(Y))] \\
          = E(XY) - E(X) \times E(Y)
$$

Elle permet de mettre en avant sa liaison et son intensité.

- Si $Cov(X, Y) > 0$ : la relation est positive, 
- Si $Cov(X, Y) = 0$ : abascence de relation monotone
- Si $Cov(X, Y) < 0$ : la relation est négative

### Propriété

La covariance d'une variable $X$ dont $Var(X) > 0$ avec elle même est toujours positive.


**Symértique** : $Cov(X, Y) = Cov(Y, X)$


**Distributivité** : $Cov(X, Y + Z) = Cov(X, Y) + Cov(Z)$


**La convariance avec une constante est nulle** : $Cov(X, a) = 0$


**Covaraince avec une variable transformer** (transformation affine) : $Cov(X, a + bY) = b(X, Y)$


**Variance de la somme des deux varaible aléatoires** : $V(X + Y) = V(X) + V(Y) + 2 \times COv(X, Y)$

**Convariance de 2 variables indépendante est nulle** : $Cov(X, Y) = 0$


#### Exercice

Soit $X -  N(0, 1)$ et $Y = X^2$. $X$ et $Y$ sont elle indépendante ?

On veut calculer la covariance entre les deux.

On sait que :

$$
E(X) = 0 \ et \ Var(X) = 1
$$

On veut calculer la covariance entre les deux pour savoir si elles sont indépendante.

On déduit que :

$$
Cov(X, Y) = Cov(X, X^2)
$$

Ce qui nous donne :

$$
Cov(X, X^2) = E(X - E(X) \times (X^2 - E(X^2)))
$$

....

### Covariance Empirique

Sur un échantillon de taille $n$, l'estimateur biaisé de la convariance est : 

$$
S_{xy} = \frac{1}{n} \sum^n_{i = 1} (X_i - \bar{X_n}) (Y_i - \bar{Y_n})
$$

Estimateur sans biais de la covaraince s'écrit par conséquance ;

$$
S'_n = \frac{1}{n - 1} \sum X_i Y_i - \frac{n}{n -1} \bar{X}_n \bar{Y_n}
$$

## Corrélation de Pearson

Le problème de la covariance ce que l'intensité de la covariance qui est défini sur $R$ dépend alors de **l'ordre de grandeur**.

Donc en gros parfois $99.9$ ça peut être énorme et dans d'autres cas très peu.

> NOTE: Il marche seulement pour mesurer l'intensité des liaison linéaire


**Dans on utilise alors une mesure normalisé** : *Le coéficient de corrélation* !

$$
r = \frac{Cov(X,Y)}{\sqrt{Var(X) \times \sqrt{Var(Y)}}} 
= \frac{Cov(X, Y)}{\sigma_x \times \sigma_y}
$$

Avec $\sigma$ qui est l'écrat-type.

Le coéfficient de corrélation est indépendant des unitées de mesures des variables.

Elle est définis entre $-1 \leq r \leq 1$.

- $r = +1$ : la lisation entre $X$ et $Y$ est linéaire positive parfaite.
- $r = -1$ : la lisation entre $X$ et $Y$ est linéaire négative.

### Propriétés

Il est de même signes que la covariance, donc même interprétations.

Il sert avant tout à caractiriser une relation linéaire positive ou négative. 

Il s'agit d'une mesure symétrique, plus il est proche de $1$ plus la liaison est forte (même chose pour $-1$)


$X$ et $Y$ sont indépendante, alors $r = 0$, Et $r = 0$ indique l'absence de corrélation. Mais si $r = 0$, **ça veut pas dire que $X$ et $Y$ sont indépendante forcément!!** (*sauf si le couple ($X$, $Y$) suite une loi normale bivarié.*)

**Il permet de mesurer seulement l'intensité de liaison linéaire** ! Et ne veut pas dire qu'il y a pas une autres liaison si $r = 0$. Il peut toujours avoir une liaison fonctionnelle (dans le sens ça suit une fonction)


### Corrélation empirique

Sur un échantillon $n$ :

$$
\hat r = \frac
{\sum^n_{i = 1} (X_i - \bar X_n) (Y_i - \bar Y_n) }
{\sqrt{\sum^n_{i = 1} (X_i - \bar X_n)^2} \times (Y_i - \bar Y_n)^2}
$$

Dans la littérature

$$
\hat r = \frac
{\sum^n_{i = 1} X_i Y_i - n \bar X_n Y_n }
{\sqrt{\sum^n_{i = 1} X_i^2 - n \bar X_n^2} \times \sqrt{\sum^n_{i = 1} Y_i^2 - n \bar Y_n^2}}
$$

comment ça dans la littérature ça n'as aucun sens je comprend pas 🤯

## Interpréation graphique

Définition les vecteurs centrés :

Avec $x^c = (x_1 - \bar x_n, \dots, x_i - \bar x_n)$
et  $x^c = (y_1 - \bar y_n, \dots, y_i - \bar y_n)$

La corrélation empirique peut être égale à

$$
\hat r = \dots = cos(\theta)
$$

Donc $r$ empirique peut être à l'angle entre es deux vecteurs permet de connaitre


### Significativité adu coefficent de corréaltion



### Statitstique de test dans le cas gausien: test exacte


### Le reste en vrai c'est le cours de Sagna


### Remarques

- Sous $H_0$, $\hat r$ sut la loi Sutdent (simple), mais si $r \ne 0$, la loi exacte de $\hat r$ est compliqué.



## Corrélation de Spearman

Il existe plusieurs mesures de liaison entre variables quantitatives continues. 

- Il permet mesurer le degré d'association pour les liaison non linéaire aussi (contrairement à Pearson).
- Il fonctionne également pour des liaison monotones (et linéaire).
- Mais ilne permet pas de caractériqsé une liaison non monotone et non linéaire.

Il se base sur les rangs des observations. avec $R_i$ le rang des échantillons de $X$ et $S_i$ le rang des échnatillon de $Y$.

> NOTE: Les rangs c'est juste leurs place dans la série si elle était trier. Par exemple $S = [0, -1, 2]$ à pour rang : $R = [2, 1, 3]$. Avec 1 le premier nombre et 3 le nombre de valeurs de la série.

En fait Spearson c'est comme Pearson mais on se base sur les rangs des écantillongs.

On as donc 

$$
\rho = Cor(R, S)
$$

et en empirique :

$$
\hat p = \frac
{\sum^n_{i = 1} (R_i - \bar R_n) (S_i - \bar S_n) }
{\sqrt{\sum^n_{i = 1} (R_i - \bar R_n)^2} \times (S_i - \bar S_n)^2}
$$

Avec $\bar S = \bar R = \frac{n + 1}{2}$ 

et $Var(S) = Var (R) = \frac{n^2 -1}{12}$

Avec ça on peut simplifier la formule :

$$
\hat p = \frac
{12 \sum^n_{i=1} R_i \times S_i}
{n (n^2 - 1)}
- \frac{3n + 1}{n - 1}
$$

Et avec $d_i$ = $R_i - S_i$

$$
\hat p = 1 - \frac{6 \sum^n_{i = 1} d_i^2}
                  {n (n^2 -1)}
$$

### Interpréation

C'est similaire à Pearson : $-1 \leq \rho \leq 1$.

- Si $\rho > 0$ il y a une liaison monotone positive
- Si $\rho < 0$ il y a une liaison monotone négative
- Si $\rho = 0$ il y a pas de liaison monotone


Par contre $\rho^2$ n'as pas d'Interprétation statistique !


## Coéfficent de Kdenall $\tau$

Le coéfficent de Kednall reose sur de pars discordant et concordante.

- On dit que les pair sont concordante lorsque que : $(x_i - x_j) \times (y_i - y_j) < 0$
- On dit que les pair sont discrodantes lorsque que : $(x_i - x_j) \times (y_i - y_j) < 0$

Le but est de mesurer si les information sont dans le même sens 

Formule empririque avec $P$ le nombre de paires concondartent.

$$
\hat \tau = \frac{P - Q}{\frac{1}{2} n(n-1)}
$$
