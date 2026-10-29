# TD3

### Rappel formules

Moyenne

$$
\bar x = \frac{1}{n} \sum^k_{i = 1} n_i \times x_i
$$

Variance

$$
S^2_x = \frac{1}{n} \sum^k_{i = 1} n_i(x_i - \bar x)^2
$$

Ou

$$
S^2_x = \frac{1}{n} \sum^k_{i = 1} n_i x_i^2 - (\bar x)^2
$$

Covariance

$$
S_{x,y} = \frac{1}{n} \sum^k_{i = 1}  n_{i,j}(x_i - \bar x)(y_i - \bar y)
$$

Coéfficient de corrélation empirique de Pearson

$$
\hat r_{x,y} = \frac{S_{x,y}}{S_x \times S_y}
$$

Test de significativité

$$
T_n = \frac{\hat r}{\sqrt{1 - \hat r^2}} \times \sqrt{n - 2}
$$

Avec $T(n - 2) = 1 - \alpha/2$

Avec $Y = aX + b$

$$
\hat a = \frac{S_{x,y}}{S^2_x} \ , \ \hat b = \bar y - \hat a \hat x
$$

## Exercice 1

#### 1. Donner les moyenne à $10^{-3}$ près

Nombre d'echantillon : $\sum^n_{i = 1} n_i = 24$

$\bar x_n = 2,833$

$\bar y_n = 6,792$

#### 2. Donner les variances à $10^{-3}$ près

$S_x^2 = 0,722$

$S_y^2 = 3,332$

#### 3. Donner les Covariances à $10^{-3}$ près

$S_{x,y} = 1,465$

#### 4. Donner le coefficient de corrélation $\hat r$ et conclure quant à la qualité de cet ajustement.

$$
\hat r = \frac{S_{x,y}}{S_x \times S_y} = 0,608
$$

On voit que $\hat r > 0$ donc leurs liaison est positive.

#### 5. Effectuer le test de significativité (t-test) à 95% de $\hat r$ et conclure.

On va posé deux hypothèse : 
- $H_0$ avec $r = 0$ (hypothèse nulle) il n'y a pas de corréaltion linéaire significativite entre $X$ et $Y$.
- $H_1$ avec $r \ne 0$ (hypothèse alternative) il existe une corrélation significative entre $X$ et $Y$.


On commence par faire le $T_{calc}$ dit T calculer qui vaut :

$$
T_n = \frac{\hat r}{\sqrt{1 - \hat r^2}} \times \sqrt{n - 2} = 13,552
$$

On calcul ensuite la valeur qu'on as en fonction de student.

On est à un interval de confiance à 95%.

Donc on as $\alpha = 0.05$ 

Pour trouver le coéfficient de Student correspondnat on utilise la formule : 

$$
q = 1 - \alpha / 2
$$

Puis il faut trouver le degrés de libérté il est égale comme on as dit dans la formule :

$$
T(n - 2) = T(22).
$$

Donc on cherche dans le tableau de Student, $q_{0.975}(22)$

Dans le tableau on trouve la valeur $2,0709$.

C'est alors notre valeur critique ($T_{crit}$)

Ensuite on compare alors notre $T_{calc}$ et notre $T_{crit}$

- Si $T_{calc} > T_{crit}$ alors on rejette $H_0$ pour $H_1$
- Si $T_{calc} < T_{crit}$ alors on acceppte $H_0$

Ici on as $13,552 > 2,0709$ donc $T_{calc} > T_{crit}$ donc on rejette $H_0$ pour $H_1$.

Donc on as bien $r \ne 0$ Donc il y a bien une corréalation linéaire entre les deux.

## Exercice 2

| X\Y | 25 | 35 | 45 | 55 |
|-----|----|----|----|----|
| 3   | 3  | 1  | 1  | 0  |
| 5   | 1  | 5  | 0  | 0  |
| 7   | 0  | 1  | 3  | 0  |
| 9   | 0  | 0  | 1  | 2  |
| 11  | 0  | 0  | 2  | 0  |

#### 1. Déterminer les distributions marginales.

| $x_i$ | 3  | 5  | 7  | 9  | 11 |
|-------|----|----|----|----|----|
| $n_i$ | 5  | 6  | 4  | 3  | 2  |


| $y_i$ | 25 | 35 | 45 | 55 |
|-------|----|----|----|----|
| $n_i$ | 4  | 7  | 7  | 2  |

#### 2. Déterminer les moyennes marginales.

$n_x = 20$ et $n_y = 20$ donc $n = 20$

$\bar x_n = 122/20 = 6,1$

$\bar y_n = 770/20 = 38,5$

#### 3. Déterminer les variances marginales.

$S_x^2 = 6,59$

$S_y^2 = 82,75$

#### 4. Calculer à $0,01$ près le coefficient de corrélation entre les variables $X$ et $Y$ . Que peut-on en déduire ?

On commence d'abord par calculer la covariance

$$
S_{x,y} = 17,15
$$

Ensuite on calcul le coéfficient de Pearson empirique

$$
\hat r_{x,y} = \frac{S_{x,y}}{\sqrt{S_x} \times \sqrt{S_y}} = 
\frac{17,15}{\sqrt{6,59} \times \sqrt{38,5}} = 0,73
$$


#### 5. Effectuer le test de significativité du coefficient de corrélation entre $X$ et $Y$. Concluire sur le resultat de test à un niveau de confiance à 95%

On pose deux hypothèse
- $H_0$ avec $r = 0$, il n'y a pas de corrélation entre $X$ et $Y$
- $H_1$ avec $r \ne 0$, il y a une de corrélation entre $X$ et $Y$

On calcul d'abord la valeur de signification, qui est notre $T$ calculer.

$$
T_{calc} = \frac{\hat r}{\sqrt{1 - \hat r^2}} \times \sqrt{n - 2} = 4,59
$$

Puis on calcul  la valeur critrique

On as niveau de confiance à $95\%$ donc $\alpha = 1 - 0,95 = 0,05$.

On récupére le coéfficent de student qui est : $1 - \alpha / 2 = 0,975$.

Le degrès de liberté est $n -2 = 20 - 2 = 18$.

$$
T_{crit} = q_{0,975}(18 )= 2,101
$$

Ensuite on compare $T_{crit}$ et $T_{calc}$ : $4,59 > 2,101$

Donc $T_{calc} > T_{crit}$ alors on rejette $H_0$ pour $H_1$.

Il y a alors bien une corréalation entre $X$ et $Y$.

#### 6. Un ajustement linéaire est-il justifié ?


#### 7. Déterminer l’équation de la droite de régression de $y$ en $x$.

On pose $Y = aX + b$

$$
\hat a = \frac{S_{x,y}}{S^2_x} = 2,6
$$

et 

$$
\hat b = \bar y - \frac{S_{x,y \bar x}}{S^2_x} = 22,625
$$

On as alors $y = 2,6x + 22,625$
