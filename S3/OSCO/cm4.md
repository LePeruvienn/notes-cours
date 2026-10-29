
## Exercice

Trouvez le minimum de :

$$
f(x) = x^2 - 2x - 1
$$

La méthode c'est d'abord de trouvé les points stationnaires.

Pour cela il faut résoudre $f'(x) = 0$.

On calcul la dérivée :

$$
f'(x) = 2x - 2
$$

On cherche $f'(x) = 0$ 

$$
2x - 2 = 0 \\
2x = 2 \\
x = 2/2 \\
x = 1
$$

Ici on as un point stationnaire, maintenant on veut savoir si c'est un minimum ou un maximum, pour cela il faut étudier le signe de $f''(x)$.

- Si $f''(x) > 0$ alors c'est un minimum
- Si $f''(x) < 0$ alors c'est un maximum

## Codition necessaire d'optimalité

C'est ce qui donne les codition qui vérifié pour trouvé un minimum local $x^*$ de $f$.

Elle comprend :

- Si $\nabla f(x^*)$ existe, alors $\nabla f(x^*) = 0$
- Si $\nabla^2 f(x^*)$ alors elle est semi défini positive

### Exemple

$$
f(x) = e^{-(x - 3)^2}
$$

On veut d'abord caculer son gradient $\nabla f(x)$ et sa matrice héssienne $\nabla^2 f(x)$.

> NOTE: Ici comme on as qu'une seule variable ($x$) alors c'est juste sa dérivée et sa dérivée seconde.

On cherche la dériviée de $f(x) = e^{-(x - 3)^2}$.

On pose $u = (x - 3)^2$

$$
u' = 2 \times 1 \times (x - 3) = (2x - 6)
$$

Donc f'(x) :

$$
f'(x) = (-2x + 6) \times e^{-(x - 3)^2}
$$

Puis on calcul $f''(x)$ :

$$
f''(x) = (-2 \times e^{-(x - 3)^2}) \times 
(-2x + 6)^2 \times e^{-(x - 3)^2}
$$

> Question : Est ce que $x^x = 2$ est un minimum local ?

Pour cela on va vérifié les deux propriété précédente.

D'abord on vérifie la première condition $\nabla f(x^*) = 0$.

$$
\nabla f(2) = (-4 + 6) \times e^{-(2 - 3) ^2} \ = 2 \times e^{-1}
$$

ça ne vérifie pas la condition ! Donc ce n'est pas un minimum local ❌


> Question : Est ce que $x^x = 3$ est un minimum local ?

D'abord on vérifie la première condition : $\nabla f(x^*) = 0$.

$$
\nabla f(3) = (-6 + 6) \times e^{-(3 - 3) ^2} \ = 0 \times e^{0}
$$

ça vérifie bien la condition ✅

On passe alors à la deuxième condition qui est de savoir si $\nabla^2f(x)$ est bien défini positive.

Comme ici on as pas de matrice mais une fonction à variable unique.

Alors il faut juste vérifié que $f''(x) > 0$ !


(le prof ne l'as pas faite il est passez à autres chose j'ai pas le temps 💀)


### Propriété

Si une fonction $f : R^d \rightarrow R$ est **2 fois différientiable** (*tu peut la dérivée deux fois*) **la sur $R^d$** et **sa matrice héssienne défini positive**, alors :
- $f$ est strictement convexe sur $R^d$ et
- $min_{x \in R^d} f(x)$ adment une unique solution $x^*$ qui vérifie : $\nabla f(x^*) = 0$.

> En gros c'est convexe et il y a qu'un seul minimum.

(J'espère que mes notes vous seront utiles la team 🤙)


