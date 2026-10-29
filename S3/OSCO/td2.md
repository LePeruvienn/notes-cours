# TD2

## Exercice ?

$$
f(x) = 100 \times (x_2 - x_1^2)
$$

> 1) Montrer que $x^* = (1, 1)$ est l'unique minimum local de $f$.


On calcul le vecteur gradient, $\nabla f(x)$

$$
\begin{pmatrix}
\end{pmatrix}
$$


## Exercice 4.

Montrer que les fonction suivantes sont stcitement convexes sur les domianes indiqués.


> **A**. $f(x) = x^p,\  p > 1, \ x \in D = \ \ ]0, +\infin[$

On calcul la dérivé et la dérviée seconde

$$
f'(x) = p \times x^{(p - 1)}
$$

et 

$$
f''(x) =  (p \times x^{(p - 1)}) +
 p(p - 1) \times x^{(p - 2)}

 = 
$$

On peut en déduire que

$$
f''(x) > 0
$$

Donc selon les propriété du cours, $f(x)$ est dérivable deux fois et est défini semi positive.

Donc elle est convexe !

> **B.** $f(x) = e^{ax},\  a \ne 0, \ x \in R$

Calcul de la dérivée

$$
f'(x) = x \times e^{ax}
$$

Calcul de la dérivée seconde

$$
f''(x) = e^{ax} + x^2e^{ax}
$$


$x^2 > 0$ dans $R$ et $e^x$ > 0 dans $R$ aussi donc $f''(x) > 0$ supérieur à 0.

La fonction est bien convexe !!


> **C.** $f(x) = -log(x),\  x \in D \ ]0, +\infin[$

On Calcul de la dérivée

$$
f'(x) = \frac{-1}{x}
$$

Calcul de la dérivée seconde

$$
f''(x) = \frac{1}{x^2}
$$

$f''(x) > 0$ sur $R$ donc la fonction est bien convexe !!!


> Ensuite on veut montrer que la fonction suivant est convexe dans son domaine : 

$$
q(x) = \frac{1}{2} x^T Ax
$$

Avec

$$
A= \begin{pmatrix}
2 & -1 \\
-1 & 4 \\
\end{pmatrix}
$$

*Faut faire de la magie un peu* 🪄

On va passez en dimension 1.

On as donc 

On sait que $A$ est symétrique car $A = A^T$.



