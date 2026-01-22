**Info sur le DS** :
- On y aura peut être des preuves (mais c'est très rare)
- On aura surement le droit à une feuille

# Variable aléatoire 2

### Calcul de l'espérance

Calcul
$$
E(X) = \sum x_i \times P(X = x_i)
$$
Théorème des transferts
$$
E(f(X)) = \sum f(x_i) \times P(X=x_i)
$$

Calcul de la moyenne empirique, 
$P(X = x_i) = \frac{1}{n}$  pour toutes les valeurs alors
$$
E(X) = \frac{1}{n} \times \sum x_i
$$

### Calcul de la variance

Variance de X
$$
e_1 = \frac{1}{n} \times \sum_{i = 1}^{n}{(x_i - \bar{m}_{xy})^2} = E[(X - E(X))^2]
$$
Variance de Y
$$
e_2 = \frac{1}{m} \times \sum_{j = 1}^{m}{(y_j - \bar{m}_{xy})^2} = E[(Y - E(Y))^2]
$$

On peut factoriser ça avec : $f(x) = (x - E(X))^2$
$$
Ef(X) = E[(X - E(X))^2]
$$
**On as donc** 
$$
Var(X) = E[(X - E(X))^2] = E(X^2) - (E(X))^2
$$

### Écart-type

On appelle *écart-type* de X et on note $\sigma_x$  la racine carré de la variance
$$
\sigma_x = \sqrt{Var(X)}
$$

## Propriétés

*Voici quelques propriété sur l'espérance et la variance* : 

1) Pour toute v.a constante X : $E(X) = c$
2) *(Linéarité)* $E(aX + bY) = aE(X) + bE(Y)$
3) *(Positivité)* si $X \leq Y$ alors $E(X) \leq E(Y)$
   Ex: Avec $X$ et $Y = X^2$, alors pour tout $X(\omega) \leq Y(\omega)$, donc la propriété s'applique
4) Pour toute v.a $X$ on as : $Var(X) \geq 0$ et $Var(c) = 0$
5) Soit $X$ une v.a. Alors $Var(aX + b) = a^2Var(X)$

*(v.a  = Variable Aléatoire)*

**Remarque** :
$Var(X + Y) = Var(X) + Var(Y)$ **seulement si** $X$ et $Y$ sont indépendantes !!


# Loi usuelles

## Loi de Bernouilli

Expérience à 2 issues:

- succès de proba nommé : $p$
- échec de proba nommé : $q$ avec $q = 1 - p$

Si $X$ ~ $Bern(p)$, alors

$$
P(X = 1) = p \space ; \space P(X = 0) = 1 - p
$$
et on as
$$
E(X) = p \space ; \space Var(X) = p(1 - p)
$$

## Loi Binomiale

C'est la loi du nombre de succès à l'issue de $n$ épreuves indépendante, de *Bernouilli* et de paramètre $p$. Si $X$ ~ $B(n,p)$

$$
P(X = k) = C^k_n \times p^k \times (1 - p )^{n-k} \space, \space k = 0, \dots, n
$$
Avec
$$
C^k_n = \frac{n!}{k!(n-k)!}
$$

Une v.a $X$ ~ $B(n,p)$ peut être représentée par
$$
X = \sum^n_{i = 1} X_i
$$
Ou les $X_i, \space i = 1, \dots, n$ sont de v.a indépendantes, de loi de Bernouilli de paramètre $p$, Donc, 
$$
E(X) = np \space, \space Var(X) = np(1 - p)
$$

# Loi Discrètes

## Loi de Poisson

Permet de modéliser le nombre d'événements qui se produise pour une unité de temps ou de volume donnée, à un taux moyen fixé.

- Si $\lambda$ désigne le nombre moyen d'occurrences par unité de temps ou de volume fixé.
- Alors $X$ suit une une *Poisson* de paramètre $\lambda$ .
$$
P(X = k) = e^{-\lambda} \frac{\lambda^k}{k!} \space, \space k = 0, 1, 2, \dots
$$
C'est la proba qu'il se produise $k$ occurrences pour l'unité donnée. On a
$$
E(X) = \lambda \space , \space Var(X) = \lambda
$$
**Lien Poisson et Binomiale** :
La loi de *Poisson* peut être vu comme une approximation de la loi *Binomiale* de paramètres $n$ et $p$ lorsque $p \leq 0.1$ et $n \geq 40$ ou lorsque $np < 5$ .

## Loi géométrique

On renouvelle une épreuve de $Bern(p)$, de façon indépendante, jusqu'à l'obtention du premier succès. La v.a $X$ donnant le rang du premier succès suit une loi géométrique de paramètre de succès $p$. Si $X$ ~ $\gamma(p)$.
$$
P(X = k) = (1 - p)^{k - 1} p \space , \space k = 1, 2, \dots
$$
On a
$$
E(X) = \frac{1}{p} \space \ \ ; \ \ \space Var(X) = \frac{1 - p}{p^2}.
$$

**Preuve** (le prof l'as pas terminé ) :
$E(X) = \sum k \times P(X = k)$
 $= \sum k \times (1 - p)^{k - 1} \times p$
 $= p \times \sum_{k \geq 1} \ [(f_k(p))]'$
 $f_k(p) = - (1 - p)^k$


# Autres

**Théorème de la limite centrale** :
$$
\frac{Y - E(Y)}{\sqrt{Var(Y)}}
$$

