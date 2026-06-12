# Estimation ponctuelle : Motivation

On étudie un phénomène aléatoire pur lequel on  des observations $x_1, \dots, ... x_n$, qu'on appel une échantillon de taille $n$, ou un $n$-echantillon.

**Exemple** : 

On fait un sondage sur un nouveau produit et on demande aux gens si ils ont aimé ou pas :

On as à la suite de cette expérience alors des résultats du type :
- $x_1 = N$
- $x_2 = O$
- $x_3 = N$
- $x_n = \dots$

**Question** : 

On note $p^* = P(O)$ la probabilité d'aimer le produit est ce qu'on peut estimer alors cette probabilité pour une plus grande partie de la population.


Donc ici comme on as que des réponse oui ou non.

On peut en déduire que cette loi suite une loi de Bernouilli de paramêtre $p$.


## Definition d'un EMM

Formule de la moyenne empirique :

$$
\bar X_n = \frac{1}{n} \sum^n_{i = 1} X_i \rightarrow \mu
$$
quand $n \rightarrow+\infin$

2. La variance empirique : 

$$
\bar S^2 = \frac{1}{n} \sum^n_{i = 1} (X_i - \bar X)^2
$$
quand $n \rightarrow+\infin$


Un **estimateur** de la variance théorique : $E(X_i - E(X_i))^2$


### Principe des méthode des moments

La mthéode des moment consiste à estimer le paramêtre $\theta^\star$ du modèle :

1. En égalisant les moment théorique dépendant de ce paramêtre,
2. avec les moment empiriques correspondants, qui ne dépend pas du paramềtre.

On espère en vertu de la loi des grands nombres, qu'au moins pour $n$ assez grand, la solution par rapport à $\theta$ du système d'équation.

$$
m_k(\theta) = M^k_n, 1 \le k \le d,
$$

soit proche $\theta^\star$ (puique M^k_n converge vers $m_k(\theta)$)


## Exemple d'EMM : Méthode de Bernouilli

On considère ule problème de sondage sur un produit avec
- $0 =$ aime pas le prduite
- $1 =$ aime le produit

Donnnées : $0, 1, \dots$

On considère que ces données sont issue d'un échantillons allant de : $X_1, \dots, X_{30}$.

Chacune de ces données suit une loi Bernuilli de paramêtre $p^\star \in [0, 1]$

##### 1. Donner un estimateur de $p^\star$ par la méthode des moments.

Loi de Bernouilli de paramêtre $1 - p^\star$, avec une moyenne empirique $\bar X$.

On engalisant ces deux moyenne on as $1 - \bar X$ est un estimateur de $p^\star$ par la méthode des moments.


##### 2. Donner un estimateur de $p^\star$ par à partir des données observées.

Une estimation de $p^\star$ est $1 - (1 / 30) \times \sum$



