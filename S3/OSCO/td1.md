# TD1

## Rappel dérivées

| $f(x)$   | $f'(x)$    |
|--------------- | --------------- |
| $au + bv$   | $au' + bv'$  |
| $uv$   | $u'v + v'u$   |
| $\frac{1}{u}$  | $-\frac{u'}{u^2}$   |
| $\frac{u}{v}$   | $\frac{u'v - v'u}{v^2}$  |
| $\sqrt{u}$   | $\frac{u'}{2\sqrt{u}}$  |
| $u^a$   | $au' \times u^{a-1}$  |
| $cos(u)$   | $-u' \times sin(u)$  |
| $sin(u)$   | $u' \times cos(u)$  |
| $u(v(x))$   | $u'(v) \times v'$  |


## Exercice 1

1. $f(x) = -3x^3 + 1$

$$
f'(x) = -9x^2
$$

2. $f(x) = -2(1 - x)^3 - 3x + 1$

$$
f'(x) = 6(1 - x)^2 + -3
$$

3. $f(x) = \frac{1}{2}x^2 - sin(x)$

$$
f'(x) = x - cos(x)
$$

4. $f(x) = sin(x) - cos(2x)$

$$
cos(x) + 2 sin(2x)
$$

5. $f(x) = \frac{2x - 1}{5x + 3}$

$$
f'(x) = \frac{2(5x + 3) - 5(2x - 1)}{(5x + 3)^2}
$$

6. $f(x) = \frac{1 + x^2}{1 + (2 - x)^2}$

$$
f'(x) = \frac
{2x(1 + (2 - x)^2) - (1 + x^2) \times -2 (2 - x)}
{(1 + (2 - x)^2)^2}
$$

7. $f(x) = ln(2 + x^2)$

$$

$$

## Exercie 2

1. Déterminé le gradient et la matraice hessienne des fonctions $f$ et $g$ suivantes définie sur $R^2$.

a) $x = 
\begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \rightarrow
f(x) = 3x_1 + x_2 - x_1 x_2 + x_1^2 + 2x_2^2
$

On fait la dérivé partielle de $x_1$ puis par $x_2$.

D'abord avec $x_1$ variable et $x_2$ constante :

$$
f_1'(x_1) = 3 - x_2 + 2x_1
$$

Puis $x_2$ variable et $x_1$ constante :

$$
f_2'(x_2) = 1 - x_1 + 4x_2
$$

Ce qui nous donnne le vecteur de gradient

$$
\triangledown f(x) = 
\begin{pmatrix} 
    f'_1(x_1) \\ 
    f'_2(x_2)
\end{pmatrix} \rightarrow

\begin{pmatrix} 
    3 - x_2 + 2x_1 \\
    1 - x_1 + 4x_2
\end{pmatrix}
$$

La matrice héssienne est égale à :

$$
\triangledown^2f(x) = 
\begin{pmatrix}
    f_{1,1}'(x_1) & f_{1,2}'(x_2) \\
    f_{2,1}'(x_1) & f_{2,2}'(x_2) 
\end{pmatrix}
$$

On as alors deux nouvelles valeurs à calculer :

- $f_{1,1}'(x_2)$ : dérivé partielle par rapport à $x_1$ de notre dérivé partielle de $x_1$ (on redérive en par la même chose)
- $f_{1,2}'(x_2)$ : dérivé partielle par rapport à $x_2$ de notre dérivé partielle de $x_1$
- $f_{2,1}'(x_1)$  : dérivé partielle par rapport à $x_1$ de notre dérivé partielle de $x_2$.
- $f_{1,2}'(x_2)$ : dérivé partielle par rapport à $x_2$ de notre dérivé partielle de $x_2$ (on redérive par la même chose)

Après avoir fait cela on obtient la matrice 

$$
\triangledown^2f(x) = 
\begin{pmatrix}
    2 & -1 \\
    -1 & 4
\end{pmatrix}
$$

et la on as terminé !!

b) On fait la même chose pour : 

$$
x = 
\begin{pmatrix} 
    x_1 \\
    x_2
\end{pmatrix} \rightarrow
g(x) = x_1^2 / x_2
$$

Dérivé partielle de $g(x)$ par rapport à $x_1$

$$
f'(x_1) = \frac{2 \times x_1}{x_2}
$$

Dérivé partielle de $g(x)$ par rapport à $x_2$

$$
f'(x_2) =  - \frac{x_1^2}{x_2^2}
$$

Ce qui nous donnne le vecteur gradient !

$$
f(x) = 
\begin{pmatrix} 
    f'(x_1) \\ 
    f'(x_2)
\end{pmatrix} \rightarrow

\begin{pmatrix} 
    \frac{2 \times x_1}{x_2} \\
    - \frac{x_1^2}{x_2^2}
\end{pmatrix}
$$


Il nous manque alors à calculer la matrice hessienne

$$
\triangledown^2f(x) = 
\begin{pmatrix}
    \dots
\end{pmatrix}
$$

et voila !

2.

Soit A = $\begin{pmatrix} 2 & -1 \\ -1 & 4\end{pmatrix}$

et soit la fonction $q$ définies pour tout $x = \begin{pmatrix} x_1 \\ x_2 \end{pmatrix} \in R^2$


