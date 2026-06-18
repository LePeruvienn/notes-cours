# Intervall de confiance

## Révisions

- Variables aléatoire continues (notamment gaussienne)
- Loi des grands nombre et le théorème central

## IC asymptotiue

Dans une gaussienne centrée en 0, il ya la propriété qu'on dit "asymptotique".

On as :

$$
P(Z \le -x) = 1 - P(Z \le x) = P(Z \ge x)
$$

Par exemple :

$$
P(Z \le - 0.33) = 1 - P(Z \le 0.33) = P(Z \ge 0.33)
$$

## Intervale de confiance

### Construction d'un intervalle de confiance

On appel intervalle de confiance (IC) de niveau de confiance $1 - \alpha$ pour $\theta$, un intervalle aléatoire $[ T_1, T_2]$ dépednant des observations et tel que

$$
P(\theta \in [T_2, T_2]) = 1 - \alpha
$$

Soit $X_1, \dots, X_n$ un échantillon de la loi de $P_{\theta}$.

- Variance empirrique sans bias : ...
- Le reste la même

### IC pour la $\mu$ dans le modèle $N(\mu, \sigma^2)$

**ICI C'ESt QUAND ON ESTIME $\mu$ !!**
En gros on  essaye de trouver du coup l'intervale de l'espérance.

Avec $\sigma$ **connu**, l'intervalle est :

$$
[\bar X_n - \frac{\sigma}{\sqrt{n}} \times q_{1 - \alpha / 2},
 \bar X_n + \frac{\sigma}{\sqrt{n}} \times q_{1 - \alpha / 2}]
$$


Avec $\sigma$ **inconnu**, l'intervalle est :

$$
[
\bar X_n - \frac{S_n^2}{\sqrt{n}} \times t_{1 - \alpha/2}
\bar X_n + \frac{S_n^2}{\sqrt{n}} \times t_{1 - \alpha/2}
]
$$

**Calcul Quantile d'ordre 1** ($q$ ou $t$) :

$$
P(Z \le q_{1 - \alpha /2}) = 1 - \alpha / 2
$$

Avec $Z$ suit la loi Normal $N(0, 1)$ (si on connais $\sigma$).

(donc en gros après il faut chercher sur la table de la loi normal)


### IC pour la $\sigma$ dans le modèle $N(\mu, \sigma^2)$

Donc ici on veut l'intervalle de la variance, on estime $\sigma$ !!

...


### Exemple

Si onas un exemple d'une loi normale $N(\mu, \sigma^2)$


Avec 
- $n = 307$
- $\bar x_n = 1.05$
- $\sigma^2 = 0.2$

1. Donner un IC pour une moyenne $\mu$ de niveau de confiance de 95%.

On construit l'intervalle de confiance avec la formule :

$$
[\bar X_n - \frac{\sigma}{\sqrt{n}}q_{1 - \alpha / 2},
 \bar X_n + \frac{\sigma}{\sqrt{n}}q_{1 - \alpha / 2}]
$$

La valeur de premier quaritle pour une Loi Normale $N(0, 1)$ est $1.96$ (il faut chercher sur la feuille)

On as alors: 

$$
[1.05 - \frac{\sigma}{\sqrt{n}} \times 1.96 , \
 1.05 + \frac{\sigma}{\sqrt{n}} \times 1.96 ]
$$

Avec $\frac{\sigma}{\sqrt{n}} = \frac{\sqrt{0.2}}{\sqrt{307}}$

Ce qui nous donne

$$
[1, \ 1.1 ]
$$

## IC Asymptotique

Avant on faisais pour une loi Normale, mais ici le but est de pouvoir estimer pour toutes les lois de probabilitées.

Avec $\sigma > 0$ **connu**, l'intervalle est :

$$
[\bar X_n - \frac{\sigma}{\sqrt{n}} \times q_{1 - \alpha / 2},
 \bar X_n + \frac{\sigma}{\sqrt{n}} \times q_{1 - \alpha / 2}]
$$


Avec $\sigma >0$ **inconnu**, l'intervalle est :

$$
[
\bar X_n - \frac{S_n^2}{\sqrt{n}} \times q_{1 - \alpha/2}
\bar X_n + \frac{S_n^2}{\sqrt{n}} \times q_{1 - \alpha/2}
]
$$

Le calcul de $q$ se fait ave une loi Normale car comme on est dans une IC asymptotique c'est une loi normale.

### Exemple

On lance 50 fois une pièce de monnais avec (0 = face, 1 = pile)

1. Donner une estimation $\hat p$ de $p$

La moyenne empirique est le $p$ estimer qu'on appel $\hat p$

$$
\hat p = \bar x_n = \frac{1}{n} \sum x_i = 0.32
$$

2. Déterminer un IC pour $p$ de niveau asymptotique 95%

On calcul la variance empirique

$$
S^2_n = \frac{1}{n} \sum (x_i - \bar x_n)
$$

On as $1 - \alpha = 0.95$.

Donc pour calculer le quartile :

$$
P(Z \le q) = 1 - \alpha / 2
$$

Avec $Z$ Suit une loir normale comme on est dans une asymptotique.

Donc on peut check dans le tableau et on trouve $1.96$.

Après on peut faire la formule pour avoir l'IC.

$$
[
\bar X_n - \sqrt{\frac{S^2_n}{n}} \times 1.96, \ 
\bar X_n + \sqrt{\frac{S^2_n}{n}} \times 1.96
]
$$

## Tests paramétriques

### Théories des Tests

**Objectif**

Décidier à partir d'un échantillon observé $(x_1, \dots, x_n)$ si le paramètre de d'intrérêt $\theta \in O_0$ ou si plutot $\theta \in O_1$

- $O_0$ est appelé l'hypothèse nulle (c'est l'affirmation de départ)
- $O_1$ est appelé l'hypothèse alternative

D'abord on commence à supposé que $O_0$ est vrai

##### Erreur de 1ère et de 2nd espèce

La décisionde rejeter ou non l'hypthèse nulle est soumise à 2 types d'érreurs :

**Erreur de 1ère espèces** :
Rejeter l'hypothèse nulle $H_0$ alors qu'elle est vraie. On lui aussi le risque de 1ère espèce $P_{\theta_0}(R)$ qui est la proba de rejeter $H_0$ alors qu'elle est vraie.

**Erreur de 2nd espèces** :
Ne pas rejeter $H_0$ alors qu'elle est fausse. ON assoicie ce risque à $P_{0_1} (R^c)$, qui est la proba de ne pas rejeter $H_0$ alors que $H_1$ est vrai.

$R$ est la région critique du test.

**Le risque de 1ère espèce est le risque le plus grave.**

##### L'approche de Neyman-Pearson

on cherche d'abord à minimiser le risque de 1ère espèces: on choisit $\alpha \in ]0,1]$ assez petit tel que $P_{\theta_0}(R) \leq \alpha$. Avec $\alpha$ est la proba de se tromper.

Après avoir déterminé $\alpha$ alors on déterminé $\beta$ qui est la proba qu'on se trompe dans la règle 2.

#### Exemple

Pour une loi binomial $B(321, p)$. On veut définir un $\alpha$  petit.

On fixe $\alpha = 0.025$

avec 
- $H_0 : p = 0.8$
- $H_1 : p = 0.76$

On a alors : $P_{0.8}(X \le 242) = 0.025$

On calcul $P_{0.8}(X \le 242)$ avec la fonction de répartition del a loi binomial $B(324, 0.8)$

Donc on rejette $H_0$ si $X \leq 242$.

### Exemple

On fait un test sur un nouveau vacn et le taux d'efficacité est supposé être de 80%.

On prend un échantillon de 321 personnes et on as eu 244 tomber malade (N) et 77 pas tomber malade (O).

On shouaite tester l'efficacité du vaccin.

On fait alors une loi de Bernouilli qu'on va estimer pour vériffier cela.

On as alors comme $p$ estimer :

$$
\hat p = 244 / 321 = 76\%
$$


Donc ici on veut alors utilisé la théorie des tests.

Pour cela on définit alors :
- $H_0 = p \in O_0$
- $H_1 = p \in O_1$

Ce qui donne

- $H_0 = p \in {0.8}$
- $H_1 = p \in {0.76}$
    - ou aussi : $H_1 = p \in [0, 0.8[$


D'abord on commence à supposé que $O_0$ est vrai.


....


## Exemple de région de rejet UPP

### Loi Binomial

Avec une loi normale gaussienne $B(n, p)$ avec $p \in [p_1, p_2]$


On as 
- $H_0: p = p_0$
- $H_1: p = p_1$

Après on rejette 

### Loi gaussienne

Avec une loi normale gaussienne $N(\mu, \sigma^2)$ avec $\mu \in [\mu_1, \mu_2]$

On as 
- $H_0: \mu = \mu_0$
- $H_1: \mu = \mu_1$

Statistique de test (avec h1 j'ai pas pu faire h2)

$$
\frac
{\sqrt{n}(\bar X_n - \mu_0)}
{\sigma} > q_{1 - \alpha /2}
$$
