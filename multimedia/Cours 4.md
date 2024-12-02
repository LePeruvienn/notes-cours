# Image


## Filtrage

**Convultion** :
- Filtrage linéaire par opérateur de convultion
- Un noya $K$ est déplacer en pixel $I$ de l'image initiale. En chaque pixel on effectue une combinaison linéare entre les pixels et le noyai. $I' = I \times K$  $I'(x,y) = \sum I(x + u, y + v)K(u,v)$  

**Médian et gaussien**
- Gaussien un peu comme un filtre moyen

### Filtre passe haut

**Contours**
Méthode la plus connues : *Filtrages de Sobe* (gradient), et détecteur de Canny
$K_x = 1/4 \begin{bmatrix} 1 & 0 & -1 \\ 2 & 0 & -2 \\ 1 & 0 & -1\end{bmatrix}, K_y = 1/4 \begin{bmatrix} 1 & 2 & 1 \\ 0 & 0 & 0 \\ -1 & -2 & -1 \end{bmatrix}$

Pixel clair => Fort gradient

La convolution veut donner du contraste la ou il y a de fort gradient !


### opencv

- Filtrage générique : `filter2d` (convolution)
- FIltrage aussien : `GaussiaFilter`
- Filtrage médian : `medianFIleter`


## Classificatn et seuillage

### Otsu

Seuillage automatique  :
```python
ret, th = cv.trshold(img, 0, cv.TRESH_BINARY + cv.TRESH_OTSU)
```


## Morphologie mathématique