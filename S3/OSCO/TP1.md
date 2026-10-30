# TP1

## Exercice 1.

Avec $x = (x_1, x_2)$

$$
f(x) = 100(x_2 - x_1^2)^2 + (1 - x_1)^2
$$

2. Vérifier à la main que $(1, 1)$ est bien un minimum local de $f(x)$

On commence par calculer le vecteur gradient de $f(x$),

On fait la dérivée partielle de $x_1$ par rapport à $f(x)$

$$
\frac{d(x)}{x_1} = 
100 \times 2 \times -2x_1\times(x_2 - x_1^2) + 2(1 - x_1) \\
= -400x_1 (x_2 - x_1^2) - 2(1 - x_1)
$$

On fait la dérivée partielle de $x_2$ par rapport à $f(x)$

$$
\frac{d(x)}{x_2} = 100 \times 2 \times (x_2 - x_1^2) = -200x_1^2  + 200x_2
$$

Ce quinous donne le vecteur gradient $\nabla f(x)$.

$$
\nabla f(x) =
\begin{pmatrix} 
    \frac{d(x)}{x_1} \\
    \frac{d(x)}{x_2} \\
\end{pmatrix}
= \begin{pmatrix} 
    -400x_1 (x_2 - x_1^2) - 2(1 - x_1) \\
    -200x_1^2  + 200x_2
\end{pmatrix}
$$

On vérifie alors la première condition que $\nabla f(1, 1) = 0$.

$$
\nabla f(1, 1)
= \begin{pmatrix} 
    -400 (1 - 1) - 2(1 -1 ) \\
    -200+ 200
\end{pmatrix}
= \begin{pmatrix} 
    0 \\
    0 \\
\end{pmatrix}
$$

La fontion vérifie bien la première condition, on passe alors à calculer la matrice héssienne :


On fait la dérivée partielle de $\frac{d_(x)}{x_1}$  par rapport à $x_1$.

$$
\frac{d(x)}{x_1 x_1} =
-400(x_2 - x_1^2) -400x_1 \times -2x_1 + 2
$$


On fait la dérivée partielle de $\frac{d_(x)}{x_1}$  par rapport à $x_2$.

$$
\frac{d(x)}{x_1 x_2} = -400
$$


On fait la dérivée partielle de $\frac{d_(x)}{x_2}$  par rapport à $x_1$.

$$
\frac{d(x)}{x_2 x_1} = -400
$$

On fait la dérivée partielle de $\frac{d_(x)}{x_2}$  par rapport à $x_2$.

$$
\frac{d(x)}{x_2 x_2} = 200
$$

Ce qui nous donne la matraice héssienne $\nabla^2 f(x)$ :

> En fait il faut que tout les détermiant de l'odre mineur de la matrice soit supérieur à 0. Donc ici il manque faire $A^{(1)}$ car ici on as fait $A^{(2)}$

$$
\nabla^2 f(x) = \begin{pmatrix} 
    1200x_1^2 - 400x_1 + 2 & -400x_1 \\
    -400x_1 & 200 \\
\end{pmatrix}
$$

Ensuite on vérifie que $\nabla^2 f(1, 1)$ est semi défini positive :


$$
\nabla^2 f(1, 1) = 
\begin{pmatrix} 
    1200 - 400 + 2 & -400 \\
    -400 & 200 \\
\end{pmatrix} =

\begin{pmatrix} 
    802 & -400 \\
    -400 & 200 \\
\end{pmatrix}
$$

Notre matrice $\nabla^2 f(1,1)$ est une matrice héssienne symétrique donc pour déterminé qu'elle est défini positive on calcul son déterminant :

$$
det(\nabla^2 f(1, 1)) 
= (802 \times 200) - (-400 \times -400) \\
= 160 \ 400 - 160 \ 000 \\
= 400
$$

$det(\nabla^2 f(1, 1)) = 400 > 0$ donc la matrice est bien déini positive !


Elle vérifie alors bien les deux condition donc $(1, 1)$ est bien le minimum de $f(x)$.


