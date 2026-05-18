# Lois Continue

## Loi uniforme

Elle modélise une varaible qui as un comportement uniforme en $[a, b]$ Si $X \text{\textasciitilde} \ U([a,b])$

$$
f(x) = \frac{1}{b - a}1_{[a,b]}(x) = \{ \frac{1}{b-a}, si \ x \in [a, b], 0 \ sinon
$$


$$
E(X) = (a + b) / 2, \ \ \ Var(X) = (b-a)^2 / 12
$$


### Foncition de répartition

$$
F(x) = P(X \leq x) = \int^x_{a} f(t)dt =  \frac{x-a}{b-a}, si \ x \in [a,b] , \ 0 \ sinon
$$

## Loi exponentielle

Elle décrit des phénomène de temps d'attente, durée de vie.

$1/\lambda$, avec $\lambda > 0$ est l'espérance de vie (ou le temps moyen d'attente)

$$
f(x) = \lambda e^{-\lambda x} \ si \  x \ge 0, \ 0 \ sinon.
$$

Si $X \text{\textasciitilde} \ \varepsilon(\lambda)$ on as :

$$
E(X) = 1/ \lambda, \ \ \ Var(X) = \frac{1}{\lambda^2}
$$



### Fonction de répartition

$$
F(x) = \int^x_0 \lambda e^{-\lambda t}dt = 1 - e^{-\lambda x}
$$

## Loi Normale

Aussi appelé Laplace-Gauss ou gaussienne

On dit que X suit une loi normale : 
$$
X \text{\textasciitilde} \  N(\mu, \sigma^2)
$$

$$
f(x) =  \frac{1}{\sigma \sqrt{2\pi}} \times e^{\frac{1}{2} \frac{(x - \mu)^2}{\sigma^2}}
$$

### Gaussienne centrée réduite

Soit $X \text{\textasciitilde} \  N(\mu, \sigma^2)$

On prend la loi $X$ qui n'est pas centrée et réduite, et on créer la nouvelle loi $Z$ qui est la version centrée et réduite de $X$.

$$
Z = \frac{X - \mu}{\sigma} \ \text{\textasciitilde} \  N(0, 1)
$$

C'est la **gaussienne centrée réduite** !

Quand $N(0, 1)$ alors la v.a $X$ est symétrique :

- $P(-X \leq x) = P(X \leq x) = P(X \ge -x)$
- ...


## Loi du chi-deux à n degrée de liberté

On la note $X \chi_x$

$$
X = \sum^n_{i = 1} X^2_i
$$

...


## Loi desgrands nombres et TCL

Soit $X_1, X_2, X_3, \dots, X_i$, une suite de v.a idépendante identiquement distribué tel que,

Alors $E(X_1) = \mu$, avec probabilité $1$, la moyenne empirique.

$$
\bar{X}_n = \frac{1}{n} \sum X_i \rightarrow \mu
$$
Quand $n$ tend vers +$\infin$

C'est un peu près

$$
\sqrt{n} \frac{\bar{X}_n - \mu}{\sigma} =  N(0, 1)
$$
