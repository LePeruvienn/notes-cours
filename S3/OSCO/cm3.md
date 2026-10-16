# Développement limité


**Théorème** supposons que $f : R^d \rightarrow R$ est différentiable. Alors $f$ est convexe si et suelement si $dom(f)$ est convexe et pour tout $x, y \in dom(f)$ :

$$
f(x) + \nabla f(x)^T (x - y) \leq f(y)
$$

> Note: $dom(f)$ veut dire domaine de $f$, donc $R$ ici.


### Exemple

$f : R \times R \rightarrow R$

$f(x_1, x_2) = 3x_1 + 4x_2 - x_1 x_2 + x_1^2 + 2x_2^2$

Le gradient est donné par : 

$$
\nabla f(x_1, x_2) = 
\begin{pmatrix}
     \frac{\partial f(x_1, x_2)}{\partial x_1}\\
     \frac{\partial f(x_1, x_2)}{\partial x_2}\\
\end{pmatrix} = \begin{pmatrix}
    3 - x_2 + 2x_1 \\
    4 - x_1 + 4x_2 \\
\end{pmatrix} \\
$$

et la matrice hessienne est donné par

$$
\nabla^2 f(x_1, x_2) = 
\begin{pmatrix}
     \frac{\partial^2 f(x_1, x_2)}{\partial^2 x_1} & \frac{\partial^2 f(x_1, x_2)}{\partial x_2, x_1} \\
     \frac{\partial^2 f(x_1, x_2)}{\partial x_1, x_2} & \frac{\partial^2 f(x_1, x_2)}{\partial^2 x_2} \\
\end{pmatrix} = \begin{pmatrix}
    2 & -1 \\
   -1 & 4 \\
\end{pmatrix} \\
$$


### Forme quadratique

$$
f(x) = \frac{1}{2} <Ax, x> + <b, x>
$$

> Info : $<Ax, x> = x^T Ax$, c'est le produit scalaire

Ce qui donne, *en dérivant* $f(x)$
- $\nabla f(x) = Ax + b$, qui est le vecteur gradient
- $\nabla^2 f(x) = A$, qui est la matrice héssienne


**On peut mettre les toutes les fonctions qui vont de $R^n \rightarrow R$ !**

Le but est d'en fait prendre des fonctions de cette forme vers une forme quadratique.


#### Exemple

$f : R \times R \rightarrow R$

$f(x_1, x_2) = 3x_1 + 4x_2 - x_1 x_2 + x_1^2 + 2x_2^2$

Ici on peut identifier les le vecteur $B$ facilement, c'est toutes les valeurs qui n'ont ni multiplication commune ni puissance.

Ici on as $3x_1 + 4x_2$ donc :

$$
B = \begin{pmatrix}
    3 \\
    4 \\
\end{pmatrix}
$$

Après pour trouver $A$ c'est plus compliquer.

On regarde les coefficient seul qui sont carré, on as $x_1^2 + 2x_2^2$.

C'est les coéfficent $1$ et $2$ mais comme dans la forme de base c'est $1/2 \times <Ax, x>$, on fait alors $\times 2$.

$$
A = \begin{pmatrix}
    2 & ? \\
    ? & 4 \\
\end{pmatrix}
$$


Pour les termes croisées, on voit qu'on as 
$- x_1 x_2$, on sait qu'il faut faire $\times 2$. On as donc $-2x_1 x_2$ qui est en soit $-x_1 x_2 - x_2x_1$. 

Donc on as pour les deux coéfficients $-1$ !

on as alors

$$
A = \begin{pmatrix}
    2 & -1 \\
    -1 & 4 \\
\end{pmatrix}
$$


### Convexité

Une fonction est convexe si :

$$u^T \nabla^2 f(x) u \geq 0$$

Avec $u$ un vecteur quelqconque non nulle.

#### Exemple

Montrer que les fonctions suivantes sont stritement convexes sur le domaine indiqué : 

1. $f(x) = x^p$ avec $p > 1$ et $x \in [0, +\infin[$

...


## Condition necessaire d'optimalité


Soit $f : R^d \rightarrow R$ deux fois différentiable sur n ouvert $O$ de $R^d$.

$$
\nabla f(x^*)
$$


