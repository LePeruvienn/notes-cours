# Cours super stylé

Les statistique **uniivariées** sont applicable à un ensemble de données avec une **seule variable**, ou aux variables **individuelle**.

## Mesure de tendance centrale

Une **mesure tendance centrale** est une valeur unqiue qui tente de crécire un ensemble de données en identifiant la position centrale au sein de cete ensemble.

- également classé comme statistique sommaires

Ils peuvent être utiliser pour répondre à des questions telles que : 
- "*Quel est le salaire médian d'un joueur de football ?*"
- "*Combien d'enfant à une famille française typique ?*"
- "*Quelle est la note moyenne pour cette examen ?*"

## Le mode

Ce sont la ou les valeurs les plus fréquente dans un ensemble de données

- Le mode est plus facilement identifié par un histogramme de fréquence ordonnée
- Sur un histogramme il représente la bar la plus élevée
- Le mode n'est pas nécessairement unique

**Varaible quantitative disctère** (non classé) \
Le *mode* corresspond à la variable pour laquelle l'effectif est le plus grand

**Variable quantitative continue** \
La *classe modale* est la classe dont la fréquence par une unité d'amplitude est la plus élevée; cette classe correspond donc au rectangle le plus haut de l'histogramme de fréquences.


**Exemple 1.** \
Soit $S =$ {$2, 3, 0, 1, 2 3, -1, 3$}, Lemode est done $M_o = 3$


## La moyennne

Le but est une donner un ordre de grandeur générale des observation.

$$
\bar X_n = \frac{1}{n} \sum^n_{i=1} x_i
$$

C'est un peu le "centre de gravité" des données affecté ou chaque individu à le même poid

Elle peut être considérer comme une **valeur centrale**, même si elle n'est pas égale à une des modalité !

*En gros elle n'est pas forcément une des valeurs de la série !!*


**NOTE** \
La moyenne est très sensible aux valeurs extrème dites valeurs aberrantes *logique* 🤓.


## La moyenne pondérer

*c'est quand même une dinguerie d'avoir un cours sur la moyenne* 🤯

ON pondère chacune des valeurs dintinces de $X$ par la fréaquence corresspondante.

$$
\bar X_n = \frac{1}{n} \sum^n_{i=1} x_i \times n_i = \sum^n_{i=1} x_i \times f_i

$$

ou $n_i$ désigne le nombre d'observation de la valeur $x_i$ et $f_i$ la fréqence de $x_i$.


Pour une variable $Y$ continue :

- Y est une varaible quantitative (*disctère ou continue*) diviser en $k$ classes distinctes.

Alors la moyenne arithmétique $\bar Y$ de $Y$ est défini comme la moyenne des centres des classes de $Y$ pondérée par les férquences correspondantes : 

$$
\bar Y = \frac{1}{N} \sum^n_{i=1} n_i \times \frac{y_{i - 1} + y_i}{2} = \sum^n_{i=1} f_i \times \frac{y_{i - 1} + y_i}{2} 
$$

## La médiane

La médiane est une valeurs qui sépare l'ensemble des données en deux groupes égaux en terme de nombre.

En gros on trie toutes les valeurs par ordre croissant/décroissant. Et on prendre le nombre qui se situe entre la moitié des valeurs à gauche et l'autres moitié à droite.



**Varaible disctère** 
- Si $n$ impair la varaible est la valeur situé au centre de l'enchantillon.

- Si $n$ est pair alors on peut prendre n'importe quel nombre comrpis entre $x_{n/2}$ et $x_{\frac{n}{2} + 1}$. Mais par convention généraement on prend le millieu de cette intervalle :

$$
\bar x_n = \bar q_{n,1/2} = \frac{x_{n/2} + x_{\frac{1}{2} + 1}}{2}
$$

L'expréssion de la médiane est **bien moins sensibles aux valeurs extrèmes** !! *la classe* 😎

**Variable continue** 
- On prend le nombre de valeurs totale $N$ qu'on divise par deux: $N/2$.
- On prend alors l'intervalle qui comprendre cette valeurs ($N / 2$)

- Après qu'on connait l'intervalle on résoud ce sytème pour trouver la valeurs de l'intervalle qui correspond à la médiane

$$
448 = a \times 60 + b \\
608 = a \times 80 + b
$$

- ou ici 448 est la valeurs de début de la classe médiane et 608 la valeur de fin de médiane.
- Après après avoir résoulu l'équation on as alors : $y = 8x - 30$ avec $x$ qui est la valeurs médiane. et $y$ est le point dans la droite.
- On résoud alors avec $M_e$ la valeurs médiane : $500 = 8 \times M_e - 30$. avec 500 qui est $N / 2$.


**Avantage**

- Le médiane n'est pas affecté par les valeurs abérrente, donc souvent utile pour le prix des maisons, les salaires, ..
- Elle est utile lorsqu'on manque des données

## Les quartiles

C'est les trois valeurs du caractre qui partage la série statistique en quatres groupe du même effectif.

En gros c'est un peu comme la médiane mais pour 4 groupe de : 25%, 25%, 25%, 25%, ce qui donne :

- **1er qaurtile** : les premier 25% des données
- **la médiane** (2ème quartile) : les premier 50% des données
- **3ème quartile** : les premier 75% des données


**Le centile** \
C'est la même chose mais en copant en 100 (voir plus), donc le centile est compris entre $[0, 1]$.

**le quartile d'ordre $p$** \
Est la valeurs du caractère à partir de la quelle la fréquence fcumulée atteint ou dépasse $p$.


## Mode, moyenne, médiane

Les trois critère donne des finformatins différente et on des problèmes différents

- Le mode n'utilise que les valeurs les lus fréquentes de la distribution.

- La médiane n'utilise que la position des observations.

- La moyenne est sensible aux valeurs extrèmes.

## Dispersion

**Exemple** \
Les températures mensuelles miyennes en degré Celsius à New Yor et à Sans Francisico calculé sur 30 ans.

[ Insérer un tableau ]

La températures moyenne pour ces deux viles est de $12.5$ degrés à New-York et à San-Fransico est de $13.7$. 

**On pourais croire que les valeurs son similaire mais non !** on voit bien une différence de température très forte en l'hiver et en été !

Pour le décéler on peut utiliser cette indicateur

$$
e = \frac{1}{n} \sum^n_{i = 1} d(x_i, c)
$$

Ici en fait on test la dispersion autour de la variable $c$ de l'échantillon.

Avec $d(x, y)$ qui est une fonction de "distance" entre $x$ et $y$, cette fonction peut être la **valeur absolue de la différence des deux** ou autres ...


**Définition** \
Le critère de dispersion est une valeur qui représente l'homogénéité des valeurs d'une variables par rappor aux autres.


### Indicateurs de dispersion

#### l'étendue

C'est la différence entre la plus grande et la plus petite valeurs prise par la variable.

- l'étendu $=$ amplitude $=$ $e_n = x_n - x_1$


#### La variance 

La **variance** d'une variable mure s'écrat quadratique moyen de cette varaible à sa moyenne :

$$
Var(X) = E(X^2) - E(X)^2
$$

#### L'écartype

$$s = \sqrt{Var(X)}$$

$s$ est l'écartype de la variable $X$ il s'exprime dans la **même unité que les données**, ce qui rend son interprétation plus facile.

Si on choisi la distéance euclidenne l'indicateur de dispersion est : 

$$
s^2_n = \frac{1}{n} \sum^n_{i = 1} x_i - \bar x^2_n
$$

Avec $\bar x_n$ la moyenne empirique de l'échnatillon.


#### Remarques

- **Dans le cas d'un série regroupée par classe, on utilise le centre des classes $c_i$ pour les $x_i$ de la formule**.
- Une variance est toujours positive !!!
- Ne pas oublié que la variane est la moyenne des écarts au carré.

## Le coefficient de variation

Le **coéfficient de variation (CV)** mesure la dispersion.

- écart-type normasié / standardisé
- écart-type en poiurcetange de la moyenne

$$
CV = \frac{s_n}{\bar x_n} \times 100
$$

Quel intérêt ? 
- Comparer des dispersions entres elles 
- Le CV permet de comparer la dispersion de variables ayant 
  - des unité de mesures différentes
  - des moyennes différentes
- Il faut qu'elle soit le plus faible possible ( $< 15$% en pratique)

## Ecart interquatile

Il sert à apprécier la dispersion de $X$, de façon absolue ou bien par comparaison avec une autre variable quantitative à condition que cette derni_re soit exprimé dans la mêe unité que $X$. En effet les valeurs de $Q_1$ et $Q_3$ délimitent une plage au sein de laquelle 50% des valeurs de $X£ son cencertrés. plus El grand, plus $X$ est dispersée.


## Boxplot ou boite à moustage

Elle met en évidence un ou plusieurs paramètre de tendance centrale et un paramêtre de dispeersion :

- 1er quartile
- 2eme quartile (médiane)
- 3eme quartile
- Les mousches ???
- La moyenne peut être représenter (par exemple par un $+$)
- Les valeurs extrèmes (valeurs atypique/outliers) : cercles ou * ou x.

**C'est une REPRESENTATION GRAPHIQUE**

## Distribution

- Une distribution décrit la propabilité pour une variable de prendre uen valeur donnée

- Une distribution peut être considérée cmme laversoon continue d'un histogramme de fréquence 


Pour une distribution unimodale (un seul mode), nous analyson la moyenne et l'écart-type.


## Skewness 

C'est **la façon dont est orientée la courbe** (plus vers la droite, ou plus vers le centre, plus vers la gauche)


**coefficient de Fisher-Pearson**
$$
Sk_X = \frac{\sum^N_{i = 1} (x_i - \bar{x})^3}{N \times s(X)^3}
$$


coefficient de Fisher-Pearson **ajusté**

$$
ASk_X = \frac{\sqrt{N(N - 1)}}{N - 1} \times 
\frac{\sum^N_{i = 1}(x_i - \bar{x})^4}{N \times s(X)^4}
$$

Avec $s(X)$ est l'écartype empirique de $X$.

## Kurtois

$$
Ku_X = \frac
{\sum^x_{i = 1}}
{}
$$

.... JAI PAS EU LE TEMPSAJEIOAZJ ajek


## Fonction cummulutaive

En théorie de probabolité la fonction de répartioon d'une variable aléatoire $X$ est la fonction $F_X$ qui à toute valeur $x \in \Omega$, associe la propabilité que $X$ prenne une valeurs inférieur ou égale à $X$


$$
F_X(x) = P(X \leq x)
$$

**Propriété** :

- $F_X : \Omega \rightarrow [0, 1]$
- Toujours croissante


## Fonction de densité

La probabilité $P(a \leq X \leq b$ est la zone sous la courbe de l'intervalle $[a, b]$.


$$
P(a \leq X \leq b = \int^b_a f_X(x)dx
$$

- $\forall x \in R, f(x) > 0$
- $f(x)$ intégrable dans $R$

## Loi gaussienne

- 90 des données dans l'intervalle $[ \mu - 1,64 \sigma ; \mu + 1,64 \sigma ]$
- 95% des données se trouvent dans l'intervalle $[\mu - $
- ...


## Mélange Guassien

- Les distributions multimodale peuvent être faites de plusieurs Gaussiennes c'est ce qu'on appelle un mélange gaussien

- Un mélange de deux population gaussienne n'est pas gaussien !

## Test Sharipo-Wilk

Le test de Sharipo-Wilk est un test statistique fréquetsite de normalité : il teste l'hypothèse nulle selon laquelle un échantillon $x_1, \dots, x_n$ provient d'une population normalement distribuée (suivant une loi gaussienne).

....

## Le test de Kolgorov-Smirnov

C'est un test de statistique non paramêtrique.


Il compare a fonction de répartioon empirique de l'échantillon à la fonction de répartition théorique $F$

$$
F_n(x) = \frac{1}{n} \sum^n_{i = 1} 1_{x_i \le x}
$$

En fait c'est le pourcentage de des valeurs de $x_i$ qui esont inférieur à $x$.

Après on prend le "suprémum" (la valeur la plus grande) des différence :

$$
D_n = sup|F(x_i + 1) - F(x_i)|
$$


- Si la p-valeurs est inférieur au seuil chosis nommé $\alpha$ (typiquement 5%) alors l'hypothèse nulle est rejetée et les données testtées ne suivent très probablement pas la loi de référence.

- Si les paramêtre de la loi $\mu$ et $\sigma$ sont étiisé à partir de l'échantillon, le test est alors plus valide.


