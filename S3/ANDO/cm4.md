## Equation de la droite des moindres carrés

On cherche à ajuster une droite d'équation $ax + b$ à un nuage de points.

On cherche donc le couble $(a, b)$ qui minimise

$$
f(\hat a, \hat b) = \sum (y_i - (ax_i + b))^2
$$

L'équation de la droite des moindres carrés de $y$ en $x$ :

$$
y = \hat a x + \hat b
$$

avec $\hat a = \frac{\hat S_{x,y}}{s_x}$ et $\hat b = \bar y - \hat a \bar x$

De même dans l'équationn de la droite des moindres carrées de $x$ en $y$ : 

$$
x = \hat a' y + \hat b'
$$


avec $\hat a' = \frac{\hat S_{x,y}}{s^2_x}$ et $\hat b' = \bar x - \hat a' \bar y$

## Qualité d'ajustement

On rapelle le coéfficient de corrélation :

$$
r_{x,y} = \frac{\hat S_{x,y}}{S_x \times S_y}
$$

Donc 

$$
\hat a = r_{x,y} \times \sqrt{\frac{S_y^2}{S_x^2}}
$$


$\hat r^2$a est le **coéfficient de détermination**. C'est la porportion de variance de $Y$ linéairement expliqué par $X$.

Le coéfficient de déterminiation est : 

$$
r^2_{x,y} = \frac{RSS}{TSS}
$$

Avec :
- $RSS = \sum^n_{i = 1} \epsilon_i^2$
- $TSS = \sum^n_{i = 1} (y_i - \bar y_n)^2$
- $ESS = \sum^n_{i = 1} (\hat y - \bar y)^2$ *Explained Sum Of Squares*

### Cirtère de comparaison de modèle

**Exemple** :  \
si $\hat r = 0.9$ onvit que la liason est forte puisqu'elle se rapporche de 1. C'est tout! Mais en revance avec $\hat r^2 = 0.81$, on peut dire que $81\%$ de la variance de $Y$ est expliqué par $X$ (et inversement).


**Limitations** :
- Le coeffcient de déterminal est une *fonction croissante* de la compléxité du modèle. Donc elle sera toujours **plus proche du modèle le plus complexe**, c'est donc **pas recommander à utliser sauf en cas de modèle à nombre de variable identitique**

- les deux mesures $\hat r$ et $\hat r^2$ **résume la force de corréaltion linéaire de l'échantillon uniquement**.


