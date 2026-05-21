---
title: TD1
---

## Exercie 8

### II. 

Théorème des limites centrales :

$$
\frac{Y - E(Y)}{\sqrt{Var(Y)}} = Z \rightarrow N(0, 1)
$$

1.

$Y$ suit une loi Binomiale de paramètre $n = 50 + m$ et $p = 2/3$

2.

$$
E(X) = (2/3) \times (50 + m) \ \ et \ \ Var(Y) = (2/9) \times (50 + m)
$$

3.

$$
P(Y \le 50) = 98\%
$$

On peut essayer de transformer la partie gauche avec $Y$ en $Z$ grace au théorème des limites centrales.

$$
P(\frac{Y - E(Y)}{\sqrt{Var(Y)}} \le \frac{50 - E(Y)}{\sqrt{Var(Y)}}) = 0.98
$$

On peut alors transformer la partie gauche en $Z$

$$
P(Z \le \frac{50 - E(Y)}{\sqrt{Var(Y)}}) = 0.98
$$
Puis on remplace par les valeurs

$$
P(Z \le \frac{50 - (50 + m) \times 2/3}{\sqrt{\frac{2}{9}(50 + m)}}) = 0.98
$$


Ici on veut alors trouver la valeur de $Z$ pour $P(Z \le x) = 0.98$

Cette valeur peut être chercher dans le tableau des valeur de la loi normal, on y trouve la valeur : $P(Z \le 2.05) = 0.98$

On en déduit

$$
\frac{50 - (50 + m) \times 2/3}{\sqrt{\frac{2}{9}(50 + m)}} = 2.05
$$


On peut ensuite transformer notre calcul sous la forme d'une équation du secondé degré par rapport à $m$.

Le reste de la solution est de résoudre c'est équation pour trouver ses polynomes. La correction est dans le TD.
