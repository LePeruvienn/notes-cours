
## Rotation

- La trace d'une matrice carrée est la somme de es coéfficient diagonaux


### Exercice 

Soit la la matrice $A = \begin{bmatrix} 1 & -\sqrt{2} & 1 \\ \sqrt{2} & 0 & -\sqrt{2} \\ 1 & \sqrt{2} & 1 \end{bmatrix}$ 

Justifier que A est une rotation. Trouver son axe et son angle non orienté, (c'est à dire entre 0 et 180°) $\theta$ puis donner une base orthonormée de $R^3$ das laquelle $A = R_\theta$   

1) A est une matrice de rotation, si :
	- La matrice est orthogonale, *il faut alors faire* : $A^t \times A = I_3$ 
	-  Et det($A$) = 1
	  
	  => A est alors une matrice de rotation !
	 
	 **Rappel** : det($\lambda$A) = $\lambda^n$ det(A), avec $\lambda \in R$ et A $\in M_A(R)$ 
	 
2) **Trouvons l'ange géométrique**
   
   On sait que $\theta$ vérifie : 1 + 2 cos $\theta$ = trace(A)
   
   Ici trace(A) = 1/2 + 1/2 = 1
    - donc  1 + 2 cos $\theta$ = 1
    - donc cos $\theta$ = 0
    - et $\theta$ = $\pi/2$ (90°)
	 
	 **Trouvons l'axe de la rotation**
	 - L'axe est l'ensembe des points vinvariants (c'est le sous-espace associé à 1)
	   
	 => **On résoud**
	 
	 $A \begin{bmatrix} x \\ y \\ z \end{bmatrix} = \begin{bmatrix} x \\ y \\ z \end{bmatrix}$ 
	 
	 On le met sous forme d'équiation à plusieurs inconnu :
	 
	 $\begin{cases} x - \sqrt{2}y + z = 2x \\ \sqrt{2}x -  \sqrt{2}z = 2y \\ x + \sqrt{2}y + z = 2z \end{cases}$ 
	 
	 On résoud le système ce qui nous donne =>  $\begin{cases} x = z \\ y = 0 \end{cases}$ 
	 
	 Donc l'axe de $E_1$ = $\{(x,y,z) \in R^3,\; x = z,\; y = 0\}$  => Vect $\begin{pmatrix} 1 \\ 0 \\ 1 \end{pmatrix}$ 
	 
	 On a $|| (1, 0, 1) || = \sqrt{2}$ , donc un veteur orthornmé est $\begin{pmatrix} 1/\sqrt{2} \\ 0 \\ 1/\sqrt{2} \end{pmatrix}$ 
	 
	 Trouvons le plan orthogonal à l'axe, c'est :
	 
	 $E^\perp = \{ (x,y,z) \in R^3,\; <\begin{pmatrix} x \\ y \\ z\end{pmatrix},\begin{pmatrix} 1 \\ 0 \\ 1 \end{pmatrix} >= 0\}$
	 $\begin{pmatrix} 1 \\ 0 \\ -1 \end{pmatrix} \in E^\perp_1$
	 
	 $|| (1,0,-1) || = \sqrt{1 + 0 + 1} = \sqrt{2}$ 
	 
	 -> Donc $\begin{pmatrix} \sqrt{2} \\ 0 \\ -\sqrt{2} \end{pmatrix} \in E^\perp_1$ 
	 
	 
	 $\begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \in E^\perp_1$ de norme 1, est orthogonal à  $\begin{pmatrix} \sqrt{2} \\ 0 \\ -\sqrt{2} \end{pmatrix}$, donc 
	 
	 $( \begin{pmatrix} \sqrt{2} \\ 0 \\ \sqrt{2} \end{pmatrix} \begin{pmatrix} 0 \\ 1 \\ 0 \end{pmatrix} \begin{pmatrix} \sqrt{2} \\ 0 \\ -\sqrt{2} \end{pmatrix} )$ est une base orthonormale
	 
	 
	 
	 Posons $P$ la matrice de passage, comme $P$ est orthogonale, $P^{-1}$ = $P^t$ 
	 
	 $E_1$ faisant le calcul, on a $P^{-1}AP$  



### Rotation affines 

**Exercice**

*On cosidère l'application suivant de $R^2$* :

$\begin{pmatrix} x \\ y \end{pmatrix}$ -> $\begin{pmatrix} 3/5x - 4/5y + 1 \\ 4/5x + 3/5y - 1 \end{pmatrix}$ 


1) Jutifier qu'il s'agit d'une transformation affine
2) Reconnaitre la transofmration dont il s'agit, donner sa partie linéaire
3) Trouver son centre


**1)**

$f(x,y) = \begin{bmatrix} 3/5x - 4/5y + 1 \\ 4/5x + 3/5y - 1 \end{bmatrix} \begin{bmatrix} x \\ y \end{bmatrix} + \begin{bmatrix} 1 \\ -1 \end{bmatrix}$ 

Ainsi $f$ est la composé de $g$, application linéaire associée à $\begin{bmatrix} 3/5 - 4/5 \\ 4/5 + 3/5 \end{bmatrix}$ et de la translation de vecteurs $\begin{bmatrix} 1 \\ -1 \end{bmatrix}$ aors $f$ est une translation affine


**2)**

Posons $A = \begin{bmatrix} 3/5 - 4/5 \\ 4/5 + 3/5 \end{bmatrix}$ 

- Det $A = (3/5)^2 + (4/5)^2$ = 1
- $A^t A = I_2$  

Alors A est une matricede rotation


**3)**

Le centr eest données par :

$f\begin{pmatrix} x \\ y \end{pmatrix} = \begin{pmatrix} x \\ y \end{pmatrix}$ 

*On a alors le système*

$\begin{cases}  3/5x - 4/5y + 1 = x \\ 4/5x + 3/5y - 1 = y \end{cases}$ 

*On résoud le système ...*

$\begin{cases}  x = 3/2 \\ y = 1/2 \end{cases}$ 

=> Le centre est $(3/2, 1/2)$ 