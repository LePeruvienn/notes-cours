# Introduction

En général lorqu'on as un problème on le décrit par un modèle de math. Souvent relier à une fonction qu'on peut optimiser.

Le but de ce cours est :

- D'introduire les fondement théorique garantissant l'exisitance ou l'unicité d'un problème d'optimisation

- De trater le cas quadratique ou la solution est explicite

- De donner des outils umériuqe d'approximation de la solution lorsqu'elle peut être décrite analytiquement

- introduction à la programmation linéaire

**Exemple 1** : Déterminé le placement d'un nouvelle gare entre les villes $V_1$ et $V_2$.

On suppose que le nombre de voyageur potentielle de chaque ville est $n$ et $m$.

Avec $x_i \in R^2$ qui corresspond la position d'un habitant d'une des villes.

Le but est d'alors trouvé un point $g^*$ qui est la position ou est construite la nouvelle are dont lequel la distance moyenne de touts les habitant pour allez à la gare est la plus petite.

Donc 

$$
v(g) = \frac{1}{N}\sum^N_{i = 1} dist(x_i, g)^2
$$

Avec $v(g)$ la distance moyenne de chaque habitant à la garde $g$.

**Exmple 2** : 

On considère le modèe de régréssion linéaire $y_i = ax_i + b + \epsilon_i$

On rappelle que une régréssion linéaire c'est de vérifier et essayer de rapprocher une série de résultat, vers une fonction. Par exemple voir si les stats trâce une fonction $e(x$) ou autres avec ici $\epsilon$ qui est l'erreur.

On cherche à déterminé la droite de régréssion: les coefficients $a$ et $b$ qui minimise la somme des carrés des érreurs donnée par :

$$
M(a,b) = \sum^n_{i = 1} \epsilon_i^2 = \sum^n_{i = 1}(y_i - ax_i -b)^2
$$


**Exemple 3** : Un téléphone mobile se trouve à une distance $x$ d'une station de base (station 1).

Une autres station voisine (station 2) emet des signaux mobile de même puissance vers la station 1.

...

##  Vecteur grandient

En fait c'est un vecteur composer des dérivé partielle de $x$

$$
\mathbf{f(x)} = \begin{pmatrix} 
    \frac{d(x)}{x_1} \\
    \frac{d(x)}{x_2} \\ 
    \frac{d(x)}{x_3} \\ 
    \dots
\end{pmatrix}
$$

avec $\frac{d(x)}{x_i}$ la **dérivé partielle** de $f$ en $x$.

## Dérivation partielle

$$
f'(x) = lim_{h \rightarrow 0} = 
\frac{f(x + h) - f(x)}{h}
$$


## Matrice hessienne


