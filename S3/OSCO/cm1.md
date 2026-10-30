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

**Exemple** : 

$$
M(a,b) = \sum^n_{i = 1} (y_i - ax_i - b)^2
$$

Dérivé partielle de $M(a,b)$ par rapport à $a$ :
- $\sum^n_{i = 1} - 2 x_i \times (y_i - ax_i -b)$

Dérivé partielle de $M(a,b)$ par rapport à $b$ :
- $\sum^n_{i = 1} - 2 (y_i - ax_i -b)$

Après on peut mettre les deux dérvié partielle dans le vecteur gradient : 

$$
\triangledown M(a,b) = 
- 2 \times \sum^n_{i = 1}
\begin{pmatrix}
    x_i \times (y_i - ax_i -b) \\
    (y_i - ax_i -b)
\end{pmatrix}
$$


$$

$$

## Matrice hessienne

C'est la dérivé seconde de $f(x)$ par rapport à $x_i$ et $x_j$ (*pour tout $i$ et $j$ possible*)

 en gros c'est juste les dérivé partielle dérivé encore une fois entre toutes les dérivié partielle (☝️🤓):

$$
\triangledown^2f(x) = 
\begin{pmatrix}
    \frac{d(x)}{x_1 x_1} & \frac{d(x)}{x_1 x_2} \\
    \frac{d(x)}{x_2 x_1} & \frac{d(x)}{x_2 x_2}
\end{pmatrix}
$$

## Déterminant d'une matrice carrée

*Pour les matrices carré uniquement !!!!*

### La formule de Leibniz

Avec $sgn(\sigma)$ qui est dit "*signature du sigma*"

$$
det(A) = \sum_{\sigma \in S_n} sgn(\sigma) a_{1\sigma(1)} \dots a_{n\sigma(n)}
$$

- $\sigma$ est une permutation de $E =$ {$1, 2 \dots, ..., n$}, c'est à dire une bijection de E sur lui même

- $S_n$ est l'ensemble des permutations de $E$, qui est le cardinal $n!$.

- Pour une permutation données $\sigma$, la paire $(i, j)$ avec $i < j$, est une inversion pour $\sigma$ si $\sigma(i) > \sigma(j)$

- Une permutation est dite paire si elle présente un nombre paire d'inversion. Sinon elle est dite impaire.

- La signature $sgn(\sigma)$ d'un permutation paire $\sigma$ vaut $sgn(\sigma) = 1$ et celle d'une permutation ...

Exemple =

$$
A = \begin{pmatrix}
    a_{1,1} & a_{1,2} \\
    a_{2,1} & a_{2,2}
\end{pmatrix}
$$

### Formule de Laplace

*Utiliser en programmation !!!*

$$
det(A) = \sum_{j = 1}^n (-1)^{i+j} a_{i,j}M_{i,j} = \sum_{i = 1}^n (-1)^{i+j} a_{i,j}M_{i,j}
$$

Avec $M_{i,j}$ la matrice aux coordonnées $i,j$

**Exemple**

$$
A = \begin{pmatrix}
   -2 & 1 & 3 \\
    1 & 2 & 1 \\
    0 & 1 & -1
\end{pmatrix}
$$

$$
det(A) = (-1)^{1+1} \times (-2) \times M_{1,1} \\
\dots
$$

### Applications

#### Résolutions de système linéaires

Soit $A$ une matrice carrée $n \times n$ tel que $det(A) \ne 0$.

On veut résoudre le système linéaire $Ax = b$

$$
x = A^{-1} b
$$

ou $A^{-1}$ est l'inverse de la matrice $A$ définie par

$$
A^{-1} = \frac{1}{det(A)} com(A)^T
$$

Avec $com(A)$ la **comatrice** défini par : 
- $com(A) = ((-1)^{i+j}M_{i,j})_{1 \leq i,j \leq n}$
- Avec $M_{i,j}$ est le déterminant de $M$ à $i,j$.


**Exemple** : résoudre le système linéaire $Ax = b$, avec :

$$
A = \begin{pmatrix}
    2 & -2 \\
    -1 & 3
\end{pmatrix}
$$

et 

$$
B = \begin{pmatrix}
    1 \\
    2
\end{pmatrix}
$$

On as $A^{-1}$

$$
A^{-1} = \frac{1}{det(A)} com(A)^T
$$

$$
com(A)^T = \begin{pmatrix}
    3 & 1 \\
    2 & 2
\end{pmatrix}^T 
 = \begin{pmatrix}
    3 & 2 \\
    1 & 2
\end{pmatrix}
$$

et 

$$
det(A) = (2 \times 3) - (-1 \times -2) = 6 - 2 = 4
$$

$$
A^{-1} = \frac{1}{4} \times 
 \begin{pmatrix}
    3 & 2 \\
    1 & 2
\end{pmatrix}
= \begin{pmatrix}
    3/4 & 2/4 \\
    1/4 & 2/4
\end{pmatrix}
$$

On as alors 

$$
x = A^{-1} b = \frac{1}{4}
 \begin{pmatrix}
    3 & 2 \\
    1 & 2
\end{pmatrix}
 \begin{pmatrix}
    1 \\
    2
\end{pmatrix}

$$


## Matrice (semi-) définie positive

**Définition** : On appelle *vecteur propre* le vecteur qui multiplier par *la valeur propre* donne le vecteur défini.

$$
Ax = \lambda x
$$

Avec $\lambda$ la valeur propre de A et $x$ le vecteur propre

**Définition** : Une matrice carré $A$ est *semi-définie positive*, si elle est symétrique et toutes ses valeurs propres sont positives ou non nulles.

**Notation** : On note $A^{(r)}$ *la source matrice principale d'ordre $r$* de $A$.

Exemple : 
1. $A = \begin{pmatrix}
    2 & -1 \\
    1 & 2
\end{pmatrix}$ alors $A^{(1)}= [2]$ et $A^{(2)} = 1$

2. $A = \begin{pmatrix}
    2 & -1 & 3 \\
    1 & 2 & 4 \\
    2 & 3 & 4
\end{pmatrix}$ alors $A^{(1)}= [2]$ 

   et $A^{(2)} = 
\begin{pmatrix}
    2 & -1 \\
    1 & 2
\end{pmatrix}$ et $A^{(3)} = A$


#### Théorème

Si une matrice systèmérique de taille $n \times n$ :

1. A est défini positive si eet seulement si : $x^T Ax > 0$
2.  A est défini positive si eet seulement si : $det(A^{(r)}) > 0$


**Exemple** : Montrer que la matrice est semi positive

$$
A = \begin{pmatrix}
    2 & -1 \\
    -1 & 4
\end{pmatrix}
$$

2. On veut prouver que : $det(A^{(r)}) > 0$

$A^{(1)} = [2]$

$A^{(2)} = A$

On as $det(A^{(1)}) = 2$ et $det(A^{(2)}) = 7$ donc tous $> 0$ donc propréité 2 validé !


1. On veut prouver que : $x^T Ax > 0$

On as $x^T Ax = [Ax, x] > 0$ avec 

$$
x = \begin{pmatrix}
    x_1 \\
    x_2
\end{pmatrix}
$$

Ce qui nous donne :


$$
x^T Ax = \begin{pmatrix}
    x_1 x_2
\end{pmatrix} \times
\begin{pmatrix}
    2 & -1 \\
    -1 & 4
\end{pmatrix} \times
\begin{pmatrix}
    x_1 \\
    x_2
\end{pmatrix} \\
 
= 2x_1^2 - x_1x_2 - x_2 x_1 + 4x^2_2 \\
= 2x^2_1 - 2x_1x_2 + 4x^2_2\\
= x^2_1 + (x_1 - x_2)^2 + 3x^2_2
$$

Donc ici pour $x_1$ et $x_2$ $> 0$ alors c'est toujours positf


**Rappelle** : quand on multiplie des matrices de taille différent mais $p$ égaux on as :  $(n, p) \times (p, m) \rightarrow (n,m)$

**Exemple 2** : Prouver que la caractérisque 1.

$$
A = \begin{pmatrix}
    2 & -1 & 0 \\
    -1 & 2 & -1 \\
    0 & -1 & 2
\end{pmatrix}
$$

$$
x = \begin{pmatrix}
    x_1 \\ x_2 \\ x_3
\end{pmatrix}

et \ x^T = \begin{pmatrix}
    x_1 & x_2 & x_3
\end{pmatrix}
$$

$$
x^T Ax = \begin{pmatrix}
    x_1 & x_2 & x_3
\end{pmatrix} \times
\begin{pmatrix}
    2 & -1 & 0 \\
    -1 & 2 & -1 \\
    0 & -1 & 2
\end{pmatrix} \times
\begin{pmatrix}
    x_1 \\ x_2 \\ x_3
\end{pmatrix} \\
= 2x^2_1 - 2x_1x_2 - 2x_2x_3 + 2x^2_3 \\
= x^2_1 + x^2_3 + (x_1 - x_2)^2
$$

$x^2_1 + x^2_3 + (x_1 - x_2)^2$ toujours $> 0$ dans $R$ car c'est une somme de carré.


#### Matrice symétrique.

Si une matrice est de taille $n \times n$ et elle est symétrique, alors il suffit de vérifié que tout les déterminant de la matrice $A^{(n)}$
