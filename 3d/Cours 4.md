# Transformation projective

Une application linéaire $f: R^3 -> R^3$ est **inversible** si $f$ est bijective. dans ce cas, $f^{-1}$ est aussi une application liénaire.

**Définition**

Soit $f$ une applicatoon linéaire inversible de $R^3$. On note *$\overline{f}$ l'application $P^2$ -> $P^2$ telle que : 

$$ f(pv()) = ...$$


### Préservation de l'alignement

**Proposition**
Soit $\overline{f}$ l'application projective $P_2$ -> $P_2$ associée à une application linéaire inversible $f : R^3$ -> $R^3$ alors pour tout point $p_1, p_2, p_3 \in P_2$

c sont aligné si et seulement si $f(p_1), f(p_2), f(p_3)$ sont alignées

### Repères projectifs

**Définition** (repère projectif)
- Un repère projectif est un quadruplet ($p_1, p_2, p_3$) de $P^2$ qui sont trois à trois non alignés.

- ça veut dire qu'ils snt une famille libre, donc ils sont une base


**Définition**

- Soit ($p_1, p_2, p_3, p_4$) un repère projectifg de $P^2$ . Une bae adaté à ce repère est une base ($v_1, v_2, v_3$) de $R^3$ telle que :
	$p_1 = p(v_1), p_2 = p(v_2), p_3= p(v_3)$ et $p(v_1 + v_2 + v_3) = p_4$

**Proposition**

- Soit ($p_1, p_2, p_3$) un repère porjectif de $P^2$. Alors il existe ($v_1, v_2, v_3$) base adapté à ce repère.


**Exemple**

On se donne les vecteurss $v_1 = (1,0,0), v_2 = (0,1,0), v_3 = (0,0,1)$ et $v_4 = (1,2,3)$ et $p_i = p(v_i)$ pour $i  = 1,2,3,4$. Comme $v_4 = 1v_1 + 2v_2 +3v_3$, est une base ada^té au repère ($p_1, p_2, p_3, p_4$) 
etst ($v_1, 2v_2, 3v_3$) 

### Changement de repère projectifs

**Théorème**

- Soit ($p_1, p_2, p_3, p_4$) et ($p_1', p_2', p_3', p_4'$) deux repère projectifs. Il existe une transfomration projective $\overline{f}$ telle que $\overline{f}(p_i) = p_i'$ pour tout $i = 1, ..., 4$.  

- On dit qu'une application $g$ : $R^2$ -> $R^2$ , **présever l'alignement** si $g(_p1); g(p_2), g(p_3)$ sont alignés dès que $p_1,p_2 , p_3$ sont alignés.


### Mise en pratique

$P = C' C^{-1}$ est la matrice de changement de base.

### Redressement

On regarde comment redrésser une image qui est au sol

On pose les repère projectif ($p_1, p_2, p_3, p_4$) et ($p_1', p_2', p_3', p_4'$). Avec les $p$ l'image au sol et les $p'$ l'image redrésser. Il faudra alors ensuite appliquer l'appliation linéaire $g()$ avec la matrice de changement de base pour retrouver les $p'$


### Anamorphose



# POUR AVOIR LE POINT BONUS

Faire tout les TPs + feuille moodle !!